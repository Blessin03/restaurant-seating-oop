/**
 * File: Reservation.cpp
 * Author: Jalen Thornhill
 * Created: 2026-05-12
 * Last Modified: 2026-05-12
*/
#include "Reservation.hpp"
#include <string>
using namespace std;

Reservation::Reservation() : id(0), name(""), partySize(0), slotIdx(0), tableId(0) {}

Reservation::Reservation(int id, string name, int partySize, int slotIdx, int tableId) : id(id), name(name), partySize(partySize), slotIdx(slotIdx), tableId(tableId) {}

Reservation::~Reservation() {}

int Reservation::getId() const {
            return id;
}

string Reservation::getName() const {
    return name;
}

int Reservation::getPartySize() const {
            return partySize;
}
int Reservation::getSlotIdx() const {
            return slotIdx;
}
int Reservation::getTableId() const {
            return tableId;
}