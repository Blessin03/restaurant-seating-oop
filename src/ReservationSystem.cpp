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

void ReservationSystem::initializeAvailability() {
    for (int slotIndex = 0; slotIndex < NUM_SLOTS; slotIndex++) {
        for (int tableIndex = 0; tableIndex < NUM_TABLES; tableIndex++) {
            assignedReservationId[slotIndex][tableIndex] = -1;
        }
    }
}

bool ReservationSystem::isAvailable(int slotIndex, int tableIndex) const {
    if (slotIndex < 0 || slotIndex >= NUM_SLOTS) {
        return false;
    }

    if (tableIndex < 0 || tableIndex >= NUM_TABLES) {
        return false;
    }

    return assignedReservationId[slotIndex][tableIndex] == -1;
}

void ReservationSystem::printAvailabilityGridDebug() const {
    cout << "Availability Grid Debug:" << endl;

    for (int slotIndex = 0; slotIndex < NUM_SLOTS; slotIndex++) {
        cout << "Slot " << slotIndex << ": ";

        for (int tableIndex = 0; tableIndex < NUM_TABLES; tableIndex++) {
            cout << assignedReservationId[slotIndex][tableIndex] << " ";
        }

        cout << endl;
    }
}