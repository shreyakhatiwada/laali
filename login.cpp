#include "login.h"
#include "ui_login.h"
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

login::~login()
{
    delete ui;
}


QString login::on_logbut_clicked()
{

    if (!mydb.open()){
        qDebug()<<"Db problem";
    } else {
        qDebug()<< "Success";

    }

    QString username = ui->username->text();
    QString password = ui->password->text();
    QSqlQuery qry;

    if(qry.exec("select * from USER where username = '"+username+"' and password = '"+password+"'")){
        int count=0;
        while(qry.next()){
            count++;
        }
        if (count==1){
            qDebug()<< "Successful login";
            qry.clear();
            mydb.close();

            ui->stackedWidget->setCurrentIndex(2);
        }
        else if (count<1){
            qDebug()<< "Username and Password does not exist.";
            ui->textdis->setText("Username and Password not found");
            qry.clear();
            mydb.close();
        } else if(count>1){
            qDebug() << "Bad";
        } else {
            qDebug()<< "Uhm ok";
        }

    }
return username;
//return username;
}


void login::on_pushButton_clicked()
{
 //s = new sign(this);
 //s->show();
 ui->stackedWidget->setCurrentIndex(1);
}


QString login::on_signbut_clicked()
{

        username = ui->uname->text();
         password = ui->pass->text();
         fullname = ui->fulln->text();
         QDate dateOfBirth = ui->dob->date();
        QString s = dateOfBirth.toString("yyyy-MM-dd");
        qDebug()<<s;

         mydb = QSqlDatabase::database();

        if(!mydb.open()){
            qDebug()<<"Not connected";
        }
        else{
            qDebug()<<"connected";

        QSqlQuery query;
        query.prepare("INSERT INTO User(username,password,fullname,DOB) VALUES (:username,:password,:fullname,:DOB)");


        query.bindValue(":username",username);
        query.bindValue(":password",password);
        query.bindValue(":fullname",fullname);
        query.bindValue(":DOB",s);

        if (!query.exec()){
            QMessageBox msgBox;
            msgBox.setText("Username taken.");
            msgBox.exec();
            ui->uname->clear();
             ui->pass->clear();
             ui->fulln->clear();
         qDebug()<< "notOk";
}else{
             qDebug()<< "Ok";
            ui->stackedWidget->setCurrentIndex(5);
        } query.clear();

}

mydb.close();
return username;
}

void login::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void login::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void login::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void login::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void login::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void login::on_questionbut_clicked()
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


    query.bindValue(":lastPeriod",lp);
    query.bindValue(":cycleLength",cycleLength);
    query.bindValue(":periodLength",periodLength);

    if (query.exec()){
     qDebug()<< "Okayyyyy";
     //hide();
      ui->stackedWidget->setCurrentIndex(2);

}
mydb.close();



}


void login::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void login::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void login::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void login::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void login::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void login::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void login::on_pushButton_14_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}




void login::on_log_period_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
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
        ui->predictionMessage->setText(QString::number(minus) +" "+QString("Days remaining"));

    }
}


void login::on_logPeriodbut_clicked()
{
      QDate logperiod = ui->logPeriodbut_2->date();
      QString g = logperiod.toString("yyyy-MM-dd");



      mydb = QSqlDatabase::database();
   if(!mydb.open()){
      qDebug()<<"Not connected";}

   QSqlQuery qr;
   if(qr.exec("select * from User where username = '"+username+"' ")){
      int b=0;
       while(qr.next()){
           b++;
       }
       if (b==1){
           qr.prepare("SELECT lastPeriod FROM periodData ");
               if(qr.prepare("UPDATE periodData SET lastPeriod = :a ")){
                   qr.bindValue(":a", g);
                   qr.clear();

                         if (qr.exec())
                           qDebug() << "Woohoo!";
                         else
                           qDebug() << "Update failed";
                       }
                       else
                         qDebug() << "Your SQL is broken";
          }
       else if (b<1 ) {
           qDebug() << "bhayena";}
       else if(b>1){qDebug()<<"no";}
       else {qDebug()<<"la herum";}




   mydb.close();
}
}
//   if(qr.prepare("UPDATE periodData SET lastPeriod = :a")){
//       qr.bindValue(":a", g);
//             if (qr.exec())
//               qDebug() << "Woohoo!";
//             else
//               qDebug() << "Update failed";
//           }
//           else
//             qDebug() << "Your SQL is broken";


//};

