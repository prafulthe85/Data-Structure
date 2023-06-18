#include <iostream>
#include "Stack_vector.h"
using namespace std;

int main(){

    Stack <char> s;

    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}