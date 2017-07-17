#ifndef FINALDIA_H
#define FINALDIA_H

#include <QDialog>
#include "playscr.h"
#include "welscr.h"

namespace Ui {
class finalDia;
}

class finalDia : public QDialog
{
    Q_OBJECT

public:
    explicit finalDia(playScr *link,QWidget *parent = 0);
    ~finalDia();

private slots:
    void on_exit_clicked();
    void on_restart_clicked();
    void on_menu_clicked();  //三个功能按钮的槽的声明

private:
    Ui::finalDia *ui;
    playScr * path;  //父界面（游戏界面）指针
    QLabel * time;
    QLabel * WrongMove;
    QLabel * RightMove;
    QLabel * difficulty;  //成绩文本显示
};

#endif // FINALDIA_H
