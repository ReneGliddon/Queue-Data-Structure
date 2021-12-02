#include <iostream>
#include "linkedQueueType.h"
#include "queueType.h"
using namespace std;

template<class Object>
void fix(queueType<Object> &q, int n)
{
    if(n>=1)
    {
        Object temp = q.front();
        q.deleteQueue();
        fix(q,n-1);
        q.addQueue(temp);
    }


}
template <class Type>
void oddQ (linkedQueueType<Type> &q)
{
    //a counter to keep track of the size of our queue
    int counter =0;

    //a node to flag the end of the queue
    nodeType<Type> *stop;
    stop = new nodeType<Type>;

    //create the  new node
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;

    //new node will take the front of the queue
    newNode->info = q.queueFront->info;

    //we will move the new node to the back of the queue
    q.queueRear->link = newNode;
    q.queueRear = newNode;
    //set the flag to the first node that was "moved"
    stop = newNode;
    //increase the size of our counter
    counter++;
    //delete the first node
    q.deleteQueue();

    //iterate through the queue, deleting every second node,
    //stopping when we get to the flagged node "stop"
    //increase the size of our counter each time we add a node to the back of the queue

    while(q.queueFront!=stop)
    {
        //delete the next node
        q.deleteQueue();

        //create a new node to move the next node to the back
        nodeType<Type> *newNode;
        newNode = new nodeType<Type>;
        //pass the info from the front to the new node
        newNode->info=q.queueFront->info;
        //move the node to the back
        q.queueRear->link = newNode;
        //increase the counter
        counter++;
        //new node is now the rear
        q.queueRear = newNode;
        //delete the original front of the queue
        q.deleteQueue();

   }

    cout<<endl<<"Let's check queue 2."<<endl;

	for(int i = 0; i<counter; i++)
    {
		cout << q.front() << " ";
		q.deleteQueue();
	}

}

template <class Type>
void replaceEverySecondItem(linkedQueueType<Type>&q, const Type & newItem)
{

    nodeType<Type> *stop;
    stop = new nodeType<Type>; //a node to flag the end of the queue

    //process(pass by) the first node
    //create the  new node
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    //new node will take the front of the queue
    newNode->info = q.queueFront->info;

    //we will move the new node to the back of the queue
    q.queueRear->link = newNode;
    q.queueRear = newNode;
    //set the flag to the first node that was "moved"
    stop = newNode;
    //delete the first node
    q.deleteQueue();

    //iterate through the queue, replacing every second info with the newItem,
    //stopping when we get to the flagged node "stop"

    while(q.queueFront!=stop)
    {
        //the replacement node
        nodeType<Type> *secondNewNode;
        secondNewNode = new nodeType<Type>;
        //info will be the new item
        secondNewNode->info=newItem;

        //place the replacement info at the back
        q.queueRear->link = secondNewNode;
        q.queueRear = secondNewNode;
        //delete the original node
        q.deleteQueue();

        //move the next node to the back
        nodeType<Type> *newNode;
        newNode = new nodeType<Type>;
        //pass the info from the front to the new node
        newNode->info=q.queueFront->info;
        //move the node to the back
        q.queueRear->link = newNode;
        //new node is now the rear
        q.queueRear = newNode;
        //delete the original front of the queue
        q.deleteQueue();

   }


}

template <class Type>
bool identicalQ (queueType<Type> Q1, queueType<Type> Q2)
{
    bool isIdentical;

      while(!Q1.isEmptyQueue()&&!Q2.isEmptyQueue())
    {
        if(Q1.front()==Q2.front())
        {
            isIdentical=true;
            Q1.deleteQueue();
            Q2.deleteQueue();
        }
        else if(Q1.front()!=Q2.front())
        {
            isIdentical=false;
            return isIdentical;
        }
    }
    if(Q1.isEmptyQueue()&&Q2.isEmptyQueue())

        isIdentical=true;
    else
        isIdentical =false;
    return isIdentical;

}
template<class Type>
queueType<Type> removeX(queueType<Type> Q, const Type &x)
{
    queueType<Type> copyQueue;

    while(!Q.isEmptyQueue())
    {
         if(Q.front()==x)
        {
            Q.deleteQueue();

        }
        //if it isn't x, then we copy it into our copyQueue before removing it
        else
        {
            copyQueue.addQueue(Q.front());
            Q.deleteQueue();
        }
    }

    //copy back the new queue into Q
    while(!copyQueue.isEmptyQueue())
    {
        Q.addQueue(copyQueue.front());
        copyQueue.deleteQueue();
    }

    return Q;

}

template<class Type>
void reverseQ(queueType< Type >&q)
{
    int stackTop;
    stack<Type> localStack;
    int stackCount=0;

    //q.initializeQueue();
    while(!q.isEmptyQueue())
    {
        Type newItem = q.front();
        localStack.push(newItem);
        stackCount++;
        //count--;
        q.deleteQueue();
    }

    for(int i=0; i < stackCount+1; i++)
    {
        Type newElement = localStack.top();
        localStack.pop();
        q.addQueue(newElement);
        stackCount--;
    }

    cout<<endl<<"Our new reversed queue is: ";
     while(!q.isEmptyQueue())
    {
        cout<<q.front()<<" ";
        q.deleteQueue();
    }
}

int main()
{
	queueType<int> queue(5);
	int x, y;

	queue.initializeQueue();
	x = 4;
	y = 5;
	queue.addQueue(x);
	queue.addQueue(y);
	x = queue.front();
	queue.deleteQueue();
	queue.addQueue(x + 5);
	queue.addQueue(16);
	queue.addQueue(x);
	//queue.addQueue(y - 3);
	queueType<int> queue2, queue3(queue);
	queue2 = queue;

	cout << "Queue Elements: " << endl;

	while (!queue.isEmptyQueue()) {
		cout << queue.front() << " ";
		queue.deleteQueue();
	}

	cout << endl;

	cout << "Queue2 Elements: " << endl;

	while (!queue2.isEmptyQueue()) {
		cout << queue2.front() << " ";
		queue2.deleteQueue();
	}

	cout << endl;

	cout << "Queue3 Elements: " << endl;

	while (!queue3.isEmptyQueue()) {
		cout << queue3.front() << " ";
		queue3.deleteQueue();
	}

	cout << endl;

	cout<<endl<<endl<<"Ok a new queue."<<endl;
	queueType<int> newQueue(7);
	newQueue.initializeQueue();

	newQueue.addQueue(1);
	newQueue.addQueue(2);
	newQueue.addQueue(3);
	newQueue.addQueue(2);
	newQueue.addQueue(2);
	newQueue.addQueue(4);
	newQueue.addQueue(4);

	queueType<int> returnedQueue;
	returnedQueue.initializeQueue();

	cout<<endl<<"We are going to remove 2";
	returnedQueue = removeX(newQueue, 2);
	cout<<endl<<"Our new queue: "<<endl;
	while (!returnedQueue.isEmptyQueue()) {
		cout << returnedQueue.front() << " ";
		returnedQueue.deleteQueue();
	}

	cout<<endl<<"Ok another new queue."<<endl;
	queueType<int> anotherQueue = queue;
	anotherQueue.initializeQueue();

	anotherQueue.addQueue(1);
	anotherQueue.addQueue(2);


	cout<<"Ok lets try reverse the new queue:";
	reverseQ(anotherQueue);

	cout<<endl;

	while (!newQueue.isEmptyQueue()) {
		cout << newQueue.front() << " ";
		newQueue.deleteQueue();
	}


    linkedQueueType<int> queue1;

    queue1.addQueue(1);
    queue1.addQueue(3);
    queue1.addQueue(4);
    queue1.addQueue(6);
    queue1.addQueue(7);
    queue1.addQueue(8);
    queue1.addQueue(2);

    linkedQueueType<int> queueSecond;

    queueSecond.addQueue(1);
    queueSecond.addQueue(3);
    queueSecond.addQueue(4);
    queueSecond.addQueue(6);
    queueSecond.addQueue(7);
    queueSecond.addQueue(8);
    queueSecond.addQueue(2);

    cout<<endl<<endl<<"Now we will try replacing every second item with a '0'";
    cout<<endl<<"we will start with queue1, which is simply 1,3,4,6,7,8,2.";

   replaceEverySecondItem(queue1, 0);

   cout<<endl<<"Let's see the replaced queue."<<endl;


   for(int stop = 0; stop<7; stop++) {
		cout << queue1.front() << " ";
		queue1.deleteQueue();
	}

	cout<<endl<<endl;

	cout<<endl<<"Now we will remove every second item from queue 2, which is currently 1, 3, 4, 6, 7, 8 , 2.";
	oddQ(queueSecond);

	cout<<endl<<"all checked";

	cout<<endl<<"we are going to try the fix function next.";
	queueType<int> fixedQ;
	fixedQ.addQueue(1);
	fixedQ.addQueue(2);
	fixedQ.addQueue(3);
	fixedQ.addQueue(4);
	fixedQ.addQueue(5);

	fix(fixedQ, 2);
	cout<<endl;

	while (!fixedQ.isEmptyQueue()) {
		cout << fixedQ.front() << " ";
		fixedQ.deleteQueue();
	}

    cout<<endl<<"Ok now we check for identical queues."<<endl;
	queueType<int> ashleyQueue = queue;
	ashleyQueue.initializeQueue();

	ashleyQueue.addQueue(1);
	ashleyQueue.addQueue(2);
	ashleyQueue.addQueue(2);

	queueType<int> marykateQueue=queue;
	marykateQueue.initializeQueue();

	marykateQueue.addQueue(1);
	marykateQueue.addQueue(2);
	marykateQueue.addQueue(2);

	if(identicalQ(ashleyQueue, marykateQueue))
        cout<<endl<<"the queues are identical.";
    else
        cout<<endl<<"the queues are not identical.";



	return 0;
}
