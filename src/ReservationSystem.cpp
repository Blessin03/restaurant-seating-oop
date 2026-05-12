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

