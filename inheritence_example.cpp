#include<iostream>
using namespace std;
class Engine{
    private:
    bool is_engine_on;
    public:
    Engine() {
        is_engine_on = false;
    }
    void start_engine(){
        is_engine_on=true;
        cout<<"Engine is Running"<< endl;
    }
    void stop_engine(){
        is_engine_on = false;
        cout<<"Engine is Off"<<endl;
    }
    void displayStatus(){
        if(is_engine_on){
            cout<<"Engine is Running"<< endl;
        }
        else{
            cout<<"Engine is OFF"<< endl;
        }
    }
};
class car{
    private:
    string model;
    Engine e;
    public:
    car (string m){
        model = m;
    }
    void car_model(){
        cout<< "model is "<< model<< endl;

    }
    void showCar() {
        cout << "Car Model: " << model << endl;
    }

    void startCar() {
        cout << "Starting " << model << "..." << endl;
        e.start_engine();
    }

    void stopCar() {
        e.stop_engine();
    }

    void showEngineStatus() {
        e.displayStatus();
    }
};

int main(){
    car my_car("Tesla");
    my_car.car_model();
    my_car.showCar(); 
    my_car.startCar();

    my_car.showEngineStatus();

    my_car.stopCar();

    my_car.showEngineStatus();
    return 0;
}