//
// Created by root on 2016-04-18.
//
#include "Queue.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    Queue<int> aQueue;


    aQueue.enqueue(1);
    aQueue.enqueue(2);
    aQueue.enqueue(3);
    aQueue.enqueue(4);
    aQueue.enqueue(11);
    cout<<aQueue.front()<<endl;
    aQueue.dequeue();
    cout<<aQueue.front()<<endl;
    aQueue.enqueue(22);
    aQueue.enqueue(66);
    cout<<aQueue.front()<<endl;
    aQueue.dequeue();
    cout<<aQueue.front()<<endl;
    aQueue.enqueue(77);
    aQueue.enqueue(88);
    aQueue.enqueue(99);

    cout<<endl;



    return 0;
}
