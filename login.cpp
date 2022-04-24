#include "login.h"
#include "ui_login.h"
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QDate>
#include <QDateEdit>
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

QString username;

int login::on_logbut_clicked()
{

    if (!mydb.open()){
        qDebug()<<"Db problem";
    } else {
        qDebug()<< "Success";

    }

    username = ui->username->text();
    QString password = ui->password->text();
    QSqlQuery qry;

    if(qry.exec("select * from USER where username = '"+username+"' and password = '"+password+"'")){
        int count=0;
        while(qry.next()){
            count++;
            QString a = qry.value(0).toString();
            id2 = a.toInt();
            qDebug()<< id2;

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
            qry.clear();
            mydb.close();
        } else {
            qDebug()<< "Uhm ok";
            qry.clear();
            mydb.close();
        }
         return id2;
    }


}



void login::on_pushButton_clicked()
{

    //s = new sign(this);
    //s->show();
    ui->stackedWidget->setCurrentIndex(1);
}


int login::on_signbut_clicked()
{
    QString uId = ui->user_id->text();
    id = uId.toInt();
    QString ue = ui->uname->text();
    QString password = ui->pass->text();
    QString fullname = ui->fulln->text();
    QDate dateOfBirth = ui->dob->date();
    QString s = dateOfBirth.toString("yyyy-MM-dd");
    qDebug()<<s;

    mydb = QSqlDatabase::database();

    if(!mydb.open()){
        qDebug()<<"Not connected";
    }
    else{
        qDebug()<<"connected";
        qDebug()<<id;
        QSqlQuery query;
        query.prepare("INSERT INTO User(user_id,username,password,fullname,DOB) VALUES (:u,:username,:password,:fullname,:DOB)");

        query.bindValue(":u",id);
        query.bindValue(":username",ue);
        query.bindValue(":password",password);
        query.bindValue(":fullname",fullname);
        query.bindValue(":DOB",s);

        if (!query.exec()){
            qDebug()<<"Not ok";
            ui->uname->clear();
             ui->pass->clear();
             ui->fulln->clear();
              query.clear();
               mydb.close();

}else{
             qDebug()<< "Ok";
            ui->stackedWidget->setCurrentIndex(5);
              query.clear();
               mydb.close();
        }




}

return id;
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
{/*
    QString periodid = ui->userN->text();
    int periodID = periodid.toInt();
    qDebug()<<periodID;*/

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
    query.prepare("INSERT INTO periodData(period_Id,lastPeriod,cycleLength,periodLength) VALUES (:p,:lastPeriod,:cycleLength,:periodLength)");

    query.bindValue(":p",id);
    query.bindValue(":lastPeriod",lp);
    query.bindValue(":cycleLength",cycleLength);
    query.bindValue(":periodLength",periodLength);

    if (query.exec()){
     qDebug()<< "Okayyyyy";
     //hide();
      ui->stackedWidget->setCurrentIndex(0);
    query.clear();
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
     ui->stackedWidget->setCurrentIndex(3);

}


void login::on_logPeriodbut_clicked()
{

    ui->stackedWidget->setCurrentIndex(2);

        mydb = QSqlDatabase::database();
     if(!mydb.open()){
        qDebug()<<"Not connected";
     }

        QDate lastp = ui->logPeriodbut_2->date();
        QDate x=lastp.addDays(28);
       // QDate x=lastp.addDays(cycleLength);

        QDate curr = QDate::currentDate();
        int minus= curr.daysTo(x);

        ui->prediction->setText(x.toString());
        ui->predictionMessage->setText(QString::number(minus) +" "+QString("Days remaining"));




      QDate logperiod = ui->logPeriodbut_2->date();
      QString g = logperiod.toString("yyyy-MM-dd");



      mydb = QSqlDatabase::database();
   if(!mydb.open()){
      qDebug()<<"Not connected";}
   QSqlQuery qre;

    qDebug()<< id2;
   qre.prepare("UPDATE periodData SET lastPeriod = :a WHERE period_Id = :asd ");
   qre.bindValue(":asd",id2);
   qre.bindValue(":a", g);
               if(qre.exec()){
                   qDebug()<< "Done";
                   qre.clear();
}
                         else{
                           qDebug() << "Update failed";
               qre.clear();
                       }

   mydb.close();


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


void login::on_pred_clicked()

    {

        mydb = QSqlDatabase::database();
        if(!mydb.open()){
        qDebug()<<"Not connected";
        }
             QSqlQuery qrr;
            qDebug()<<id2;


             if(qrr.exec("SELECT lastPeriod FROM periodData WHERE period_Id = :dd ")){
             qrr.bindValue(":dd",id2);
                qDebug()<<"noprob";
            while(qrr.next()){
             QString n = qrr.value(0).toString();
             qDebug()<<n;}}
//             //QDate next = n.toDate();
             //QDate nextP = QDate::fromString(n);
//             //QDate next = n.to();
 qrr.clear();

}
//             //int cycle = qrr.value(2).toInt();
//            // qDebug()<<cycle;






        //QDate lastp = ui->logPeriodbut_2->date();
//        QDate x=nextP.addDays(cycle);


//        QDate curr = QDate::currentDate();
//        int minus= curr.daysTo(x);

//        ui->prediction->setText(x.toString());
//        ui->predictionMessage->setText(QString::number(minus) +" "+QString("Days remaining"));






