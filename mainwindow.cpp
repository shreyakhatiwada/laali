#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calendarwindow.h"
#include "articlewindow.h"
#include <QMessageBox>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    CalendarWindow obj;
    obj.setModal(true);
    obj.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    articleWindow obj;
    obj.setModal(true);
    obj.exec();
}

