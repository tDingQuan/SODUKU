#ifndef PAUSEDIA_H
#define PAUSEDIA_H

#include <QDialog>
#include "playscr.h"

namespace Ui {
class pauseDia;
}

class playScr;
class pauseDia : public QDialog
{
    Q_OBJECT

public:
    explicit pauseDia(playScr * link,QWidget *parent = 0);
    ~pauseDia();

private slots:
    void on_quit_clicked();
    void on_restart_clicked();
    void on_goBack_clicked();
    void on_referrence_clicked(); //界面上的四个按钮的槽函数

private:
    Ui::pauseDia *ui;
    playScr * link;  //父界面（游戏界面）的指针
};

#endif // PAUSEDIA_H
