#include <bits/stdc++.h>
#include <chrono>

using namespace std;

// enums for supporting structs

enum class VehicleType {
    MOTORBIKE,
    CAR,
    TRUCK,
    ELECTRIC
};

enum class SpotType {
    COMPACT,
    MOTORBIKE,
    LARGE,
    ELECTRIC
};

enum class TicketStatus {
    ACTIVE,
    PAID,
    LOST
};

enum class PaymentMethod {
    CASH,
    CARD,
    UPI
};

// entities

struct Vehicle {
    string plate;
    VehicleType type;
};

struct ParkingSpot {
    string id;
    SpotType type;
    bool occupied = false;
};

struct Ticket {
    string id;
    string spotId;
    string VehicleType;
    chrono::time_point<clock_t> entry;
    chrono::time_point<clock_t> exit;
    TicketStatus status = TicketStatus::ACTIVE;
};

class ParkingFloor {
    public:
        int number;
        unordered_map<string, ParkingSpot> spots;
        unordered_map<SpotType, set<string> > freeSpots;

        ParkingFloor(int num): number(num) {};

        void addSpot(const ParkingSpot& s) {
            spots[s.id] = s;
            freeSpots[s.type].insert(s.id);
        }

        optional<string> allocate(SpotType type) {
            if (freeSpots[type].empty()) {
                return nullopt;
            }
            // iterator over set
            auto id = *freeSpots[type].begin();
            freeSpots[type].erase(freeSpots[type].begin());
            spots[id].occupied = true;
            return id;
        }

        void release(string spotId) {
            auto& sp = spots[spotId];
            sp.occupied = false;
            freeSpots[sp.type].insert(spotId);
        }
};

class ParkingLot {
    vector<ParkingFloor> floors;
    unordered_map<string, Ticket> activeTickets;
    RateCard rateCard;
    int ticketSeq = 0;
    public:
        void addFloor(ParkingFloor f) {
            floors.push_back(f);
        }

        Ticket ParkVehicle(const Vehicle& v) {
            for (auto& f: floors) {
                auto spot = f.allocate(SpotType::COMPACT);
                if (spot) {
                    Ticket t;
                    t.id = 'T'+to_string(++ticketSeq);
                    t.spotId = *spot;
                    t.VehicleType = v.plate;
                    t.entry = clock::now;
                    activeTickets[t.id] = t;
                    return t;
                }
            }
            throw runtime_error("No spot");
        }
};

int main() {

}