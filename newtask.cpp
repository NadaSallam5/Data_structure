#include "newtask.h"
#include "hashtable.h"
#include "ui_newtask.h"
#include "duedate.h"
#include "linkedlist.h"
#include <QMessageBox>

newTask::newTask(LinkedList& linkedList, HashTable& tasks, QWidget* parent)
    : QDialog(parent), ui(new Ui::newTask), linkedListRef(linkedList), Tasks(tasks),
    newTaskObject("", "", priority1)  // Initialize with default values
{
    ui->setupUi(this);
}

newTask::~newTask()
{
    delete ui;
}
Task newTask::getTaskObject() const
{
    return newTaskObject;
}
void newTask::on_btnDate_clicked()
{
    duedate due;
    due.setModal(true);
    due.exec();
    ui->Date->setText(due.sharedDate.toString());
}


void newTask::on_btnprio_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);  // Marking arg1 as unused to avoid the warning
    ui->btnprio->setMaximum(5);
}


void newTask::on_btnOK_clicked()
{
    QString taskDescription = ui->btnTask->text();
    int taskPriority = ui->btnprio->value();
    QString taskDate = ui->Date->text();
    Priority taskPriorityEnum = static_cast<Priority>(taskPriority);
    newTaskObject = Task(taskDescription, taskDate, taskPriorityEnum);
    Tasks.insertH(linkedListRef.insertLL(newTaskObject));

    QMessageBox::warning(this, "Success", "Your task has been successfully saved.");
    close();
}

void newTask::on_pushButton_3_clicked()
{
    close();
}

