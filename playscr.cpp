#include "playscr.h"
#include "ui_playscr.h"
#include "helptxt.h"

playScr::playScr(int diff,QWidget *parent) :
    QDialog(parent),diffsavenum(diff),
    ui(new Ui::playScr)
{
    ui->setupUi(this);
    configuration(diff);  //配置函数
    calculate();  //生成数独
    draw();  //绘制图像
    time=0;  //计时器归零
}

playScr::~playScr()
{
    delete ui;
}

void playScr::mousePressEvent(QMouseEvent *event)
{

    if(event->button()==Qt::LeftButton)  //检测是否鼠标左键按下
   {
    QApplication beep();  //在前一个版本中，点击是有即时声音，但好像被背景音乐遮盖了
   qDebug()<<event->x()<<event->y()<<event->globalPos();  //输出绝对位置，前期debug用
    int y=(event->x()-160)/60+1;
    int x=(event->y()-160)/60+1;  //计算相对坐标
    if((x>0&&x<10)&&(y>0&&y<10))  //判断点击事件是否发生在数独内部
   {
    qDebug()<<x<<y<<xpos<<ypos;  //输出相对坐标与前一个坐标，前期debug用
    frame[xpos][ypos]->show();  //更新数独
    frame[x][y]->show();  //更新数独
    xpos=x;  //更新鼠标坐标存储
    ypos=y;  //更新鼠标坐标存储
    }
   }
}

void playScr::keyPressEvent(QKeyEvent *event)
{
    int input;  //定义输出数字
    switch (event->key()) {
    case Qt::Key_1:input=1;break;
    case Qt::Key_2:input=2;break;
    case Qt::Key_3:input=3;break;
    case Qt::Key_4:input=4;break;
    case Qt::Key_5:input=5;break;
    case Qt::Key_6:input=6;break;
    case Qt::Key_7:input=7;break;
    case Qt::Key_8:input=8;break;
    case Qt::Key_9:input=9;break;
    case Qt::Key_0:input=-1;break;
    default:input=-2;break;  //switch语句控制键盘输入与屏幕上输出内容
    }
    qDebug()<<input<<Answer[xpos][ypos];  //输出输入内容与正确答案，前期debug用
    if(input==Answer[xpos][ypos])  //判断是否输入正确
    {
        diffnum--;  //空缺数目减少
        rightAns++;  //正确步数增加
        head->setText(tr("Cheer Up , %1   To The Final").arg(QString::number(diffnum,10)));  //更新计分器
        ui->rightAns->display(rightAns);  //更新正确步数显示
        Initial[xpos][ypos]=Answer[xpos][ypos];  //更新数独数组
        Answer[xpos][ypos]=0;  //更新答案数组
        createLabel(xpos,ypos);
        frame[xpos][ypos]->show();  //更新数独显示界面
        std::cout<<"show"<<std::endl;  //输出正确，前期debug用
        if(diffnum==0)  //判断游戏是否结束
        {
            finalDia * final = new finalDia(this);  //弹出结算界面
            this->timer->stop();  //计时器暂停
            final->setWindowFlag(Qt::FramelessWindowHint);
            final->show();  //结算界面无边框弹出
        }
    }
    else if(input!=-2&&Answer[xpos][ypos]!=0)  //如果是输入错误而不是误输入
    {
        wrongAns++;  //错误步数增加
        ui->wrongAns->display(wrongAns);  //更新错误步数显示
    }
}

void playScr::draw()
{
   frame[1][1]=ui->f11;frame[1][2]=ui->f12;frame[1][3]=ui->f13;
   frame[1][4]=ui->f14;frame[1][5]=ui->f15;frame[1][6]=ui->f16;
   frame[1][7]=ui->f17;frame[1][8]=ui->f18;frame[1][9]=ui->f19;
   frame[2][1]=ui->f21;frame[2][2]=ui->f22;frame[2][3]=ui->f23;
   frame[2][4]=ui->f24;frame[2][5]=ui->f25;frame[2][6]=ui->f26;
   frame[2][7]=ui->f27;frame[2][8]=ui->f28;frame[2][9]=ui->f29;
   frame[3][1]=ui->f31;frame[3][2]=ui->f32;frame[3][3]=ui->f33;
   frame[3][4]=ui->f34;frame[3][5]=ui->f35;frame[3][6]=ui->f36;
   frame[3][7]=ui->f37;frame[3][8]=ui->f38;frame[3][9]=ui->f39;
   frame[4][1]=ui->f41;frame[4][2]=ui->f42;frame[4][3]=ui->f43;
   frame[4][4]=ui->f44;frame[4][5]=ui->f45;frame[4][6]=ui->f46;
   frame[4][7]=ui->f47;frame[4][8]=ui->f48;frame[4][9]=ui->f49;
   frame[5][1]=ui->f51;frame[5][2]=ui->f52;frame[5][3]=ui->f53;
   frame[5][4]=ui->f54;frame[5][5]=ui->f55;frame[5][6]=ui->f56;
   frame[5][7]=ui->f57;frame[5][8]=ui->f58;frame[5][9]=ui->f59;
   frame[6][1]=ui->f61;frame[6][2]=ui->f62;frame[6][3]=ui->f63;
   frame[6][4]=ui->f64;frame[6][5]=ui->f65;frame[6][6]=ui->f66;
   frame[6][7]=ui->f67;frame[6][8]=ui->f68;frame[6][9]=ui->f69;
   frame[7][1]=ui->f71;frame[7][2]=ui->f72;frame[7][3]=ui->f73;
   frame[7][4]=ui->f74;frame[7][5]=ui->f75;frame[7][6]=ui->f76;
   frame[7][7]=ui->f77;frame[7][8]=ui->f78;frame[7][9]=ui->f79;
   frame[8][1]=ui->f81;frame[8][2]=ui->f82;frame[8][3]=ui->f83;
   frame[8][4]=ui->f84;frame[8][5]=ui->f85;frame[8][6]=ui->f86;
   frame[8][7]=ui->f87;frame[8][8]=ui->f88;frame[8][9]=ui->f89;
   frame[9][1]=ui->f91;frame[9][2]=ui->f92;frame[9][3]=ui->f93;
   frame[9][4]=ui->f94;frame[9][5]=ui->f95;frame[9][6]=ui->f96;
   frame[9][7]=ui->f97;frame[9][8]=ui->f98;frame[9][9]=ui->f99;
   //由于最后决定全部采用ui界面设计，因此这里使用了一一对应的写法
   for(int x=1;x<10;x++)
       for(int y=1;y<10;y++)
       {
           createLabel(x,y);
           frame[x][y]->show();
       }
   //产生数独界面数字显示文本
}

void playScr::createLabel(int x, int y)  //数字显示
{
    label[x][y] = new QLabel(frame[x][y]);
    if(Initial[x][y])  //如果该处非0，即可以显示
    label[x][y]->setText(QString::number(Initial[x][y],10));
    label[x][y]->setFont(font);
    label[x][y]->setAlignment(Qt::AlignCenter);
    label[x][y]->setGeometry(0,0,70,70);
    label[x][y]->show();  //显示
}

void playScr::configuration(int diff)  //配置函数
{
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&playScr::timerUpdate);
    timer->start(100);  //配置计时器，以0.1毫秒为单位计时

    xpos=1;ypos=1;  //初始化鼠标位置存储器
    wrongAns=0;rightAns=0;  //初始化步数存储器
    ui->wrongAns->display(wrongAns);
    ui->rightAns->display(rightAns);  //步数存储显示

    diffnum = diff;  //存储难度
    head = ui->head;
    head->setText(tr("Cheer Up , %1 To The Final").arg(QString::number(diffnum,10)));
    head->show();  //计分器显示

    font.setFamily("华文行楷");
    font.setPointSize(20);  //字体配置

    connect(ui->exitTxt,&QPushButton::clicked,this,&playScr::on_exit_clicked);
    connect(ui->pauseTxt,&QPushButton::clicked,this,&playScr::on_pause_clicked);
    connect(ui->restartTxt,&QPushButton::clicked,this,&playScr::on_restart_clicked);
    connect(ui->referenceTxt,&QPushButton::clicked,this,&playScr::on_reference_clicked);
    //按钮与槽函数相关联
}

void playScr::timerUpdate()
{
    time++;
    if(time%10==0)
    ui->timer->display(time/10);  //显示时间
}

void playScr::on_exit_clicked()  //关闭界面，退出游戏的槽函数
{
    this->close();
}

void playScr::on_restart_clicked()  //重开一局游戏的槽函数
{
    finalDia * final = new finalDia(this);
    this->timer->stop();
    final->setWindowFlag(Qt::FramelessWindowHint);
    final->show();
}

void playScr::on_pause_clicked()  //暂停游戏的槽函数，设置游戏界面半透明
{
    timer->stop();
    this->setWindowOpacity(0.5);
    pauseDia * pause = new pauseDia(this,this);
    pause->show();
}

void playScr::on_reference_clicked()  //查看帮助文档的槽函数
{
    helpTxt * txt = new helpTxt(this);
    txt->setWindowFlag(Qt::FramelessWindowHint);
    txt->show();
}
