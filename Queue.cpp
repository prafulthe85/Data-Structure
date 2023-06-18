#include <iostream>
#include "Queue.h"
using namespace std;

int main(){

    Queue myqueue(7);

    myqueue.push(1);  // 1, rear at 1, front at 
    myqueue.push(2);  // 1 2
    myqueue.push(3);  // 1 2 3 
    myqueue.push(4);  // 1 2 3 4  
    myqueue.push(5);  // 1 2 3 4 5
    myqueue.push(6);  // 1 2 3 4 5 6
    myqueue.push(7);  // 1 2 3 4 5 6 7, rear at 7
    myqueue.push(8);  // 1 2 3 4 5 6 7 , size is full so 8 is not inserted
    myqueue.pop();    // _ 2 3 4 5 6 7 ,front at 1,rear at 7
    myqueue.pop();    // _ _ 3 4 5 6 7 , front at 2, rear at 7
    myqueue.push(9);  // 9 _ 3 4 5 6 7 , front at 2, rear at 1

    while (!myqueue.empty())
    {
        cout<<myqueue.getfront()<<" ";
        myqueue.pop();

    }


// Queueu STL

// Queue <int> myqueue;

// // Stl has same as our queue class

//     myqueue.push(1);
//     myqueue.push(2);
//     myqueue.push(4);
//     myqueue.push(3);
//     myqueue.push(5);
//     myqueue.push(6);
    
//     while (!myqueue.empty())
//     {
//         cout<<myqueue.getfront()<<" ";
//         myqueue.pop();

//     }

    return 0;
}