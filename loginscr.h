#ifndef LOGINSCR_H
#define LOGINSCR_H

#include "regist.h"
#include <QDialog>

namespace Ui {
class loginScr;
}

class regist;
class loginScr : public QDialog
{
    Q_OBJECT

public:
    explicit loginScr(QWidget *parent = 0);
    ~loginScr();

private slots:
    void on_pushButton_clicked();  //注册界面按钮私有槽

private:
    Ui::loginScr *ui;
    regist * reg;  //登录界面
};

#endif // LOGINSCR_H
