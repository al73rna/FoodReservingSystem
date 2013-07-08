#include "history.h"
#include "ui_history.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
History::History(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
     bg.load("E:/orange lines.png");
}

History::~History()
{
    delete ui;
}

void History::paintEvent(QPaintEvent *)
{
    p.begin(this);
    p.drawImage(QRect(0,0,550,550),bg);
    p.end();
}

void History::on_pushButton_clicked()
{
    QFile Current("CurrentUSer.txt");
    Current.open(QIODevice::ReadWrite | QIODevice::Text);

    QTextStream Current_file(&Current);
    QString CurrentUser= Current_file.readLine();

    Current.close();

    QFile members;
    members.setFileName(CurrentUser);
     members.open(QIODevice::ReadWrite | QIODevice::Text);

      QTextStream members_file(&members);

      QString str= members_file.readAll();

      int index=0;
      int size=str.size();
      qDebug()<<"size is"<<size;
      int times=0;

      for(int i=0;i<size;i++)
      {
          if(str[i]=='&')
          {
              index=i;
              times++;
             int count=0;
              for(int j=0;j<index;j++)
              {   if(str[j]=='\n')
                      count++;

              }
              members_file.seek(index+count);
              if(times==1)
                 ui->label->setText(members_file.readLine());
              else if(times==2)
                  ui->label_2->setText(members_file.readLine());
              else if(times==3)
                  ui->label_3->setText(members_file.readLine());
              else if(times==4)
                  ui->label_4->setText(members_file.readLine());

              else if(times==5)
                  ui->label_5->setText(members_file.readLine());

              else if(times==6)
                  ui->label_6->setText(members_file.readLine());

              else if(times==7)
                  ui->label_7->setText(members_file.readLine());

              else if(times==8)
                  ui->label_8->setText(members_file.readLine());

              else if(times==9)
                  ui->label_9->setText(members_file.readLine());

              else if(times==10)
                  ui->label_10->setText(members_file.readLine());



              qDebug()<<"count is"<<count;

          }
      }

      qDebug()<<"in history";
}
