#pragma once
#include <string>


/**
 * File: Reservation.hpp
 * Author: Jalen Thornhill
 * Created: 2026-05-12
 * Last Modified: 2026-05-12
*/
using namespace std;

class Reservation
{
private:
    int id;
    string name;
    int partySize;
    int slotIdx;
    int tableId;
public:
    Reservation();
    Reservation(int id, string name, int partySize, int slotIdx, int tableId);
    ~Reservation();

    int getId() const;
    string getName() const;
    int getPartySize() const;
    int getSlotIdx() const;
    int getTableId() const;
};



