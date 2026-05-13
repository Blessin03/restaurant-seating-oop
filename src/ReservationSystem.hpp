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



        

    public:
        ReservationSystem();

    void loadDefaultTables();
    void printTables() ;

    bool isValidSlot(int slotIdx) ;
    string slotToTime(int slotIdx) ;

};