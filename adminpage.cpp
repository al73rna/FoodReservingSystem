#include "adminpage.h"
#include "ui_adminpage.h"
#include "mainwindow.h"

AdminPage::AdminPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminPage)
{
    D1=new DefaultUP; // jadid
    AMP=new AdminMoneyChange;
    percentPage= new Percent;


    ui->setupUi(this);
    bool flag=bg.load("E:/purple lines.png");
    qDebug()<<flag;

    //!!D1= new DefaultUP(this); // az classe DefaultUP ke page e marbut be user ha va pass haye default ast shey misazad.
    //!!D1->hide(); // dar ebteda in safe hide ast
}

AdminPage::~AdminPage()
{
    delete ui;
}


void AdminPage::on_DefaultUPBottun_clicked()
{


    //this->hide();
   // mainW->setCentralWidget(D1);
    D1->show();
}



void AdminPage::setMain(QMainWindow *m)
{
    this->mainW = m ;
}

/*void AdminPage::on_exit_clicked()
{

    this->hide();
    mainW->setCentralWidget(mainW2);
    // MainWindow::centralWidget()->show();
}
*/

void AdminPage::paintEvent(QPaintEvent *)
{
    p.begin(this);
    p.drawImage(QRect(0,0,550,550),bg);
    p.end();
}

void AdminPage::on_moneyBottun_clicked()
{
    //this->hide();
    //mainW->setCentralWidget(AMP);
    AMP->show();
}

void AdminPage::on_pushButton_clicked()
{
    percentPage->show();
}

void AdminPage::on_exit_clicked()
{


}
