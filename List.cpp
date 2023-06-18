#include <iostream>
#include "List.h"
using namespace std;

int main(){

    List l;
    l.push_front(3);
    l.push_back(7);
    l.push_back(19);
    l.push_back(13);
    l.insert(4,3);
    // l.pop_back();
    //  l.pop_front();
    //l.pop_between(2);
// using begin gives u the head head of the list
    // l.reverse_node();

//  This gives the kth last element
    cout<<l.kth_last_element(2)<<endl;

    Node* head= l.begin();
    while (head!=nullptr)
    {
        cout<<head->getdata()<<"->";
        head = head->next;
    }

    cout<<endl;

    // int key;
    // cout<<"Enter key for rec search : ";
    // cin>>key;
    // cout<<l.recursivesearch(key);
    // cout<<endl;

    // Here without calling destructor to delete linked list the main func automatically call it
    // as here the list declared is a type of static variable 
    // which means that list l is static when the main function ends it automatically call destructor 
    // while rest of the code is written in dynamic memory
    return 0;
}