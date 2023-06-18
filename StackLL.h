template <typename T>
class Stack;

template <typename T>
class Node{

public:
    T data;;
    Node<T> *next;

    Node(T d){
        data=d;
    }
};

template<typename T>
class Stack{
    Node<T> * head;
public:

    Stack(){
        head=nullptr;
    }

    void push(T data){
        Node<T> *n=new Node<T>(data);
        n->next=head;
        head=n;
    }

    bool empty(){
        return head==nullptr;
    }

    T top(){
        return head->data;
    }

    void pop(){
        if(head!=nullptr){
            Node<T>* temp= head;
            head=head->next;
            delete temp;
        }
    }
};