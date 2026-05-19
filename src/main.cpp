/**
 * File: main.cpp
 * Author: Jalen Thornhill
 * Created: 2026-05-12
 * Last Modified: 2026-05-12
 *
 **/

#include <iostream>
#include<fstream>
#include "ReservationSystem.hpp"


using namespace std;
int main(){
    // create ReservationSystem object
    ReservationSystem system;
    // load tables from data/tables.txt
    system.loadTables("../data/tables.txt");
    // load reservations from data/reservations.csv
    system.loadReservations("../data/reservations.csv");


    // menu loop
int choice;
do{

cout << "===== Restaurant Seating Management System =====\n";
cout << "1. Add reservation\n";
cout << "2. Cancel reservation\n";
cout << "3. Search by customer name\n";
cout << "4. Show Time Slot Overview\n";
cout << "5. Show Maître-d Report\n";
cout << "6. Show Capacity Utilization Summary\n";
cout << "7. Export Maître-d Report\n";
cout << "8. Save & Exit\n";
cout << "Choose an option: ";
cin >> choice;


switch (choice) {
case 1: {
    cout << "Enter the name of the customer: ";
    string name;
    cin >> name;

    cout << "Enter their party size: ";
    int partySize;
    cin >> partySize;

    cout << "Enter the desired time slot (0-11, where 0=12:00, 1=13:00, ..., 11=23:00): ";
    int slotIdx;
    cin >> slotIdx;

    if (system.addReservation(name, partySize, slotIdx)) {
        cout << "Reservation added successfully!\n";
    } else {
        cout << "Failed to add reservation.\n";

        int alternativeSlot = system.findNearestAlternativeSlot(slotIdx, partySize);

        if (alternativeSlot != -1) {
            cout << "Suggested alternative time slot: "
                 << system.slotToTime(alternativeSlot) << "\n";
        } else {
            cout << "No alternative time slot available.\n";
        }
    }

    break;
}

case 2: {
    cout << "Cancel by:\n1. Reservation ID\n2. Customer Name and Time Slot\nChoose an option: ";

    int cancelChoice;
    cin >> cancelChoice;

    if (cancelChoice == 1) {
        cout << "Enter the reservation ID to cancel: ";

        int reservationId;
        cin >> reservationId;

        if (system.cancelReservationById(reservationId)) {
            cout << "Reservation cancelled successfully!\n";
        } else {
            cout << "Failed to cancel reservation. ID not found.\n";
        }
    } 
    else if (cancelChoice == 2) {
        cout << "Enter the customer name: ";

        string cancelName;
        cin >> cancelName;

        cout << "Enter the time slot (0-11): ";

        int cancelSlot;
        cin >> cancelSlot;

        if (system.cancelReservationByNameAndSlot(cancelName, cancelSlot)) {
            cout << "Reservation cancelled successfully!\n";
        } else {
            cout << "Failed to cancel reservation. No matching reservation found.\n";
        }
    }

    break;
}

case 3: {
    cout << "Enter the customer name to search: ";

    string name;
    cin >> name;

    system.searchByCustomerName(name);

    break;
}

case 4: {
    cout << "Enter the time slot to view (0-11): ";

    int slotIndex;
    cin >> slotIndex;

    system.showTimeSlotOverview(slotIndex);

    break;
}

case 5: {
    system.showMaitreReport();

    break;
}

case 6: {
    system.showCapacityUtilizationSummary();

    break;
}

case 7: {
    cout << "Enter the filename to export the Maître-d Report (e.g., maitre_report.txt): ";

    string filename;
    cin >> filename;

    if (system.exportMaitreReport(filename)) {
        cout << "Maitre-d Report exported successfully!\n";
    } else {
        cout << "Failed to export Maître-d Report.\n";
    }

    break;
}

case 8: {
    cout << "Saving data and exiting...\n";

    system.saveReservations("../data/reservations.csv");

    break;
}

default: {
    cout << "Invalid choice. :( Please try again.\n";

    break;
}
}
} while (choice != 8);



    return 0;
}