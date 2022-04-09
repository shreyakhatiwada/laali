#include "questions.h"
#include "ui_questions.h"
#include "todaypage.h"
#include "mainwindow.h"
#include <qmessagebox.h>

questions::questions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::questions)
{
    ui->setupUi(this);
    menstrualcycle=0;
    lengthOfperiod=0;
    MainWindow conn;
    if(!conn.connOpen())
        ui->label_sec_status->setText("Failed to open database");
    else
         ui->label_sec_status->setText("Connected...");

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
 MainWindow conn;
 lastperiodDate=ui->dateEdit->date();
 menstrualcycle= ui->lineEdit_2->text().toInt();
 lengthOfperiod=ui->lineEdit->text().toInt();
 age=ui->lineEdit_3->text().toInt();

 if(!conn.connOpen())
 {
     qDebug()<<("Failed to open database");
     return;
 }

 conn.connOpen();
 QSqlQuery qry;
 qry.prepare("insert into UserInfo ("
             "lastPeriodDate,"
             "lengthOfPeriod,"
             "MenstrualCycle)"
             "values (?,?,?)");
 qry.addBindValue(lastperiodDate);
 qry.addBindValue(menstrualcycle);
 qry.addBindValue(lengthOfperiod);

 if(qry.exec( ))
  {
 QMessageBox::critical(this,tr ("Thank you!"), tr ("Your information has been recorded sucessfully. Press enter to continue."));
 conn.connClose();
 }
 else
      QMessageBox::critical(this,tr("ERROR!"), qry.lastError().text());
}
