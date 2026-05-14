#include <iostream>

#include <algorithm>

#include <fstream>

#include <sstream>

#include<climits>

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

void ReservationSystem::addReservationObject(const Reservation& reservation) {
    reservations.push_back(reservation);
}

void ReservationSystem::printReservations() const {
    cout << "Reservations \n"; 

    if (reservations.empty()) {
        cout << "No reservations found.\n"; 
        return;
    }

    for (const auto& reservation : reservations) {
        cout << "ID: " << reservation.getId() << endl;
        cout << "Name: " << reservation.getName() << endl;
        cout << "Party Size: " << reservation.getPartySize() << endl;
        cout << "Slot Index: " << reservation.getSlotIdx() << endl;
        cout << "Table ID: " << reservation.getTableId() << endl;
        cout << endl;
    }
}

bool ReservationSystem::customerNameExists(string& name){
    for(auto& reservation : reservations) if (reservation.getName() == name) return true;

    return false;
}

int ReservationSystem::findBestTable(int slotIdx, int partySize){
   if(!isValidSlot(slotIdx)) return -1;
   if (partySize <= 0) return -1;
   

   int tableIdx = 0;
   int bestFit = INT_MAX;
   int bestTable = 0;
   for(auto& table : tables){

    if (!isAvailable( slotIdx,  tableIdx)) {
        tableIdx++;
        continue;
   }

   if(table.getCapacity() < partySize){
        tableIdx++;
        continue;
   }

   if(table.getCapacity() == partySize) return table.getID();
   
    if (table.getCapacity()  < bestFit){
        bestFit = table.getCapacity();
        bestTable = table.getID();
    }
     

    tableIdx++;
   }

   return bestFit == INT_MAX ? -1 : bestTable;
}

int ReservationSystem::findBestTableID(int tableId){
    for (auto& table : tables) if (table.getID() == tableId) return table.getID();

    return -1;
}

bool ReservationSystem::addReservation(string& name, int partySize, int slotIdx){
    if (partySize <= 0) return false;
    if (customerNameExists(name)) return false;
    if (!isValidSlot(slotIdx)) return false;
 

    int bestTableId = findBestTable(slotIdx, partySize);

    if (bestTableId == -1) return false;

    int tableIdx = findBestTableID(bestTableId);

        int reservationId = nextReservationId;
            Reservation reservation(reservationId, name, partySize, slotIdx, bestTableId);

            reservations.push_back(reservation);

            assignedReservationId[slotIdx][tableIdx] = reservationId;
            nextReservationId++;
            return true;
}