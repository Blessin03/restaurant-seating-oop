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

        vector<vector<int>> assignedReservationId;

        int nextReservationId;

        //maps table id to vector index in tables vector
        int findTableIndexFromId( int tableId);

        //check duplicate customer names
        int findReservationIndexFromName( string& customerName);

        //smallest available table that fits the party size
        int bestTableForSlot( int partySize, int slot);


        

    public:
        ReservationSystem();

        bool loadTables( string& filename);

        bool loadReservations( string& filename);

        bool saveReservations( string& filename);


        void addReservation( );
        void cancelReservation( );
        void searchByName( );

        void showTimeSlotOverview( );
        void showMaitreDReport( );
        void showCapacityUtilization( );


        bool exportMaitreDReport( string& filename);


};