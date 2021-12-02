#ifndef LINKEDQUEUETYPE_H
#define LINKEDQUEUETYPE_H
#include "queueType.h"
#include <iostream>
using namespace std;
#include <cassert>

//Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class linkedQueueType: public queueType<Type>
{
    public:
        const linkedQueueType<Type>& operator=(const linkedQueueType<Type>&);
        //Overload the assignment operator.
        bool isEmptyQueue() const;
        //Function to determine whether the queue is empty.
        //Postcondition: Returns true if the queue is empty, otherwise returns false.
        bool isFullQueue() const;
        //Function to determine whether the queue is full.
        //Postcondition: Returns true if the queue is full,
        // otherwise returns false.
        void initializeQueue();
        //Function to initialize the queue to an empty state.
        //Postcondition: queueFront = NULL; queueRear = NULL
        Type front() const;
        //Function to return the first element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: If the queue is empty, the program
        // terminates; otherwise, the first element of the
        // queue is returned.
        Type back() const;
        //Function to return the last element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: If the queue is empty, the program
        // terminates; otherwise, the last element of the
        // queue is returned.
        void addQueue(const Type& queueElement);
        //Function to add queueElement to the queue.
        //Precondition: The queue exists and is not full.
        //Postcondition: The queue is changed and queueElement is
        // added to the queue.
        void deleteQueue();
        //Function to remove the first element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: The queue is changed and the first element
        // is removed from the queue.
        linkedQueueType();
        //Default constructor
        linkedQueueType(const linkedQueueType<Type>& otherQueue);
        //Copy constructor
        ~linkedQueueType();
        //Destructor
         void replaceEverySecondItem(const Type & newItem);
        //practice exam question

        nodeType<Type> *queueFront; //pointer to the front of the queue
        nodeType<Type> *queueRear; //pointer to the rear of the queue
};

template <class Type>
void linkedQueueType<Type>::replaceEverySecondItem(const Type & newItem)
{

    nodeType<Type> *stop;
    stop = new nodeType<Type>; //a node to flag the end of the queue

    //process(pass by) the first node
    //create the  new node
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    //new node will take the front of the queue
    newNode->info=queueFront->info;

    //we will move the new node to the back of the queue
    queueRear->link = newNode;
    queueRear = newNode;
    //set the flag to the first node that was "moved"
    stop = newNode;
    //delete the first node
    deleteQueue();

    //iterate through the queue, replacing every second info with the newItem,
    //stopping when we get to the flagged node "stop"

    while(queueFront!=stop)
    {
        //the replacement node
        nodeType<Type> *secondNewNode;
        secondNewNode = new nodeType<Type>;
        //info will be the new item
        secondNewNode->info=newItem;

        //place the replacement info at the back
        queueRear->link = secondNewNode;
        queueRear = secondNewNode;
        //delete the original node
        deleteQueue();

        //move the next node to the back
        nodeType<Type> *newNode;
        newNode = new nodeType<Type>;
        //pass the info from the front to the new node
        newNode->info=queueFront->info;
        //move the node to the back
        queueRear->link = newNode;
        //new node is now the rear
        queueRear = newNode;
        //delete the original front of the queue
        deleteQueue();

   }


}

template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
    nodeType<Type> *temp;
    while (queueFront!= NULL) //while there are elements left in the queue
    {
        temp = queueFront; //set temp to point to the current node
        queueFront = queueFront->link; //advance first to the next node
        delete temp; //deallocate memory occupied by temp
    }
    queueRear = NULL; //set rear to NULL
} //end initializeQueue

template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>; //create the node
    newNode->info = newElement; //store the info
    newNode->link = NULL; //initialize the link field to NULL
    if (queueFront == NULL) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else //add newNode at the end
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}//end addQueue

template <class Type>
Type linkedQueueType<Type>::front() const
{
    assert(queueFront != NULL);
    return queueFront->info;
} //end front

template <class Type>
Type linkedQueueType<Type>::back() const
{
    assert(queueRear!= NULL);
    return queueRear->info;
} //end back

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    nodeType<Type> *temp;
    if (!isEmptyQueue())
    {
        temp = queueFront; //make temp point to the first node
        queueFront = queueFront->link; //advance queueFront
        delete temp; //delete the first node
        if (queueFront==NULL) //if after deletion the queue is empty
        queueRear = NULL; //set queueRear to NULL
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue

template<class Type>
linkedQueueType<Type>::linkedQueueType()
{
    queueFront = NULL; //set front to null
    queueRear = NULL; //set rear to null
} //end default constructor


template<class Type>
linkedQueueType<Type>::~linkedQueueType()
{
    deleteQueue();
}

template <class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return(queueFront == NULL);
} //end

template <class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
} //end isFullQueue

#endif // LINKEDQUEUETYPE_H
