#pragma once

#include <string>

#include <vector>

#include "Reservation.hpp"

#include "Table.hpp"

using namespace std;

class ReservationSystem {
    private:
        vector<Table> tables;

        vector<Reservation> reservations;

        static const int NUM_SLOTS = 12;
        static const int NUM_TABLES = 8;

        int assignedReservationId[NUM_SLOTS][NUM_TABLES];



        

    public:
        ReservationSystem();

    void loadDefaultTables();
    void printTables() ;

    bool isValidSlot(int slotIdx) ;
    string slotToTime(int slotIdx) ;



    void initializeAvailability();
    bool isAvailable(int slotIndex, int tableIndex) const;
    void printAvailabilityGridDebug() const;
};