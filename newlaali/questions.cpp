#include "questions.h"
#include "ui_questions.h"
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>

questions::questions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::questions)
{
    ui->setupUi(this);
}

questions::~questions()
{
    delete ui;
}

void questions::on_questionbut_clicked()
{

    QDate last = ui->lastPeriod->date();
    QString lp = last.toString("yyyy-MM-dd");
    qDebug()<<lp;

    QString cycleL = ui->cycleLength->text();
    int cycleLength = cycleL.toInt();
    qDebug()<<cycleLength;

    QString periodL = ui->periodLength->text();
    int periodLength = periodL.toInt();
    qDebug()<<periodLength;

    mydb = QSqlDatabase::database();

if(!mydb.open()){
    qDebug()<<"Not connected";
}
else{
    qDebug()<<"connected";

}
    QSqlQuery query;
    query.prepare("INSERT INTO periodData(lastPeriod,cycleLength,periodLength) VALUES (:lastPeriod,:cycleLength,:periodLength)");
    qDebug()<< "yes";

    query.bindValue(":lastPeriod",lp);
    query.bindValue(":cycleLength",cycleLength);
    query.bindValue(":periodLength",periodLength);

    if (query.exec()){
    // count++;
     qDebug()<< "Okayyyyy";
     hide();
}
    t = new todaypage(this);
    t->show();
}
