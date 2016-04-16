//
// Created by root on 2016-04-14.
//

#ifndef INLAMNING1_QUEUE_H
#define INLAMNING1_QUEUE_H

#include "IQueue.h"
template <class T>
class Queue : public IQueue
{
private:
    T* ptr;
    int nrOfElements=0;
    int capacity=0;
public:
    Queue();
    ~Queue();
    Queue(const Queue<T>& orgin);
    Queue<T>& operator=(const Queue<T>& orgin);
    //inherited
    virtual ~IQueue() {};
    virtual void enqueue(const T& item);
    virtual T dequeue();
    virtual T& front() const;
    virtual bool isEmpty() const;

};
template <class T>
IQueue<T>::~IQueue()
{}
template <class T>
Queue<T>::Queue()
{
    this->nrOfElements=0;
    this->ptr = new T[2];
    this->capacity=2;
}
template <class T>
Queue<T>::~Queue()
{
    IQueue<T>::~IQueue();
    delete[]  this->ptr;
}
template <class T>
Queue<T>::Queue(const Queue<T> &orgin)
{
    this->nrOfElements = orgin.nrOfElements;
    this->capacity=orgin.capacity;
    this->ptr=new T[this->capacity];
    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        this->ptr[i] = orgin.ptr[i];
    }
}
template <class T>
Queue<T> &Queue::operator=(const Queue<T> &orgin)
{
    if(this != &orgin)
    {
        this->nrOfElements = orgin.nrOfElements;
        this->capacity = orgin.capacity;
        delete[] this->ptr;
        this->ptr = new T[this->capacity];
        for (int i = 0; i < this->nrOfElements; ++i) {
            this->ptr[i] = orgin.ptr[i];
        }
    }
    return *this;
}
//inherited
template <class T>
void Queue<T>::enqueue(const T &item)
{
    if(this->nrOfElements > this->capacity)
    {
        //expansion
        T* tmp= new T[this->capacity];
        for (int i = 0; i < this->capacity ; ++i)
        {
            tmp[i] = this->ptr[i];
        }
        delete[] this->ptr;
        this->ptr = new T[this->capacity+3];
        this->capacity+=3;
        for (int i = 0; i < this->capacity ; ++i)
        {
            this->ptr[i]=tmp[i];
        }
        delete[] tmp;
    }
    else
    {
        this->ptr= new T[this->capacity+3];
        this->capacity+=3;
    }
    this->ptr[this->nrOfElements]= item;
    this->nrOfElements++;
}
template <class T>
T Queue<T>::dequeue()
{
    return nullptr;
}
template <class T>
T &Queue<T>::front() const
{
    return this->ptr[this->nrOfElements-1];
}
template <class T>
bool Queue<T>::isEmpty() const
{
    if(this->capacity == 0)
    {
        return true;
    }
    return false;
}
#endif //INLAMNING1_QUEUE_H
