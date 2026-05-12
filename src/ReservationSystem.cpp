#include <iostream>

#include <algorithm>

#include <fstream>

#include <sstream>

#include "ReservationSystem.hpp"
using namespace std;


bool ReservationSystem::loadTables(string& filename){
            // to open file
            ifstream file(filename);

            // if file cannot open:
            //     return false
            if(!file.is_open()) return false;

    // clear current tables
    tables.clear();

    string line;
    // for each line:
    while (getline(line, file)){
       stringstream ss(line);
    
    
    //     split by comma
    string idStr;
    string capacityStr;

    getline(ss,idStr, ",");
    getline(ss, capacityStr,",");
    //     parse id
    int id = stoi(idStr);
    //     parse capacity
    int capacity = stoi(capacityStr);
    //     create Table object
    Table table (id, capacity);

    //     push into tables
        tables.push(capacity);
    // return true if at least one table loaded
    }
return (!tables.empty());
}

bool ReservationSystem::loadReservations(string& filename){
    // open file
            ifstream file(filename);
    // if file cannot open:
    //     return false
            if (!file.is_open()) return false;
    // clear current reservations
    reservations.clear();
    // reset assignedReservationId to 12 x 8 filled with -1
    assignedReservationsId.clear();
    assignedReservationId.resize(12, vector<int>(8, -1));

    string line;
     
    // read and skip CSV header
    std::getline(file, line);

    // reset next id before loading
    nextReservationId = 1;
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);

        std::string idStr;
        std::string name;
        std::string partySizeStr;
        std::string slotIndexStr;
        std::string tableIdStr;

        // split by commas
        std::getline(ss, idStr, ',');
        std::getline(ss, name, ',');
        std::getline(ss, partySizeStr, ',');
        std::getline(ss, slotIndexStr, ',');
        std::getline(ss, tableIdStr, ',');

        // parse values
        int id = std::stoi(idStr);
        int partySize = std::stoi(partySizeStr);
        int slotIndex = std::stoi(slotIndexStr);
        int tableId = std::stoi(tableIdStr);

        // validate slotIndex is 0..11
        if (slotIndex < 0 || slotIndex >= 12) {
            continue;
        }

        // validate tableId maps to real table
        int tableIndex = findTableIndexById(tableId);

        if (tableIndex == -1) {
            continue;
        }

        // validate grid cell is free
        if (assignedReservationId[slotIndex][tableIndex] != -1) {
            continue;
        }

        // create Reservation object
        Reservation reservation(id, name, partySize, slotIndex, tableId);

        // save reservation
        reservations.push_back(reservation);

        // mark table as reserved for that slot
        assignedReservationId[slotIndex][tableIndex] = id;

        // update nextReservationId if needed
        if (id >= nextReservationId) {
            nextReservationId = id + 1;
        }
    }


    // return true
    return true;
  }