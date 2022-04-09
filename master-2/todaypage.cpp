#include "todaypage.h"
#include "ui_todaypage.h"

todaypage::todaypage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::todaypage)
{
    ui->setupUi(this);
}

todaypage::~todaypage()
{
    delete ui;
}
