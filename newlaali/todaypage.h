#ifndef TODAYPAGE_H
#define TODAYPAGE_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class todaypage;
}

class todaypage : public QMainWindow
{
    Q_OBJECT

public:
    explicit todaypage(QWidget *parent = nullptr);
    ~todaypage();
    QSqlDatabase mydb;
   // mydb2.setDatabaseName("C:/Users/Dell/Desktop/db/p.db");


private slots:

    void on_log_period_2_clicked();

    //void on_lastdate_clicked();

private:
    Ui::todaypage *ui;
};

#endif // TODAYPAGE_H
