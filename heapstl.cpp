#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class compare{
public:
    bool operator()(int a, int b){
        return a<b;
    }
};

int main(){

    vector <int> arr ={4,60,12,15,20};
    
    // priority_queue <int> heap; 
    // by default, it is a max heap to make it min or max use below method 

    priority_queue<int, vector<int>, compare> heap;

    for(int x: arr){
        heap.push(x);
    }

    while(!heap.empty()){
        cout<<heap.top()<<" ";
        heap.pop();
    }

    return 0;
}