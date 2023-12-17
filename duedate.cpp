#include "duedate.h"
#include "ui_duedate.h"

duedate::duedate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::duedate)
{
    ui->setupUi(this);
    ui->calendarWidget->setMinimumDate(QDate::currentDate());
}

duedate::~duedate()
{
    delete ui;
}
void duedate::setSharedDate(const QDate &date)
{
    sharedDate = date;
}
void duedate::on_calendarWidget_activated(const QDate &date)
{
    setSharedDate(date);
    close();
}

