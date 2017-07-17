#ifndef REGIST_H
#define REGIST_H

#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>

namespace Ui {
class regist;
}

class regist : public QDialog
{
    Q_OBJECT

public:
    explicit regist(QWidget *parent = 0);
    ~regist();
    void dboperation(); //数据库操作函数

private slots:
    void on_pushButton_clicked();  //注册完成槽

private:
    Ui::regist *ui;
    QSqlDatabase database;  //声明数据库
    bool tableFlag;
    int max_id;
};

#endif // REGIST_H
