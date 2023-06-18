#include <iostream>
#include <vector>
#include <string>
using namespace std;


// here heap is considered to be of min heap
class Heap{
    vector <int> v;
    string s;
    
int compare(int n, int m){
    if(s=="min"){
        return n<m;
    }
    else {
        return m<n;
    }
}

    void heapify(int i){
        int left = 2*i;
        int right = 2*i + 1;

        int minidx = i;

        if(left<v.size() and compare(v[i],v[left])){
            minidx = left;
        }

        if(right<v.size() and compare(v[minidx],v[right])){
            minidx = right;
        }

        if(minidx!=i){
            swap(v[minidx],v[i]);
            heapify(minidx);
        }
    }

public:
    Heap(string s,int default_size =10){
        v.reserve(default_size+1);
        v.push_back(-1);
    };

    void push(int data){

        // add data at the end of the heap
        v.push_back(data);

        int idx = v.size()-1;

        int parent = idx/2;

        
        while(idx<v.size() and compare(v[idx] , v[parent])){
            swap(v[idx],v[parent]);
            idx = parent;
            parent = parent/2;
        }
    }

    int top(){
        return v[1];
    }

    void pop(){
        int idx = v.size()-1;

        swap(v[idx], v[1]);
        heapify(1);
    }


};