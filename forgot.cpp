#include "forgot.h"
#include "ui_forgot.h"
#include <QFile>
#include<QTextStream>


Forgot::Forgot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Forgot)
{
    ui->setupUi(this);
     bg.load("E:/purple lines.png");
    ui->label_4->hide();
}

Forgot::~Forgot()
{
    delete ui;
}

void Forgot::on_pushButton_clicked()
{
   QString studentNum= ui->lineEdit->text();
   QString user= ui->lineEdit_2->text();
   QFile file;
   file.setFileName(studentNum);
   file.open(QIODevice::ReadWrite | QIODevice::Text);
   QTextStream file_stream(&file);
   file_stream.readLine();

   if( user==file_stream.readLine() )
   {
       ui->pass->setText(file_stream.readLine());
   }
    else
       ui->label_4->show();

   file.close();


}

void Forgot::setMain(QMainWindow *m)
{
    this->mainW = m ;
}

void Forgot::paintEvent(QPaintEvent *)
{
    p.begin(this);
    p.drawImage(QRect(0,0,550,550),bg);
    p.end();
}

