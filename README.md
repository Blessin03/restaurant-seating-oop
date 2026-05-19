# README

C++ OOP console system for managing restaurant reservations.

## Main features
- Added reservations with best-fit table assignment
- Suggests nearest available slot if requested slot is full
- Cancel reservations
- Searchs by customer name
- Shows time slot overview
- Shows Maître-d daily grid report
- Shows capacity utilization summary
- Save/load reservations with CSV
- can Export report to text file


## Tech 
C++ classes
Encapsulation
Vectors
File Handling
Input validation
<iomanip> formatted reports

## Build

```bash
g++ src/main.cpp src/Table.cpp src/Reservation.cpp src/ReservationSystem.cpp -o  restaurant_oop.exe
```


## Run
```bash
.\restaurant_oop.exe
```