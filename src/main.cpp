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


switch (choice){
case 1:
    break;
case 2:
    break;
case 3:
    break;
case 4:
    break;  
case 5:
    break;
case 6:
    break;
case 7:
    break;
case 8:

    cout << "Thank you for using Jalen's Restaurant Seating Management System!\n";
    systemsaveReservations("../data/reservations.csv");
    cout << "saving data and exiting...\n";
    break;

default:
    cout << "Invalid choice. :( Please try again.\n";

}
} while (choice != 8);



    return 0;
}