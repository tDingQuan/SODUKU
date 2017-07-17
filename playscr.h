#ifndef PLAYSCR_H
#define PLAYSCR_H

#include "welscr.h"
#include "pausedia.h"
#include "finaldia.h"

#include <QDialog>
#include <QFrame>
#include <QDebug>
#include <QLabel>
#include <QFont>
#include <QMouseEvent>
#include <QPixmap>
#include <QTime>
#include <QTimer>
#include <QPainter>
#include <QPen>  //qt头文件组

#include <iostream>
#include <algorithm>
#include <ctime>
#include <conio.h>
#include <cstdlib>  //C++头文件组

namespace Ui {
class playScr;
}

class playScr : public QDialog
{
    Q_OBJECT

public:
    friend class pauseDia;
    friend class finalDia;
    const int diffsavenum;  //难度存储器
    explicit playScr(int diff,QWidget *parent = 0);
    ~playScr();

private:
    Ui::playScr *ui;

    QFrame * frame[10][10];  //游戏方格界面 9行9列
    QLabel * label[10][10];  //数字存储器
    QLabel * head;  //游戏计分器

    QTimer * timer;  //计时器
    QFont font;  //统一字体

    int Initial[10][10];  //游戏初始数字存储数组
    int Answer[10][10];  //空数字存储数组
    int xpos,ypos;  //上一次鼠标点击位置存储
    int diffnum;  //难度存储器
    int time;  //时间存储
    int wrongAns,rightAns;  //正确、错误步数存储

private:
    void mousePressEvent(QMouseEvent * event);  //鼠标事件
    void keyPressEvent(QKeyEvent * event);  //键盘事件

    void calculate();  //生成数独函数
    void ans(int);  //随机生成空缺函数
    bool check(int x,int y);  //检测数字是否成立函数
    void draw();  //绘画函数
    void createLabel(int x,int y);  //数字显示以及改变函数
    void configuration(int diff);  //固定不变内容配置函数

private slots:
    void timerUpdate();  //计时器更新函数
    void on_exit_clicked();  //退出槽函数
    void on_restart_clicked();  //重新开始槽函数
    void on_pause_clicked();  //暂停槽函数
    void on_reference_clicked();  //规则查看槽函数
};

#endif // PLAYSCR_H
