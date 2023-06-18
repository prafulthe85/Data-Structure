#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

class Car{
public:
    string id;
    int x,y;

    Car(string id, int x,int y){
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
        return A.distance()< B.distance();
    }

};


void printNearestCar(vector<Car> cars, int k){


priority_queue <int , vector<Car>, CarCompare> maxheap(cars.begin(),cars.begin()+k);

    for(int i=k;i<cars.size();i++){
        auto car = cars[i];

        if(car.distance()<maxheap.top().distance()){
            maxheap.pop();
            maxheap.push(car);
        }
    }

    vector <Car> output;

    while(!maxheap.empty()){
        output.push_back(maxheap.top());
        maxheap.pop();
    }
    reverse(output.begin(),output.end());
    for(auto car : output){
        cout<<car.id<<endl;
    }

}

int main(){
    
    string id;
    int n,k;

    cin>>n>>k;

    int x,y;

    vector<Car> cars;

    for(int i=0;i<n;i++){
        cin>>id>>x>>y;
        Car car(id,x,y);
        cars.push_back(car);
    }

    printNearestCar(cars,k);

    return 0;
}