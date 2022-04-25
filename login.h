#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QFileInfo>
#include "todaypage.h"
#include "sign.h"
#include "questions.h"
QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    todaypage *t;
    sign *s;

    QSqlDatabase mydb;
    login(QWidget *parent = nullptr);
    ~login();
public slots:
    void data(){
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/Dell/Desktop/db/mydb.db");

    };
private slots:
    void on_logbut_clicked();

    void on_pushButton_clicked();

    void on_signbut_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_questionbut_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::login *ui;
};
#endif // LOGIN_H
