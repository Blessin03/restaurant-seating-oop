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