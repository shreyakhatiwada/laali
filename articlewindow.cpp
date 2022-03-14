#include "articlewindow.h"
#include "ui_articlewindow.h"

articleWindow::articleWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::articleWindow)
{
    ui->setupUi(this);
}

articleWindow::~articleWindow()
{
    delete ui;
}
