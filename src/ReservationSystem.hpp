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
    void printTables();
    void initializeAvailability();
    void printAvailabilityGridDebug() const;


    bool isValidSlot(int slotIdx);
    bool isAvailable(int slotIndex, int tableIndex) const;
    bool customerNameExists(string& name);

    string slotToTime(int slotIdx) ;




    void addReservationObject(const Reservation& reservation);
    void printReservations() const;


    int findBestTable(int slotIdx, int partySize);

};