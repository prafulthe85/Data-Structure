#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1,q2;
public:

    void push(int data){
        if(!q1.empty()){
            q1.push(data);
        }
        else {
            q2.push(data);
        }
    }

    void pop(){
        if(q1.empty()){
            // elements transfered from q2 to q1
            while(!q2.empty()){
                int front = q2.front();
                q2.pop();

                if(q2.empty()){
                    break;
                }

                q1.push(front);
            }
        }

        else{
            // elements transfered from q1 to q2
             while(!q1.empty()){
                 int front = q1.front();
                 q1.pop();

                 if(q1.empty()){
                     break;
                 }
                 q2.push(front);
             }
        }
    }

    int top(){
        while(!q2.empty()){
                int front = q2.front();
                q2.pop();

                q1.push(front);
                if(q2.empty()){
                    return front;
                }

            }
        while(!q1.empty()){
                int front = q1.front();
                q1.pop();

                q2.push(front);
                if(q1.empty()){
                    return front;
                }

            }
    }
    bool empty(){
        return q1.empty() and q2.empty();
    }
};

int main(){

    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.push(5);

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    

    return 0;
}