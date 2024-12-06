#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std ;

class Car{
    public:
    string id;
    int x,y;
    Car(string id, int x, int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int distance() const{
        return x*x + y*y ;
        }
    friend class CarCompare;
};

class CarCompare{
public:
    bool operator()(const Car A, const Car B){
        return A.distance() < B.distance();
    }
};


bool compare(const Car A, const Car B){
    return A.distance() < B.distance();
}


void printNearestCars(vector<Car> cars, int k){
    priority_queue<Car, vector<Car>,CarCompare> maxheap(cars.begin(),cars.begin()+k);
    
    for(int i= k; i<cars.size();++i){
        Car car = cars[i];
        if(car.distance() < maxheap.top().distance()){
            maxheap.pop();
            maxheap.push(car);
        }
    }
    vector<Car> ans;
    while(!maxheap.empty()){
        ans.push_back(maxheap.top());
        // cout<<maxheap.top().id<<endl;
        maxheap.pop();
    }

    sort(ans.begin(), ans.end(), compare);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i].id<<" ";
    }
    cout<<endl;
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    int n,k;
    cin>>n>>k;
    string id;
    int x,y;
    
    vector<Car> v;

    for(int i=0;i<n;++i){
        cin>>id>>x>>y;
        Car car(id,x,y);
        v.push_back(car);
    }

    printNearestCars(v,k);
    

    return 0;
}