#include <iostream>

#include <algorithm>

#include <fstream>

#include <sstream>

#include<climits>
    #include<iomanip>

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

int ReservationSystem::findNearestAlternativeSlot(int requestedSlot, int partySize) {
  
  if (!isValidSlot(requestedSlot)) {
        return -1;
    }

 if (findBestTable(requestedSlot, partySize) != -1) {
        return requestedSlot;
    }
  
  
    for (int offset = 1; offset < NUM_SLOTS; offset++) {
        int earlierSlot = requestedSlot - offset;
        int laterSlot = requestedSlot + offset;

        if (isValidSlot(earlierSlot) && findBestTable(earlierSlot, partySize) != -1) {
            return earlierSlot;
        }

        if (isValidSlot(laterSlot) && findBestTable(laterSlot, partySize) != -1) {
            return laterSlot;
        }
    }  
    return -1;
}

bool ReservationSystem::cancelReservationById(int reservationId){
    if (reservationId < 0) return false;


    int index = 0;
    for(auto& reservation : reservations){
        if(reservation.getId() == reservationId){
            return index;
        }
        index++;
    }
    return -1;
}


bool ReservationSystem::cancelReservationByNameAndSlot(string& name, int slotIdx){

      if(!isValidSlot(slotIdx)) return false;

      for(auto& reservation : reservations){
        if(reservation.getName() == name && reservation.getSlotIdx() == slotIdx){
                cancelReservationById(reservation.getId());
                return true;
        }
      }
      
      return false; 
}

void ReservationSystem::searchByCustomerName( string& name) {
    
    for(auto& reservation : reservations){
        if (name == reservation.getName()){
            cout << "ID: " << reservation.getId() << "\n";
            cout << "Name: " << reservation.getName() << "\n";
            cout << "Party Size: " << reservation.getPartySize() << "\n";
            cout << "Slot Index: " << reservation.getSlotIdx() << "\n";
            cout << "Table ID: " << reservation.getTableId() << "\n";
            return;
        }
    }

    cout << "No reservation found for customer: " << name << " :( \n";
}

void ReservationSystem::showTimeSlotOverview(int slotIndex)  {
    if (!isValidSlot(slotIndex)) {
        cout << "Invalid slot\n";
        return;
    }

    cout << "Time Slot Overview for " << slotToTime(slotIndex) << "\n";

    cout << left << setw(13) << "Table"
            << setw(13) << "Capacity"
            << setw(15) << "Status\n";

    int index = 0;
    string status = "";
    for(auto& table : tables){
        status="";
                if( isAvailable(slotIndex, index )){
                    status = "available" ;
                } 
                else{
                    for(auto& reservation : reservations){
                        if (assignedReservationId[slotIndex][index] == reservation.getId()){
                            status = "booked by " + reservation.getName() + "(size " + to_string(reservation.getPartySize()) +")"; 
                        }
                    }
                }

    cout << left << setw(13) << table.getID()
            << setw(13) << table.getCapacity()
            << setw(15) << status << "\n";
            index++;
    }
}

void ReservationSystem::showMaitreReport() {
    cout << "Maitre-D Report\n\n";

    cout << left << setw(13) << "Table"
         << setw(13) << "Capacity";

    for (int slotIndex = 0; slotIndex < NUM_SLOTS; slotIndex++) {
        cout << setw(15) << slotToTime(slotIndex);
    }

    cout << "\n";

    for (int tableIndex = 0; tableIndex < NUM_TABLES; tableIndex++) {
        cout << left << setw(13) << tables[tableIndex].getID()
             << setw(13) << tables[tableIndex].getCapacity();

        for (int slotIndex = 0; slotIndex < NUM_SLOTS; slotIndex++) {
            int reservationId = assignedReservationId[slotIndex][tableIndex];

            if (reservationId == -1) {
                cout << setw(15) << "Avail";
            } 
            else {
                string reservationInfo = "ERR";

                for (const auto& reservation : reservations) {
                    if (reservation.getId() == reservationId) {
                        reservationInfo = reservation.getName().substr(0, 1)
                                        + "#"
                                        + to_string(reservationId);
                        break;
                    }
                }

                cout << setw(15) << reservationInfo;
            }
        }

        cout << "\n";
    }

    cout << "\n";
}

void ReservationSystem::showCapacityUtilizationSummary(){
    cout <<  "Capacity Utilization Summary\n\n";


    cout<< left<< setw(13) << "Time Slot" 
        << setw(20) << "Booked Seats"
        << setw(25) << "Available Seats"
        << setw(20) << "Utilization by %\n";


        int bookedSeats, totalSeats, index;
        for(int slotIdx = 0; slotIdx < NUM_SLOTS; slotIdx++){
            bookedSeats =0;
            totalSeats = 0;
            index = 0;

            for(auto& table : tables){
                totalSeats += table.getCapacity();

                int reservationId = assignedReservationId[slotIdx][index];
                index++;
                if(reservationId != -1){

                    for(auto& reservation : reservations){
                        if (reservationId == reservation.getId())
                        bookedSeats += reservation.getPartySize();
                        break;
                    }
                    
                }
            }
            if(totalSeats == 0) {
            cout << "wait... Your restaurant has to tables :/";
            return;
        }
        int availableSeats = totalSeats - bookedSeats;
        double utilization = static_cast<double>((bookedSeats) / static_cast<double> (totalSeats)) * 100;

        cout << left << setw(13) << slotToTime(slotIdx)
                << setw(20) << bookedSeats
                << setw(25) << availableSeats
                << setw(20) << fixed << setprecision(2) << utilization << "%\n";
        }
        
}


bool ReservationSystem::loadTables(const string& filename) {
    ifstream file(filename);

    if(!file.is_open()) {
        cout << "Error opening file: " << filename << "\n";
        return false;
    }

    tables.clear();


    string line;
    while(getline(file,line)){
        stringstream ss(line);
        string idStr, capacityStr;

        if (!getline(ss, idStr, ',')) {
            cout << "Error with line: " << line << "\n";
            continue;
        } 
        if (!getline(ss, capacityStr, ',')) {
            cout << "Error with line: " << line << "\n";
            continue;
        }
        int id = stoi(idStr);
        int capacity = stoi(capacityStr);

       Table table(id, capacity);
         tables.push_back(table);
    }

    file.close();

    return !tables.empty();
}
