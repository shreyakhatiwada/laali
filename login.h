#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:

    QSqlDatabase mydb;
    login(QWidget *parent = nullptr);
    ~login();

    QString username,password,fullname,now;
    int id,cycle,minus;
    QDate x,nextOvu;

public slots:
    void data(){
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/Dell/Desktop/db/mydb.db");

    };
private slots:
    int on_logbut_clicked();


    int on_signbut_clicked();

    void on_questionbut_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();


    void on_log_period_2_clicked();

    void on_logPeriodbut_clicked();

    void on_pred_clicked();


    void on_insightbut_clicked();

    void on_signupbut_clicked();

    void on_existingaccount_clicked();

private:
    Ui::login *ui;
};
#endif // LOGIN_H
