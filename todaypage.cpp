#include "todaypage.h"
#include "ui_todaypage.h"
#include <QDebug>
#include <QString>
#include <QDateEdit>
#include <QDateTime>
//#include <QSqlDatabase>
//#include <QtSql>

todaypage::todaypage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::todaypage)
{
    ui->setupUi(this);
    qDebug()<< "shre";
}

todaypage::~todaypage()
{
    delete ui;
}





/*void todaypage::on_lastdate_clicked()
{

    QDate i = ui->last_period->date();
   QString h = i.toString("yyyy-MM-dd");

   qDebug()<<h;
       mydb = QSqlDatabase::database();
    if(!mydb.open()){
       qDebug()<<"Not connected";
    }

    QSqlQuery query;
    query.prepare("insert INTO User(lastper)" "VALUES (:lastper)");
    query.bindValue(":lastper",h);


    QDate sum=ui->last_period->date();
    QDate y=sum.addDays(28);

    QDate tod = QDate::currentDate();
    int diff= tod.daysTo(y);

    ui->prediction->setText(y.toString());
    ui->predictioMessage->setText(QString::number(diff) +" "+  QString("Days remaining"));
    if (query.exec()){
    // count++;
     qDebug()<< "yes";
     hide();
}
     mydb.close();
}*/

void todaypage::on_log_period_2_clicked()
{
    mydb = QSqlDatabase::database();
 if(!mydb.open()){
    qDebug()<<"Not connected";
 }
    QDate lastp = ui->logdate->date();
    QDate x=lastp.addDays(28);
   // QDate x=lastp.addDays(cycleLength);

    QDate curr = QDate::currentDate();
    int minus= curr.daysTo(x);

    ui->prediction->setText(x.toString());
    ui->predictioMessage->setText(QString::number(minus) +" "+QString("Days remaining"));

}





