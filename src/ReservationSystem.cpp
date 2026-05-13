#include <iostream>

#include <algorithm>

#include <fstream>

#include <sstream>

#include "ReservationSystem.hpp"
using namespace std;


ReservationSystem::ReservationSystem() {}


void ReservationSystem::loadDefaultTables(){


    tables.clear();

    
    tables.push_back(Table(1,2));
    tables.push_back(Table(2,2));
    tables.push_back(Table(3,4));
    tables.push_back(Table(4,4));
    tables.push_back(Table(5,4));
    tables.push_back(Table(6,6));
    tables.push_back(Table(7,6));
    tables.push_back(Table(8,8));


}

void ReservationSystem::printTables(){
    cout << "Available Tables:" << endl;
    for (auto& table : tables){
        cout << "Table: " << table.getID() << "cap: " << table.getCapacity();
    }
}

bool ReservationSystem::isValidSlot(int slotIdx){
    return slotIdx >= 0 && slotIdx < 12;
}

string ReservationSystem::slotToTime(int slotIdx){

    if (!isValidSlot(slotIdx)) {
        return "Invalid Slot";
    }
    return to_string(12 + slotIdx) + ":00";
}