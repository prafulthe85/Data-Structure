
class Queue{

    int *arr;
    int ms;
    int cs;
    int rear;
    int front;

public:

    Queue(int default_size=5){
        ms=default_size;
        arr = new int[ms];
        cs=0;
        rear = ms-1;
        front = 0;
    }

    bool full(){
        return cs==ms;
    }

    bool empty(){
        return cs==0;
    }

    void push(int data){
        if(!full()){
// this expression is used so that if rear go beyond it's limit then it come back to intial value , here if rear is greater than 6 than it come back to 0
            rear = (rear+1)%ms;
            arr[rear] = data;
            cs++;
        }
    }

    void pop(){
        if(!empty()){
            front = (front+1)%ms;
            cs--;
        }
    }

    int getfront(){
        return arr[front];
    }

};