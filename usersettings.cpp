#include "usersettings.h"
#include "ui_usersettings.h"
#include<QMainWindow>
#include<foodreserve.h>

UserSettings::UserSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserSettings)
{
    ui->setupUi(this);
    CI=new ChangeInfo;
    IM=new IncMoney;
    H= new History;


    bool flag=bg.load("E:/blue lines.png");
    qDebug()<<flag;

}

UserSettings::~UserSettings()
{
    delete ui;
}

void UserSettings::setMain(QMainWindow *m2)
{
    this->mainW2 = m2 ;

}

void UserSettings::on_change_clicked()
{

   // this->hide();
   CI->show();

}

void UserSettings::paintEvent(QPaintEvent *)
{
    p.begin(this);
    p.drawImage(QRect(0,0,550,550),bg);
    p.end();
}

void UserSettings::on_money_clicked()
{
    IM->show();
}

void UserSettings::on_history_clicked()
{
    H->show();
}
