#include "diffdia.h"
#include "ui_diffdia.h"

diffDia::diffDia(welScr * link,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::diffDia),
    falink(link)
{
    ui->setupUi(this);
    Input = ui->spinBox;
    Input->setGeometry(280,130,100,20);
    Input->setMaximum(64);
    Input->setMinimum(0);
    Input->show();
}

diffDia::~diffDia()
{
    delete ui;
}


void diffDia::on_closeBtn_clicked()
{
    this->close();
}

void diffDia::on_level1Btn_clicked()
{
    scr=new playScr(10);
    scr->showFullScreen();
    this->close();
    falink->close();
}

void diffDia::on_level2Btn_clicked()
{
    scr=new playScr(30);
    scr->showFullScreen();
    this->close();
    falink->close();
}

void diffDia::on_level3Btn_clicked()
{
    scr=new playScr(45);
    scr->showFullScreen();
    this->close();
    falink->close();
}

void diffDia::on_level4Btn_clicked()
{
    scr=new playScr(55);
    scr->showFullScreen();
    this->close();
    falink->close();
}

void diffDia::on_level5Btn_clicked()
{
    scr=new playScr(60);
    scr->showFullScreen();
    this->close();
    falink->close();
}

void diffDia::on_level6Btn_clicked()
{
    scr=new playScr(64);
    scr->showFullScreen();
    this->close();
}

void diffDia::on_selfLevelBtn_clicked()
{
    if(Input->value()!=0)
    {
        scr=new playScr(Input->value());
        scr->showFullScreen();
        this->close();
        falink->close();
    }
}
