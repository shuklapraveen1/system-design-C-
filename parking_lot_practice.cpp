#include <iostream>
#include <vector>
using namespace std;
enum class VehicleType{
    
    CAR,
    BIKE, BUS
};
class Vehicle{
    public:
    string Vehicle_id;
    VehicleType type;
    public:
    Vehicle(string id, VehicleType t){
        Vehicle_id =id;
        type = t;
    } 
};
class ParkingLot{
    private:
    int spot_id;
    bool isAvailable;
    Vehicle* vehicle;
    VehicleType spotType;
    public:
    ParkingLot(int id, VehicleType type){
        spot_id = id;
        isAvailable= false;
        vehicle = NULL;
        spotType = type;
    }
    bool Spot_Available(){
        return isAvailable;
    }
    void ParkVehicle(Vehicle* v){
        vehicle= v;
        isAvailable = false;
    }
    bool canPark(Vehicle* v){
        return v->getType() == spotType;
    }
};
class ParkingFloor {
public:
    int floorNumber;
    vector<ParkingLot> spots;

    ParkingFloor(int number) {
        floorNumber = number;
    }

    void addSpot(ParkingLot spot) {
        spots.push_back(spot);
    }

    ParkingLot* findAvailableSpot(VehicleType type) {

        for (auto &spot : spots) {

            if (spot.Spot_Available() && spot.canPark(new Vehicle("", type))) {
                return &spot;
            }
        }

        return NULL;
    }
};

