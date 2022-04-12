#include "login.h"
#include "todaypage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login l;
    l.data();
    l.show();
    return a.exec();
}
