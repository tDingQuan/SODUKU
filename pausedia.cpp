#include "pausedia.h"
#include "ui_pausedia.h"
#include "helptxt.h"

pauseDia::pauseDia(playScr * link,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pauseDia)
{
    this->link=link;  //父界面指针初始化
    this->setWindowFlag(Qt::FramelessWindowHint);  //暂停界面设定无边框
    ui->setupUi(this);
    connect(ui->exitTxt,&QPushButton::clicked,this,&pauseDia::on_quit_clicked);
    connect(ui->goBackTxt,&QPushButton::clicked,this,&pauseDia::on_goBack_clicked);
    connect(ui->referText,&QPushButton::clicked,this,&pauseDia::on_referrence_clicked);
    connect(ui->restartTxt,&QPushButton::clicked,this,&pauseDia::on_restart_clicked);
    //四个按钮的connection的声明
}

pauseDia::~pauseDia()
{
    delete ui;
}

void pauseDia::on_quit_clicked()  //退出游戏的槽，所有界面全都关闭
{
    this->close();
    link->close();
}

void pauseDia::on_restart_clicked()  //重新开始的槽，进入结算界面，计时器暂停，游戏界面和暂停界面关闭
{
    this->close();
    finalDia * final = new finalDia(link);
    link->timer->stop();
    final->setWindowFlag(Qt::FramelessWindowHint);
    final->show();
    link->close();
}

void pauseDia::on_goBack_clicked()  //继续游戏的槽，关闭暂停界面，重启计时器，打开游戏界面并设置透明度为最低
{
    this->close();
    link->setWindowOpacity(1);
    link->show();
    link->timer->start();
}

void pauseDia::on_referrence_clicked()  //查看游戏规则的槽
{
    helpTxt * txt = new helpTxt;
    txt->setWindowFlag(Qt::FramelessWindowHint);
    txt->show();
}
