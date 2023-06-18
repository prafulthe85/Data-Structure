#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// car problem to find the car id nearest to the origin based on the distance

class Car {
public:

    string id;
    int x,y;

    Car(string id,int x,int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int distance() const{
        return x*x + y*y;
    }
};

class CarCompare{
public:

    bool operator()(Car A, Car B){
        return A.distance() < B.distance();// max heap is executed
    }

};

void PrintNearestCar(vector<Car> cars,int k){
    // make max heap of size k so that first enter k car data and then enter next car data

    priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin()+k);

    for(int i =k;i<cars.size();i++){
        auto car = cars[i];
    // while entering the data of next cars if distance of that car from origin is smaller than 
    // the max element of max heap then pop the max element and input the current element
        if(car.distance() < max_heap.top().distance()){
            max_heap.pop();
            max_heap.push(car);
        }
    }

    vector <Car> output;
    // make a vector output to store the cars
    while(!max_heap.empty()){
        output.push_back(max_heap.top());
        max_heap.pop();
    }

    // automatically in priority queue the cars are arranged in descending order so to convert to ascending reverse the vector
    reverse(output.begin(),output.end());

    for(auto car: output){
        cout<<car.id<<endl;
    }


}
/*
    input
    6 3
    c1 1 0
    c2 1 2
    c3 2 3 
    c4 1 1 
    c5 3 2
    c6 0 2

*/


int main(){

    int N,K;
    cin>>N>>K;

    string id;
    int x,y;

    vector<Car> cars;

    for(int i=0;i<N;i++){
        cin>>id>>x>>y;
        Car car(id,x,y);
        cars.push_back(car);
    }   

    PrintNearestCar(cars,K);

    return 0;
}