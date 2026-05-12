#include "ReservationSystem.h"

ReservationSystem::ReservationSystem()
    : assignedReservationId(12, std::vector<int>(8, -1)),
      nextReservationId(1)
{
}

bool ReservationSystem::loadTables(const std::string& filename) {
    return false;
}

bool ReservationSystem::loadReservations(const std::string& filename) {
    return false;
}

bool ReservationSystem::saveReservations(const std::string& filename) const {
    return false;
}

void ReservationSystem::addReservation() {
    // later: ask for input, validate, assign table
}

void ReservationSystem::cancelReservation() {
    // later: cancel by ID or name + slot
}

void ReservationSystem::searchByName() const {
    // later: search reservation list
}

void ReservationSystem::showTimeSlotOverview() const {
    // later: print selected slot
}

void ReservationSystem::showMaitreDReport() const {
    // later: print full grid
}

void ReservationSystem::showCapacityUtilization() const {
    // later: print seats booked/available per slot
}

bool ReservationSystem::exportMaitreDReport(const std::string& filename) const {
    return false;
}