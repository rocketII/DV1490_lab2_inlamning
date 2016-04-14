#ifndef IQUEUE_H
#define IQUEUE_H

template <typename T>
class IQueue
{
public:
	virtual ~IQueue() {};
	virtual void enqueue(const T& item) = 0;
	virtual T dequeue() = 0;
	virtual T& front() const = 0;
	virtual bool isEmpty() const = 0;
};

#endif