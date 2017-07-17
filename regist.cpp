#include "regist.h"
#include "ui_regist.h"

regist::regist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regist)
{
    ui->setupUi(this);
    max_id=0;
}

regist::~regist()
{
    delete ui;
}

void regist::on_pushButton_clicked()
{
    //bool nameFlag = false;
    bool passwordFlag = false;
    //int newID = max_id + 1;
    QString newPassword = NULL;
    QString newName = NULL;  //初始化用户名和密码
    if(ui->pass1->text()==ui->pass2->text())  //检验两次密码输入是否相同
    {
        newPassword = ui->pass1->text();
        passwordFlag = true;
    }
    else
    {
        qDebug()<<"password wrong";  //输出密码错误指令，debug用
        passwordFlag = false;
    }
}
