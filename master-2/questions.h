#ifndef QUESTIONS_H
#define QUESTIONS_H
#include <QMainWindow>
#include <QDialog>
#include <QtDebug>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QSqlError>
#include<QDate>
#include "mainwindow.h"

namespace Ui {
class questions;
}

class questions : public QDialog
{
    Q_OBJECT

public:
    MainWindow conn;
    explicit questions(QWidget *parent = nullptr);
    ~questions();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::questions *ui;
public:
    QDate lastperiodDate;
    int menstrualcycle,lengthOfperiod,age;
};

#endif // QUESTIONS_H
