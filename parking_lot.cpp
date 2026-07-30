#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum VehicleType {
    MOTORCYCLE,
    CAR,
    TRUCK
};

// ---------------- Vehicle ----------------

class Vehicle {
public:
    string vehicleNumber;
    VehicleType type;

    Vehicle(string number, VehicleType t) {
        vehicleNumber = number;
        type = t;
    }
};

// ---------------- Parking Spot ----------------

class ParkingSpot {
public:
    int spotId;
    VehicleType spotType;
    bool occupied;
    Vehicle* vehicle;

    ParkingSpot(int id, VehicleType type) {
        spotId = id;
        spotType = type;
        occupied = false;
        vehicle = NULL;
    }

    bool isAvailable() {
        return !occupied;
    }

    bool canPark(Vehicle* v) {
        return v->type == spotType;
    }

    void parkVehicle(Vehicle* v) {
        vehicle = v;
        occupied = true;
    }

    void removeVehicle() {
        vehicle = NULL;
        occupied = false;
    }
};

// ---------------- Parking Floor ----------------

class ParkingFloor {
public:
    int floorNumber;
    vector<ParkingSpot> spots;

    ParkingFloor(int number) {
        floorNumber = number;
    }

    void addSpot(ParkingSpot spot) {
        spots.push_back(spot);
    }

    ParkingSpot* findAvailableSpot(VehicleType type) {

        for (auto &spot : spots) {

            if (spot.isAvailable() && spot.canPark(new Vehicle("", type))) {
                return &spot;
            }
        }

        return NULL;
    }
};

// ---------------- Ticket ----------------

class Ticket {
public:
    int ticketId;
    long long entryTime;
    Vehicle* vehicle;
    ParkingSpot* spot;

    Ticket(int id, Vehicle* v, ParkingSpot* s) {
        ticketId = id;
        vehicle = v;
        spot = s;
        entryTime = 0;      // Assume current time
    }
};

// ---------------- Parking Lot ----------------

class ParkingLot {

public:
    vector<ParkingFloor> floors;

    Ticket* issueTicket(Vehicle* vehicle) {

        for (auto &floor : floors) {

            ParkingSpot* spot = floor.findAvailableSpot(vehicle->type);

            if (spot != NULL) {

                spot->parkVehicle(vehicle);

                Ticket* ticket = new Ticket(1, vehicle, spot);

                return ticket;
            }
        }

        return NULL;
    }

    double processExit(Ticket* ticket) {

        ticket->spot->removeVehicle();

        return 50.0;      // Assume parking fee
    }
};