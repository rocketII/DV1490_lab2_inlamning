//
// Created by root on 2016-04-18.
//
#include "Queue.h"
#include <iostream>

using namespace std;

int main()
{
    Queue<int> aQueue;
    Queue<int> bQueue = aQueue;

    aQueue.enqueue(10);
    aQueue.enqueue(30);
    aQueue.enqueue(2);

    cout<<endl;



    return 0;
}
