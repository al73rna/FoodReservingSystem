#include "incmoney.h"
#include "ui_incmoney.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <qmath.h>
#include <QDate>
IncMoney::IncMoney(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IncMoney)
{
    ui->setupUi(this);

    bg.load("E:/orange lines.png");
    ui->label_3->hide();

}

IncMoney::~IncMoney()
{
    delete ui;
}

void IncMoney::paintEvent(QPaintEvent *)
{
    p.begin(this);
    p.drawImage(QRect(0,0,550,550),bg);
    p.end();
}


void IncMoney::on_pushButton_clicked()
{
    QFile Current("CurrentUSer.txt");
    Current.open(QIODevice::ReadWrite | QIODevice::Text);

    QTextStream Current_file(&Current);
    QString CurrentUser= Current_file.readLine();

    Current.close();

    QFile GetIndex;
    GetIndex.setFileName(CurrentUser);
    GetIndex.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream GetIndex_stream(&GetIndex);


     QString s = GetIndex_stream.readAll();
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
      ui->pushButton->hide();
      ui->CurrentMoney->setText(QString("%1").arg(money));





}

void IncMoney::on_TransferButton_clicked()
{
    QFile Current("CurrentUSer.txt");
    Current.open(QIODevice::ReadWrite | QIODevice::Text);

    QTextStream Current_file(&Current);
    QString CurrentUser= Current_file.readLine();

    Current.close();

    QFile GetIndex;
    GetIndex.setFileName(CurrentUser);
    GetIndex.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream GetIndex_stream(&GetIndex);


     QString s = GetIndex_stream.readAll();
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


      QFile members;
      members.setFileName(CurrentUser);
       members.open(QIODevice::ReadWrite | QIODevice::Text |QIODevice::Append);

        QTextStream members_file(&members);

      int MoneyToAdd= (ui->lineEdit->text()).toInt();
      int moneyTemp=money;
      moneyTemp+=MoneyToAdd;
      members_file.operator <<("\n");
      members_file.operator <<('$');
      members_file.operator <<(moneyTemp);
      members_file.operator <<('%');
      members_file.operator <<("\n");
      members_file.operator <<('&');
      members_file.operator <<(ui->lineEdit->text());
      members_file.operator <<('-');
      members_file.operator <<(QDate::currentDate().month());
      members_file.operator <<('-');
      members_file.operator <<(QDate::currentDate().day());


      members.close();

      GetIndex.close();


      ui->label_3->show();


}
