#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"

class HashTable
{
private:
    LinkedList* table;
    int tablesize;
    int numOfTasks = 0;
    int Hash(const QString& date);

public:
    HashTable(int size1 = 10);
    ~HashTable();
    void insertH(const Task& task);
    void printH();
    void removeH(const QString& date);
    void finalprintTasks();
    Task searchH(const QString& date);
};

#endif
