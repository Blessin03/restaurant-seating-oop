# Design — Restaurant Seating Management System OOP Version

## Architecture
The system uses three main classes:

- `Table`
- `Reservation`
- `ReservationSystem`

## Class Responsibilities

### Table
Stores table ID and capacity.

Main behavior:
- `fits(partySize)`

### Reservation
Stores one booking.

Fields:
- ID
- customer name
- party size
- slot index
- assigned table ID

### ReservationSystem
Controls the full system.

Responsibilities:
- load tables
- load reservations
- save reservations
- add reservations
- cancel reservations
- search by name
- generate reports
- export reports

## Availability Grid
The system uses a `12 × 8` grid:

```text
assignedReservationId[slotIndex][tableIndex]