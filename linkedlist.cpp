#include "linkedlist.h"
#include <QDebug>

LinkedList::LinkedList()
{
    First = nullptr;
}

LinkedList::~LinkedList()
{
    Node* current = First;
    while (current != nullptr)
    {
        Node* ptr = current->next;
        delete current;
        current = ptr;
    }
}

Task& LinkedList::insertLL(const Task& task)
{
    Node* newNode = new Node(task);
    newNode->next = First;
    First = newNode;
    return newNode->task;  // Return a reference to the inserted task
}

void LinkedList::printTasksLL()
{
    Node* current = First;
    while (current != nullptr)
    {
        qDebug() << "Date: " << current->task.date;
        qDebug() << " Priority: " << current->task.priority;
        qDebug() << " Description: " << current->task.description << Qt::endl;
        current = current->next;
    }
}

void LinkedList::removeLL(const QString& date)
{
    Node* current = First;
    Node* prev = nullptr;

    while (current != nullptr && current->task.date != date) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (prev == nullptr) {
            First = current->next;
        }
        else {
            prev->next = current->next;
        }
        delete current;
    }
}

void LinkedList::SortPriority()
{
    if (First == nullptr || First->next == nullptr) return;
    Node* current = First;
    Node* nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        while (nextNode != nullptr)
        {
            if (current->task.priority < nextNode->task.priority)
            {
                std::swap(current->task, nextNode->task);
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

bool LinkedList::isEmpty() const
{
    return First == nullptr;
}

Task LinkedList::searchLL(const QString& date) const
{
    Node* current = First;
    while (current != nullptr)
    {
        if (current->task.date == date)
        {
            return current->task; // Found the task
        }
        current = current->next;
    }
    return Task("", "", Priority());
}
