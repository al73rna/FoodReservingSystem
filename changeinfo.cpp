#include "changeinfo.h"
#include "ui_changeinfo.h"
#include <QFile>
#include <QMainWindow>
#include <QString>
#include <QTextStream>


ChangeInfo::ChangeInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeInfo)
{
    ui->setupUi(this);
    ui->saved->hide();

    ui->label_4->hide();

    bg.load("E:/orange lines.png");
    //qDebug()<<flag;

}

ChangeInfo::~ChangeInfo()
{
    delete ui;
}

void ChangeInfo::on_changesdone_clicked()
{



    QFile Current("CurrentUSer.txt");
    Current.open(QIODevice::ReadWrite | QIODevice::Text);

    QTextStream Current_file(&Current);
    QString CurrentUser= Current_file.readLine();

    Current.close();

    QFile members;
    members.setFileName(CurrentUser);
    members.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
    QTextStream members_file(&members);


    // chek mikonad ke password hatman yek digit dashte bashad!
    QString pass= ui->lineEdit_3->text();
    int size= pass.size();
    bool hasDigit=false;
    for(int i=0;i<size;i++)
    {
        if( pass[i].digitValue() <10 && pass[i].digitValue()>=0)
            hasDigit=true;

    }

    if( hasDigit==false)
        ui->label_4->show();

    if( hasDigit==true)
   {
   // members_file.operator <<(ui->lineEdit_1->text());
    members_file.operator <<("\n");
    members_file.operator <<('<');
    members_file.operator <<(ui->lineEdit_2->text());
    members_file.operator <<('>');
    members_file.operator <<("\n");
    members_file.operator <<('/');
    members_file.operator <<(ui->lineEdit_3->text());
    members_file.operator <<('@');
    members_file.operator <<("\n");

     ui->label_4->hide();
     ui->saved->show();
    }

    members.close();





}
void ChangeInfo::paintEvent(QPaintEvent *)
{
    p.begin(this);
    p.drawImage(QRect(0,0,550,550),bg);
    p.end();
}

