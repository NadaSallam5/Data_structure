#ifndef NEWTASK_H
#define NEWTASK_H

#include <QDialog>
#include "linkedlist.h"
#include "ui_newtask.h"
#include "hashtable.h"

namespace Ui {
class newTask;
}

class newTask : public QDialog
{
    Q_OBJECT

public:
    explicit newTask(LinkedList& linkedList, HashTable& tasks, QWidget* parent = nullptr);
    ~newTask();
    Task getTaskObject() const;
private slots:
    void on_btnDate_clicked();

    void on_btnprio_textChanged(const QString &arg1);

    void on_btnOK_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::newTask *ui;
    LinkedList& linkedListRef;
    HashTable& Tasks;
    Task newTaskObject;
};

#endif // NEWTASK_H
