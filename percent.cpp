#include "percent.h"
#include "ui_percent.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>


Percent::Percent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Percent)
{
    ui->setupUi(this);
    bg.load("E:/green lines.png");
    ui->label_3->hide();
}

Percent::~Percent()
{
    delete ui;
}

void Percent::paintEvent(QPaintEvent *)
{
    p.begin(this);
    p.drawImage(QRect(0,0,400,300),bg);
    p.end();
}

void Percent::on_pushButton_clicked()
{
    QFile Current("CurrentUser.txt");
    Current.open(QIODevice::ReadWrite | QIODevice::Text| QIODevice::Append);

    QTextStream Current_stream(&Current);
    Current_stream.operator <<('\n');
    Current_stream.operator <<('$');
    Current_stream.operator <<(ui->percent->text());
    Current_stream.operator <<('%');

    Current.close();
    ui->label_3->show();




}
