#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QFileInfo>

namespace Ui {class signup;}

class signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
