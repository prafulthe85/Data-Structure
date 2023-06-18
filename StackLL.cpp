#include <iostream>
#include "StackLL.h"
using namespace std;

int main(){

    Stack<int> s;

    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.pop();

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}