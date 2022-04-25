#include "login.h"
#include "ui_login.h"
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

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


void login::on_logbut_clicked()
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
            hide();

            //t = new todaypage(this);
            //t->show();
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


}


void login::on_pushButton_clicked()
{
 //s = new sign(this);
 //s->show();
 ui->stackedWidget->setCurrentIndex(1);
}


void login::on_signbut_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void login::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void login::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void login::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void login::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void login::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void login::on_questionbut_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
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
    ui->stackedWidget->setCurrentIndex(5);
}

