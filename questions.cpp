#include "questions.h"
#include "ui_questions.h"
#include "todaypage.h"
#include "mainwindow.h"


questions::questions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::questions)
{
    ui->setupUi(this);

     menstrualCycle=0;
     lengthOfPeriod=0;
}

questions::~questions()
{
    delete ui;
}

void questions::on_pushButton_clicked()
{
    todaypage obj;
    obj.setModal(true);
    obj.exec();
}


void questions::on_pushButton_2_clicked()
{

lastPeriodDate=ui->dateEdit->date();
 menstrualCycle= ui->lineEdit_2->text().toInt();
 lengthOfPeriod=ui->lineEdit->text().toInt();
 age=ui->lineEdit_3->text().toInt();















}

