#include <iostream>
#include <stack>
#include <string>
using namespace std;

void insert_at_bottom(stack <string>& s, string data){
    // base case
    if(s.empty()){
        s.push(data);
        return;
    }

    // rec case

    string temp=s.top();
    s.pop();
    insert_at_bottom(s,data);
    s.push(temp);
}


void reverse_stack(stack <string> &s){
    // base case 
    if(s.empty()){
        return;
    }

    // rec case

    string t = s.top();
    s.pop();
    reverse_stack(s);
    insert_at_bottom(s,t);
}

int main(){

    stack<string> s;

    s.push("Java");
    s.push("C++");
    s.push("python");
    s.push("Javascript");

    // this function puts the element at the start of the stack 
    // it works against the operations of stack
    insert_at_bottom(s,"Ruby");

    // this function reverse the stack so first element print at first 
    // opposing the nature of stack i.e, First In Last Out(FIFO)
    reverse_stack(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}