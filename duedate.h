#ifndef DUEDATE_H
#define DUEDATE_H

#include <QDialog>
#include "qdatetime.h"

namespace Ui {
class duedate;
}

class duedate : public QDialog
{
    Q_OBJECT

public:
    explicit duedate(QWidget *parent = nullptr);
    ~duedate();
    void setSharedDate(const QDate &date);
    QDate sharedDate;

private slots:
    void on_calendarWidget_activated(const QDate &date);

private:
    Ui::duedate *ui;
};

#endif // DUEDATE_H
