#pragma once

/**
 * File: Table.hpp
 * Author: Jalen Thornhill
 * Created: 2026-05-12
 * Last Modified: 2026-05-12
 *
 **/

using namespace std;
class Table{
private:
    int id;
    int capacity;
public:
    Table();
    Table (int id, int capacity);
    ~Table();

    int getID() const;
    int getCapacity() const;
    bool fits(int partySize);
};

