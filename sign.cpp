#include "sign.h"
#include "ui_sign.h"
#include <QtSql>
#include <QDate>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>

sign::sign(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign)
{
    ui->setupUi(this);
}

sign::~sign()
{
    delete ui;
}


//void sign::on_signbut_clicked()
//{
//    username = ui->uname->text();
//     password = ui->pass->text();
//     fullname = ui->fulln->text();
//     QDate dateOfBirth = ui->dob->date();
//    QString s = dateOfBirth.toString("yyyy-MM-dd");
//    qDebug()<<s;

//        mydb = QSqlDatabase::database();

//    if(!mydb.open()){
//        qDebug()<<"Not connected";
//    }
//    else{
//        qDebug()<<"connected";

//    QSqlQuery query;
//    query.prepare("INSERT INTO User(username,password,fullname,DOB) VALUES (:username,:password,:fullname,:DOB)");
//    qDebug()<< "yes";

//    query.bindValue(":username",username);
//    query.bindValue(":password",password);
//    query.bindValue(":fullname",fullname);
//    query.bindValue(":DOB",s);

//    if (query.exec()){
//    // count++;
//     qDebug()<< "Ok";
//     hide();


//}
//}
//}
