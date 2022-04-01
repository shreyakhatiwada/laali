#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "questions.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mydatabase=QSqlDatabase::addDatabase("QSQLITE");
    mydatabase.setDatabaseName("C:/Users/acer/Desktop/database/mydb.db");
    if(!mydatabase.open())
        ui->label_3->setText("Failed to open database");
    else
         ui->label_3->setText("Connected...");

}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow:: connOpen(){
    mydatabase=QSqlDatabase::addDatabase("QSQLITE");
    mydatabase.setDatabaseName("C:/Users/acer/Desktop/database/mydb.db");
    if(!mydatabase.open()){
        qDebug()<<"Failed to open database";
    return false;}
    else{
         qDebug()<<"Connected...";
         return true;}

}
void connClose(){
    QSqlDatabase mydatabase;
    mydatabase.close();
    mydatabase.removeDatabase(QSqlDatabase::defaultConnection);
}


void MainWindow::on_pushButton_clicked()
{

   QString username,password;
   username=ui->lineEdit->text();
   password=ui->lineEdit_2->text();
   if(!mydatabase.open()){
       qDebug()<<"failed to connect";
   }
   QSqlQuery qry;


   if(qry.exec("SELECT * FROM UserInfo WHERE Username='"+username+"' and Password='"+password+"'"))
    {
       int count=0;
       while(qry.next()){
           count++;
       }
      if(count==1){
      ui->label_4->setText("Username and paassword is correct.");
      this->hide();
      questions obj;
      obj.setModal(true);
      obj.exec();}



      if(count>1)
      ui->label_4->setText("Username and password duplicated");
      if(count<1)
      ui->label_4->setText("Usename and password is incorrect");
   }

   mydatabase.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString Username,Password;
    Username=ui->lineEdit->text();
    Password=ui->lineEdit_2->text();
   if(connOpen()){
    QSqlQuery qry;
    qry.exec("insert into UserInfo (Username,Password) values('"+Username+"','"+Password+"')");

                ui->label_4->setText("Sign-in successful...");
                this->hide();
                questions obj;
                obj.setModal(true);
                obj.exec();
    }

   else
   ui->label_4->setText("Sign-in not successful.");
   mydatabase.close();

 }

































