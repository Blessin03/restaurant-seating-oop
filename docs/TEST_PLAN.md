# Test Plan
| Test | Scenario                               | Expected Result                                                      |
| ---- | -------------------------------------- | -------------------------------------------------------------------- |
| T1   | Add 3–5 mixed reservations             | Reservations are assigned to the smallest suitable available tables. |
| T2   | Add a party larger than table capacity | System rejects the booking with a clear message.                     |
| T3   | Requested slot unavailable             | System suggests the nearest available alternative slot.              |
| T4   | Cancel a reservation                   | Reservation is removed and the table becomes available again.        |
| T5   | Search by customer name                | Matching reservation details are displayed.                          |
| T6   | Show Time Slot Overview                | All tables for the selected slot show Available or Booked.           |
| T7   | Show Maître-d Report                   | Full daily table/slot grid is displayed clearly.                     |
| T8   | Export Maître-d Report                 | Report is saved to a text file and filename is confirmed.            |
