#pragma once
#include <QDataStream>
#include <QString>
#include <QDebug>

enum Priority
{
    priority1 = 1,
    priority2 = 2,
    priority3 = 3,
    priority4 = 4,
    priority5 = 5
};

class Task
{
public:
    QString description;
    QString date;
    Priority priority;

    Task(const QString& des, const QString& dt, Priority pri)
        : description(des), date(dt), priority(pri)
    {
    }

    // Implement serialization functions
    friend QDataStream &operator<<(QDataStream &out, const Task &task)
    {
        out << task.description << task.date << static_cast<int>(task.priority);
        return out;
    }

    friend QDataStream &operator>>(QDataStream &in, Task &task)
    {
        int priority;
        in >> task.description >> task.date >> priority;
        task.priority = static_cast<Priority>(priority);
        return in;
    }
};
class LinkedList
{

private:
    class Node
    {
    public:
        Task task;
        Node* next;

        Node(const Task& t) : task(t), next(nullptr) {}
    };
    Node* First;

public:
    LinkedList();
    ~LinkedList();
    // In the LinkedList class definition (linkedlist.h)
    Task& insertLL(const Task& task);
    void printTasksLL();
    void removeLL(const QString& date);
    void SortPriority();
    bool isEmpty() const;
    Task searchLL(const QString& date) const;
};
