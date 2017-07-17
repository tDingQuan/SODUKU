#ifndef HELPTXT_H
#define HELPTXT_H

#include <QDialog>

namespace Ui {
class helpTxt;
}

class helpTxt : public QDialog
{
    Q_OBJECT

public:
    explicit helpTxt(QWidget *parent = 0);
    ~helpTxt();

private slots:
    void on_pushButton_clicked(); //退出按钮声明

private:
    Ui::helpTxt *ui;
};

#endif // HELPTXT_H
