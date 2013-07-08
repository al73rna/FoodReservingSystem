#include "adminmoneychange.h"
#include "ui_adminmoneychange.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include<QDebug>
#include<qmath.h>
#include<iostream>

AdminMoneyChange::AdminMoneyChange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminMoneyChange)
{
    ui->setupUi(this);
    bg.load("E:/green lines.png");
    ui->label_4->hide();
}

AdminMoneyChange::~AdminMoneyChange()
{
    delete ui;
}

void AdminMoneyChange::on_pushButton_clicked()
{
    QString user= ui->lineEdit_1->text();
    QFile User;
    User.setFileName(user);
    User.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
    QTextStream User_stream(&User);
    User_stream.operator <<('$');
    User_stream.operator <<(ui->lineEdit_2->text());
    User_stream.operator <<('%');
    User_stream.operator <<('\n');

    User.close();

    ui->label_4->show();




}

void AdminMoneyChange::on_pushButton_2_clicked()
{

    QString user= ui->lineEdit_1->text();
    QFile User;
    User.setFileName(user);
    User.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream User_stream(&User);

    QString s = User_stream.readAll();
     int StartIndex = s.lastIndexOf('$');
     int EndIndex =s.lastIndexOf('%');

     int size=EndIndex-StartIndex -1;

     qDebug()<<"index1 is" << StartIndex;
     qDebug()<<"index2 is" << EndIndex;
     int money=0;
     int index=EndIndex-1;

     for( int i=0; i<size;i++)
     {
        static int tavan=0;
        money= money+ ((s[index]).digitValue())* (qPow(10,tavan));
         index--;
         tavan++;
     }
     qDebug()<<money;
     ui->available->setText(QString("%1").arg(money));



}
void AdminMoneyChange::paintEvent(QPaintEvent *)
{
    p.begin(this);
    p.drawImage(QRect(0,0,550,550),bg);
    p.end();
}
