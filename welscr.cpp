#include "welscr.h"
#include "ui_welscr.h"
#include "playscr.h"
#include "ui_playscr.h"
#include "ui_diffdia.h"
#include "helptxt.h"
#include "loginscr.h"
/*头文件组成包含欢迎界面、游戏界面、帮助界面、登录界面、难度界面的ui文件*/

welScr::welScr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::welScr)
{
    ui->setupUi(this);
    setIcon();//设置文字与槽
}

welScr::~welScr()
{
    delete ui;
}


void welScr::setIcon()//欢迎界面的文字与各个按钮和槽的connection
{
    QFont font("华康少女文字W5(P)",35);

    startTxt = new QLabel(tr("开始游戏"),this);
    startTxt->setFont(font);
    startTxt->setGeometry(270,430,250,150);
    startBtn = ui->startBtn;
    connect(startBtn,&QPushButton::clicked,this,&welScr::diffScreen);

    referTxt = new QLabel(tr("帮助索引"),this);
    referTxt->setFont(font);
    referTxt->setGeometry(270,540,250,150);
    referBtn = ui->referBtn;

    quitTxt = new QLabel(tr("好好学习"),this);
    quitTxt->setFont(font);
    quitTxt->setGeometry(270,650,250,150);
    quitBtn = ui->quitBtn;
    connect(quitBtn,&QPushButton::clicked,this,&welScr::exitGame);
}

void welScr::exitGame()//退出游戏的槽函数
{
    this->close();
}

void welScr::diffScreen()//难度界面的槽函数
{
    diff = new diffDia(this,this);
    diff->show();
}

void welScr::on_referBtn_clicked()//游戏规则界面的槽函数
{
    helpTxt * txt = new helpTxt();
    txt->setWindowFlag(Qt::FramelessWindowHint);
    txt->show();
}

void welScr::on_pushButton_clicked()//登录界面的槽函数（未完善）
{
    login = new loginScr;
    login->show();
}
