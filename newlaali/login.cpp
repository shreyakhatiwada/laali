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
            t = new todaypage(this);
            t->show();

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
 s = new sign(this);
 s->show();
}

