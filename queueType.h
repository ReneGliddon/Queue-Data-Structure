//D.S MALIK textbook code. Copy constructor, copyQueue and
//overloaded assignment operator implemented by K.M Mphakalasi.

#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include <cassert>
#include <iostream>
#include "queueADT.h"
#include <stack>

using namespace std;

template <class Type>
class queueType: public queueADT<Type>
{
	public:
		const queueType<Type>& operator=(const queueType<Type>&);
		bool isEmptyQueue() const;
		bool isFullQueue() const;
		void initializeQueue();
		Type front() const;
		Type back() const;
		void addQueue(const Type& queueElement);
		void deleteQueue();
		queueType(int queueSize = 100);
		queueType(const queueType<Type>& otherQueue);
		~queueType();
		 void reverseQ(queueType< Type >&q);
        //practice exam question
        bool identicalQ(queueType<Type> Q1, queueType<Type> Q2);



		int maxQueueSize;
		int count;
		int queueFront;
		int queueRear;
		Type *list;
		void copyQueue(const queueType<Type>& otherQueue);
};


template <class Type>
bool queueType<Type>::identicalQ (queueType<Type> Q1, queueType<Type> Q2)
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
    return isIdentical;

}




template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
	return (count == 0);
}


template <class Type>
bool queueType<Type>::isFullQueue() const
{
	return (count == maxQueueSize);
}

template <class Type>
void queueType<Type>::initializeQueue()
{
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
}

template <class Type>
Type queueType<Type>::front() const
{
	assert(!isEmptyQueue());
	return list[queueFront];
}

template <class Type>
Type queueType<Type>::back() const
{
	assert(!isEmptyQueue());
	return list[queueRear];
}

template <class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
	if (!isFullQueue()) {
		queueRear = (queueRear + 1) % maxQueueSize;
		count++;
		list[queueRear] = newElement;
	} else
		cout << "Cannot add to a full queue." << endl;
}

template <class Type>
void queueType<Type>::deleteQueue()
{
	if (!isEmptyQueue()) {
		count--;
		queueFront = (queueFront + 1) % maxQueueSize;
	} else
		cout << "Cannot remove from an empty queue." << endl;
}

template <class Type>
queueType<Type>::queueType(int queueSize)
{
	if (queueSize <= 0) {
		cout << "Size of the array to hold the queue must be positive" << endl;
		cout << "Creating an array of size 100." << endl;
		maxQueueSize = 100;
	} else {
		maxQueueSize = queueSize;
		//cout << "Default of 100 initialised." << endl;
	}

	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
	list = new Type[maxQueueSize];
}

template <class Type>
queueType<Type>::~queueType()
{
	delete [] list;
}

template <class Type>
void queueType<Type>::copyQueue(const queueType<Type>& otherQueue)
{
	delete [] list;
	maxQueueSize = otherQueue.maxQueueSize;
	queueFront = otherQueue.queueFront;
	queueRear = otherQueue.queueRear;
	count = otherQueue.count;
	list = new Type[maxQueueSize];

	for (int j = 0; j < maxQueueSize; j++)
		list[j] = otherQueue.list[j];
}

template <class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue)
{
	list = NULL;
	copyQueue(otherQueue);
}

template <class Type>
const queueType<Type>& queueType<Type>::operator=(const queueType<Type>& otherQueue)
{
	if (this != &otherQueue) {
		copyQueue(otherQueue);
	}

	return *this;
}

#endif
