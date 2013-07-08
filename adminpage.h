#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QWidget>
#include "defaultup.h"
#include<QMainWindow>
#include<QPainter>
#include<QImage>
#include<QDebug>
#include <adminmoneychange.h>
#include<percent.h>


namespace Ui {
class AdminPage;
}

class AdminPage : public QWidget
{
    Q_OBJECT
    
public:
    explicit AdminPage(QWidget *parent = 0);
    QMainWindow *mainW;

    DefaultUP * D1;
    AdminMoneyChange * AMP;
    Percent * percentPage;



    QPainter p;
    QImage bg;

    ~AdminPage();
    void paintEvent(QPaintEvent *);
    void setMain(QMainWindow *m);
    
private slots:
    void on_pushButton_clicked();
  void on_DefaultUPBottun_clicked();


  void on_exit_clicked();

  void on_moneyBottun_clicked();

private:
    Ui::AdminPage *ui;
};

#endif // ADMINPAGE_H
