#ifndef PROJECT_H
#define PROJECT_H

#include <QMainWindow>
#include "linkedlist.h"
#include "hashtable.h" // Include the HashTable header if needed
#include "newtask.h"   // Include the newTask header if needed

QT_BEGIN_NAMESPACE
namespace Ui {
class project;
}
QT_END_NAMESPACE

class project : public QMainWindow
{
    Q_OBJECT

public:
    project(QWidget *parent = nullptr);
    ~project();

private slots:
    void on_btnAdd_clicked();
    void saveTask(const Task &task); // Add the saveTask function declaration
    void loadTasks();                 // Add the loadTasks function declaration
    void displayTasks();              // Add the displayTasks function declaration

private:
    Ui::project *ui;
    LinkedList myLinkedList;
    HashTable myHashTable;
};
#endif // PROJECT_H
