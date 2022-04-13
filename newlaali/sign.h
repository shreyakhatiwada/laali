#ifndef SIGN_H
#define SIGN_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "questions.h"
namespace Ui {
class sign;
}

class sign : public QMainWindow
{
    Q_OBJECT

public:
    questions *q;
    explicit sign(QWidget *parent = nullptr);
    ~sign();
    QSqlDatabase mydb;
    QString username,password,fullname;


private slots:
    void on_signbut_clicked();

private:
    Ui::sign *ui;
};

#endif // SIGN_H
