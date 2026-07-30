#include <iostream>
#include <queue>
using namespace std;
enum class Direction{
    UP, DOWN ,IDLE
};
enum Door{
    OPEN,
    CLOSE
};
class Elevator{
    public:
    int elevator_id;
    int current_floor;
    Direction* direction;
    queue<int > requests;
    Door* door;
    Elevator(int id, int f, Direction* d ){
        elevator_id = id;
        current_floor= f;
        direction = d;
        door = nullptr;
    }
    void addRequest(int floor){
        requests.push(floor);
    }
    void move_onr_floor(){
        current_floor += 1;
    }
    void open_door(){
        door = "OPEN";
    }
    void close_door(){
        door = "CLOSE";
    }
    int processNextRequest(){
        if(!requests.empty()){
        int next_floor= requests.front();
        requests.pop();
        return next_floor
        }
        else
        return -1;
    }
    void setDirection(){
        int next_floor= processNextRequest();
        if( next_floor== -1 || (current_floor - next_floor == 0)){
            d ="IDLE";
        }
        else if(current_floor - next_floor > 0){  
            direction -> "UP";
        }
        else {
            direction = "DOWN";
        }
    }
    void getCurrentFloor(){
        cout<<current_floor<<endl;
    }
};
class Elevator_system{
    vector<Elevator*> Elevators;
    Direction * d;
    virtual void Elevator_system() =0;{

    }
}