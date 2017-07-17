#ifndef DIFFDIA_H
#define DIFFDIA_H

#include <QDialog>
#include <QSpinBox>
#include "playscr.h"
#include "welscr.h"

namespace Ui {
class diffDia;
}

class playScr;
class welScr;
class diffDia : public QDialog
{
    Q_OBJECT

public:
    explicit diffDia(welScr *link,QWidget *parent = 0);
    ~diffDia();

private slots:
    void on_closeBtn_clicked();
    void on_level1Btn_clicked();
    void on_level2Btn_clicked();
    void on_level3Btn_clicked();
    void on_level4Btn_clicked();
    void on_level5Btn_clicked();
    void on_level6Btn_clicked();  //六种设定难度的私有槽函数
    void on_selfLevelBtn_clicked();  //自主选择难度的私有槽函数

private:
    Ui::diffDia *ui;
    playScr *scr;  //游戏界面声明
    welScr *falink;  //父界面（欢迎界面）指针
    QSpinBox * Input;  //难度选择器
};

#endif // DIFFDIA_H
