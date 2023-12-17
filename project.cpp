#include "project.h"
#include "ui_project.h"
#include "newtask.h"
#include "qradiobutton.h"
#include <QVBoxLayout>
#include <QFile>
#include <QDataStream>
#include "project.h"
#include "linkedlist.h"

project::project(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::project)
{
    ui->setupUi(this);
    loadTasks(); // Load saved tasks when the GUI is created
}

project::~project()
{
    delete ui;
}

void project::on_btnAdd_clicked()
{
    newTask n(myLinkedList, myHashTable, this);
    n.setModal(true);
    n.exec();

    // Retrieve the Task object from newTask
    Task taskObject = n.getTaskObject();

    // Save the Task object to a binary file
    saveTask(taskObject);

    // Display the saved tasks on the GUI
    displayTasks();
}

void project::saveTask(const Task &task)
{
    QFile file("tasks.bin");
    if (file.open(QIODevice::Append)) {
        QDataStream out(&file);
        out << task;
        file.close();
    }
}

void project::loadTasks()
{
    QFile file("tasks.bin");
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        while (!in.atEnd()) {
            QString description, date;
            Priority priority;

            // Read the task details from the file
            in >> description >> date >> priority;

            // Create a Task object
            Task task(description, date, priority);

            // Process the loaded task as needed
            // For example, you can add it to your linked list or hash table
        }
        file.close();
    }
}

void project::displayTasks()
{
    // Clear existing layout
    QLayout *layout = ui->scrollArea->layout();
    if (layout) {
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        delete layout;
    }

    // Create a new layout
    QVBoxLayout *newLayout = new QVBoxLayout(ui->scrollArea);

    // Load and display tasks from the binary file
    QFile file("tasks.bin");
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        while (!in.atEnd()) {
            QString description, date;
            Priority priority;

            // Read the task details from the file
            in >> description >> date >> priority;

            // Create a new QRadioButton with the task details
            QRadioButton *radioButton = new QRadioButton(
                QString("%1 - Date: %2").arg(description).arg(date),
                ui->scrollArea);

            // Add the QRadioButton to the layout
            newLayout->addWidget(radioButton);
        }
        file.close();
    }
}
