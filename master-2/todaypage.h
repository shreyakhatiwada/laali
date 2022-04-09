#ifndef TODAYPAGE_H
#define TODAYPAGE_H

#include <QDialog>

namespace Ui {
class todaypage;
}

class todaypage : public QDialog
{
    Q_OBJECT

public:
    explicit todaypage(QWidget *parent = nullptr);
    ~todaypage();

private:
    Ui::todaypage *ui;
};

#endif // TODAYPAGE_H
