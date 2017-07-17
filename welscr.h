#ifndef WELSCR_H
#define WELSCR_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include "ui_diffdia.h"
#include "diffdia.h"
#include "loginscr.h"

namespace Ui {
class welScr;
}

class diffDia;//难度界面类的前置声明
class welScr : public QMainWindow
{
    Q_OBJECT

public:
    explicit welScr(QWidget *parent = 0);
    ~welScr();

private:
    Ui::welScr *ui;
    diffDia * diff;//难度界面对象指针
    loginScr * login;//登陆界面对象指针
    QPushButton * startBtn;//开始按钮
    QPushButton * referBtn;//规则按钮
    QPushButton * quitBtn;//退出按钮
    QLabel * startTxt;//开始按钮文本
    QLabel * referTxt;//规则按钮文本
    QLabel * quitTxt;//退出按钮文本

private:
    void sound();//背景音乐开启函数
    void setIcon();//设置文本文字

private slots:
    void exitGame();//退出按钮的槽
    void diffScreen();//进入难度界面的槽
    void on_referBtn_clicked();//查看游戏规则按钮的槽
    void on_pushButton_clicked();//登录界面按钮的槽
};

#endif // WELSCR_H
