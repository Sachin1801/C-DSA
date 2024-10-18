#include<iostream>
#include<string>
using namespace std ;

class Product{
    int id;
    char name[100];
    int mrp;
    int selling_price;
    

    public:
    //constructor

    //parameterised constructor 
    Product(int id, char *name, int mrp, int SP){
        // cout<<"Inside constructor"<<endl;
        this->id = id;
        strcpy(this->name,name);
        this->mrp = mrp;
        selling_price = SP;
    }

    //copy constructor
    Product(Product &X){
        mrp = X.mrp;
        selling_price = X.selling_price;
        id = X.id;
        strcpy(name,X.name);
    
    }

    //Setters
    void setMRP(int mrp){
        if(mrp>0)
            this->mrp = mrp;
    }

    void setSP(int SP){
        if(SP <= mrp)
            selling_price = SP;
        else
            selling_price=mrp;
    }

    //getters
    int getMRP(){
        return mrp;
    }
    int getSP(){
        return selling_price;
    }

    void getName(){
        cout<<name<<endl;
    }

    void showDetails(){
        cout<<"Name "<<name<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"MRP: "<<mrp<<endl;
        cout<<"SP: "<<selling_price<<endl;

        cout<<"-----------------"<<endl;
    }
        
};
int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    Product camera(2,"GoPRO8", 200,190);

    Product second_camera(camera);

    Product handycam = camera; // calls to the copy constructor
    handycam.setMRP(10000);

    // camera.setMRP(100);
    // camera.setSP(200);

    
    // cout<<camera.getMRP()<<endl;
    // cout<<camera.getSP()<<endl;
    camera.showDetails();
    cout<<endl;
    second_camera.showDetails();
    cout<<endl;
    handycam.showDetails();



    

    return 0;
}