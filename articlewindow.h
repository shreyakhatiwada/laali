#ifndef ARTICLEWINDOW_H
#define ARTICLEWINDOW_H

#include <QDialog>

namespace Ui {
class articleWindow;
}

class articleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit articleWindow(QWidget *parent = nullptr);
    ~articleWindow();

private:
    Ui::articleWindow *ui;
};

#endif // ARTICLEWINDOW_H
