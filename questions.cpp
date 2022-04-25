#include "questions.h"
#include "ui_questions.h"
#include <QDate>
#include <QString>

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



}

