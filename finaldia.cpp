#include "finaldia.h"
#include "ui_finaldia.h"

finalDia::finalDia(playScr *link,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finalDia)
{
    ui->setupUi(this);
    path = link;
    WrongMove=ui->WrongMove;
    RightMove=ui->RightMove;  //正确错误步数
    time=ui->Time;  //关联计时器
    difficulty=ui->Difficulty;
    WrongMove->setText(tr("WRONG MOVE : %1").arg(QString::number(path->wrongAns,10)));
    RightMove->setText(tr("RIGHT MOVE : %1").arg(QString::number(path->rightAns,10)));  //输出正确错误步数
    time->setText(tr("TIME : %1 SECONDS").arg(QString::number(path->time/10,10)));  //输出耗费时间
    difficulty->setText(tr("DIFFICULTY : %1").arg(QString::number(path->diffsavenum,10)));  //输出难度选择
    connect(ui->exitText,&QPushButton::clicked,this,&finalDia::on_exit_clicked);
    connect(ui->menuText,&QPushButton::clicked,this,&finalDia::on_menu_clicked);
    connect(ui->restartText,&QPushButton::clicked,this,&finalDia::on_restart_clicked);  //关联按钮与槽
}

finalDia::~finalDia()
{
    delete ui;
}

void finalDia::on_exit_clicked()  //退出游戏槽函数，关闭所有界面
{
    this->close();
    path->close();
}

void finalDia::on_restart_clicked()  //重新开始槽函数，重新载入游戏界面
{
    int temp= path->diffsavenum;
    this->close();
    path->close();
    playScr * scr=new playScr(temp);
    scr->showFullScreen();
}

void finalDia::on_menu_clicked()  //菜单槽函数，回到欢迎界面
{
    this->close();
    path->close();
    welScr * wel = new welScr;
    wel->showFullScreen();
}
