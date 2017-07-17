#include "loginscr.h"
#include "regist.h"
#include "ui_loginscr.h"

loginScr::loginScr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginScr)
{
    ui->setupUi(this);
}

loginScr::~loginScr()
{
    delete ui;
}

void loginScr::on_pushButton_clicked()
{
    reg = new regist;  //新建注册界面
    reg->show();  //注册界面显示
}
