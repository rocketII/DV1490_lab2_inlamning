//
// Created by root on 2016-04-14.
//

#ifndef QUEUE_H
#define QUEUE_H
#include "IQueue.h"

template <class T>
class Queue : public IQueue<T>
{
private:
    T* ptr= nullptr;
    int frontptr, backptr;
    int nrOfElements=0;
    int capacity=0;
public:
    Queue();
    virtual ~Queue();
    Queue(const Queue<T>& orgin);
    Queue<T>& operator=(const Queue<T>& orgin);
    //inherited
    virtual void enqueue(const T& item);
    virtual T dequeue();
    virtual T& front() const;
    virtual bool isEmpty() const;

};

template <class T>
Queue<T>::Queue()
{
    this->nrOfElements=0;
    this->backptr=0;
    this->frontptr=1;
    this->ptr = new T[2];
    this->capacity=2;
}
template <class T>
Queue<T>::~Queue()
{
    delete[]  this->ptr;
}
template <class T>
Queue<T>::Queue(const Queue<T> &orgin)
{
    this->nrOfElements = orgin.nrOfElements;
    this->capacity=orgin.capacity;
    this->backptr = orgin.backptr;
    this->frontptr = orgin.frontptr;
    this->ptr=new T[this->capacity];
    for (int i = 0; i < this->capacity ; ++i)
    {
        this->ptr[i] = orgin.ptr[i];
    }
}
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T> &orgin)
{
    if(this != &orgin)
    {

        this->nrOfElements = orgin.nrOfElements;
        this->backptr = orgin.backptr;
        this->frontptr = orgin.frontptr;
        this->capacity = orgin.capacity;
        delete[] this->ptr;
        this->ptr = new T[this->capacity];
        for (int i = 0; i < this->capacity; ++i)
        {
            this->ptr[i] = orgin.ptr[i];
        }
    }
    return *this;
}
//inherited
template <class T>
void Queue<T>::enqueue(const T &item)
{
    this->nrOfElements++;
    if(this->nrOfElements < this->capacity)
    {
        ;
    }
    else
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
    this->backptr = (this->backptr + 1) % this->capacity;
    this->ptr[this->backptr]= item;
}
template <class T>
T Queue<T>::dequeue()
{
    if(!this->isEmpty())
    {
        T data = this->ptr[this->frontptr];
        this->frontptr= (this->frontptr +1) % this->capacity;
        this->nrOfElements--;
        return data;
    }
    else
        throw " I'm empty ;P";
}
template <class T>
T &Queue<T>::front() const
{
    if(this->nrOfElements == 0)
    {
        throw "...";
    }
    else
        return this->ptr[this->frontptr];
}
template <class T>
bool Queue<T>::isEmpty() const
{
    if(this->nrOfElements == 0)
    {
        return true;
    }
    return false;
}
#endif //INLAMNING1_QUEUE_H
