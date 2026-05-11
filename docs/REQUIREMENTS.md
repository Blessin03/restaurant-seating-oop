# Requirements — Restaurant Seating Management System OOP Version

## Overview
A C++ console system for managing restaurant table reservations across 8 tables and 12 hourly slots from 12:00 PM to 11:00 PM.

## Core Features
- Load table data from `data/tables.txt`.
- Load and save reservations using `data/reservations.csv`.
- Add reservations using best-fit table assignment.
- Suggest a nearby time slot when the requested slot is unavailable.
- Cancel reservations by ID or by customer name and slot.
- Search reservations by customer name.
- Show a Time Slot Overview.
- Show a Maître-d daily grid report.
- Show capacity utilization by slot.
- Export the Maître-d report to a text file.

## Rules
- Party size must be greater than 0.
- Slot index must be `0..11`.
- Customer name cannot be empty.
- Duplicate customer names are not allowed.
- One table can only have one reservation per slot.

## Data Files
- `tables.txt`: `id,capacity`
- `reservations.csv`: `id,name,partySize,slotIndex,tableId`