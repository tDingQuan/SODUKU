#include "helptxt.h"
#include "ui_helptxt.h"

helpTxt::helpTxt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpTxt)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&helpTxt::on_pushButton_clicked);  //按钮与槽connection
}

helpTxt::~helpTxt()
{
    delete ui;
}

void helpTxt::on_pushButton_clicked()  //关闭界面的槽函数
{
    this->close();
}
