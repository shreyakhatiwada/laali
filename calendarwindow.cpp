#include "calendarwindow.h"
#include "ui_calendarwindow.h"

CalendarWindow::CalendarWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalendarWindow)
{
    ui->setupUi(this);
}

CalendarWindow::~CalendarWindow()
{
    delete ui;
}
