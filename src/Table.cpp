#include "Table.hpp"

/**
 * File: Table.cpp
 * Author: Jalen Thornhill
 * Created: 2026-05-12
 * Last Modified: 2026-05-12
 *
 **/



Table::Table() : id(0), capacity (0){}
Table::Table(int id, int capacity) : id(id)  , capacity(capacity){}
Table::~Table(){}

int Table::getID()  const{
            return id;
}

int Table::getCapacity() const{
    return capacity;
}

bool Table::fits(int partySize){
    return partySize <= getCapacity();
}