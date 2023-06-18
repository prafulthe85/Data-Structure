#include <iostream>
using namespace std;

class List;

class Node{
    int data;
public:
    Node * next;

    Node(int d):data(d),next(nullptr){}
    
// getdata is used to get the private member data 
    int getdata(){
        return data;
    }

    ~Node(){
        if(next!=nullptr){
            delete next;
        }
        cout<<"Deleting node with data "<<data<<endl;
    }

// friend class is used so that private members of Node can be accessed by List
    friend class List;

};

class List{
    Node * head;
    Node * tail;


    int rechelp(Node * start, int key){
        //Base Case
        if(start==nullptr){
            return -1;
        }
        // Value matches
        if(start->data==key){
            return 0;
        }

        // Recursive call

        int subhelp = rechelp(start->next,key);
        if(subhelp==-1){
                return -1;
        }
// Here it add +1 while returning as when the value matches it returns 0 which decrease the index so incremented here
        return subhelp+1;
    }
public:

    List():head(nullptr),tail(nullptr){}

    Node * begin(){
        return head;
    }
    void push_front(int data){
        if(head==nullptr){
            Node * n = new Node(data);
            head = tail = n;
        }
        else {
            Node * n = new Node(data);
            n->next = head;
            head = n;
        }
    }

    void push_back(int data){
        if(head==nullptr){
            Node *n = new Node(data);
            head = tail = n;
        }
        else {
            Node * n = new Node (data);
            tail->next = n;
            tail=n;
        }
    }

    void insert(int data,int pos){
        if(pos==0){
            push_front(data);
            return ;
        }

        else {
            Node *temp = head;
            for(int jump=1;jump<=pos-1;jump++){
                temp=temp->next;
            }
            Node *n = new Node(data);
            n->next=temp->next;
            temp->next=n;
        }
    }
    

    void pop_back(){
        
        Node *temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        
        temp->next=nullptr;

        delete tail;
        tail = temp;
    }

    void pop_front(){
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    
    void pop_between(int pos){
        if(pos==0){
            pop_front();
            return ;
        }

        Node * temp= head;

        
        for(int jump=1; (jump<=pos-1) and (temp!=nullptr); jump++){
            temp = temp->next; 
        }
        if(temp == nullptr){
            cout << "Pos out of bounds\n";
            return;
        }
        Node *to_remove = temp->next;
        
        if(to_remove->next == NULL){
            pop_back();
            return;
        }

        temp->next = to_remove->next;
        to_remove->next = NULL;
        delete to_remove;
    }

    int search(int key){
        Node *temp = head;
        int idx=0;
        while(temp!= nullptr){
            if(temp->data==key){
                return idx;
            }

            idx++;
            temp= temp->next;
        }
        return -1;
    }

    int recursivesearch(int key){
        int idx = rechelp(head,key);
        return idx;
    }
    ~List(){
        if(head!=nullptr){
            delete head;
            head=nullptr;
        }
    }

    void reverse_node(){
        Node * pre=nullptr;
        Node * current=head;
        Node * temp;

        while(current!=nullptr){
            temp=current->next;
            current->next=pre;
            pre=current;
            current=temp;
        }
        head=pre;
    }

    int kth_last_element(int k){
        Node* current =head;
        int idx=0;

        while(current->next!=nullptr){
                idx++;
                current=current->next;
        }
        int i=0;

        current=head;
        while(i!=(idx-k+1)){
            i++;
            current=current->next;
        }
        return current->getdata();

    }

};