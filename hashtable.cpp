#include "hashtable.h"

int HashTable::Hash(const QString& date)
{
    int hash = 0;
    for (QChar c : date)
    {
        hash += static_cast<int>(c.unicode());
    }
    return hash % tablesize;
}

HashTable::HashTable(int size1)
{
    tablesize = size1;
    table = new LinkedList[size1]();
}

HashTable::~HashTable()
{
    delete[] table;
}

void HashTable::insertH(const Task& task)
{
    int index = Hash(task.date);
    table[index].insertLL(task);
}

void HashTable::printH()
{
    for (int i = 0; i < tablesize; i++)
    {
        qDebug() << "Bucket " << i << ":";
        table[i].printTasksLL();
    }
}

void HashTable::removeH(const QString& date)
{
    int index = Hash(date);
    table[index].removeLL(date);
}

void HashTable::finalprintTasks()
{
    for (int i = 0; i < tablesize; i++)
    {
        if (!table[i].isEmpty())
        {
            table[i].SortPriority();
            table[i].printTasksLL();
        }
    }
}

Task HashTable::searchH(const QString& date)
{
    int index = Hash(date);
    return table[index].searchLL(date);
}
