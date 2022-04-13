#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <QDialog>
#include "todaypage.h"

namespace Ui {
class questions;
}

class questions : public QDialog
{
    Q_OBJECT

public:
    todaypage *t;
    QSqlDatabase mydb;
    explicit questions(QWidget *parent = nullptr);
    ~questions();

private slots:

    void on_questionbut_clicked();

private:
    Ui::questions *ui;
};

#endif // QUESTIONS_H
