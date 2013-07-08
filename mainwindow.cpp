#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "iostream"
#include "QFile"
#include <QTextStream>
#include "adminpage.h"
#include<QDebug>
#include <forgot.h>
#include<QDate>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    bg.load("E:/grey lines.png");

    adminp= new AdminPage;
    memberPage= new FoodReserve;
    forgotPage= new Forgot;
    adminp->setMain(this);
    memberPage->setMain(this);
    forgotPage->setMain(this);


    ui->setupUi(this);

    ui->Error->hide(); // dar ebteda peigham haye username ya password e eshtebah hide bashand.
    ui->Error2->hide();


    int year= QDate::currentDate().year();
    int month=QDate::currentDate().month();
    int day= QDate::currentDate().day();

    qDebug()<<month<<"/" <<day <<"/"<<year;
    ui->year->setText(QString("%1").arg(year));
    ui->month->setText(QString("%1").arg(month));
    ui->day->setText(QString("%1").arg(day));

    int hour= QTime::currentTime().hour();
    int minute= QTime::currentTime().minute();
    int second= QTime::currentTime().second();

     qDebug()<<hour<<"::" <<minute <<"::"<<second;

    // time ra neshan midahad vali faghat male lahzeye baz shodane safe yani sanie va min jelo nemiravad.
    ui->hour->setText(QString("%1").arg(hour));
    ui->minute->setText(QString("%1").arg(minute));
    ui->second->setText(QString("%1").arg(second));




 }


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()  // agar ruye login click kard
{
    QString ad_user, ad_pass;   // 2 ta Qstring sakhte shavad
    QFile admin_file("Admin.txt");  //yek Qfile be name Admin.txt sakhte shavad.
    admin_file.open(QIODevice::ReadWrite | QIODevice::Text);  // file e sakhte shode baz shavad.

    QTextStream admin_info(&admin_file);  // yek QTextStream sakhte shavad ke address e file be an dade mishavad.
    ad_user= admin_info.readLine();  // az ruye QtextStream khate aval va dovom khande shavad.
    ad_pass= admin_info.readLine();



    admin_file.close();;  // file baste shavad.

    // agar khate aval file ke user e admin ast ba lineEdite aval ke username ast barabar bud
    // va khate dovom ke pass e admin ast ba lineEdit 2 ke password ast barabar bud
    if( ui->lineEdit->text() == ad_user && ui->lineEdit_2->text()== ad_pass)
    {


        this->centralWidget()->hide();
        this->setCentralWidget(adminp);

    }



    //  peighm ha har kodam yek label hastand!
    // agar username name eshtebah bud peighame errore user name
         if( ui->lineEdit->text() != ad_user && ui->lineEdit_2->text()==ad_pass)
            ui->Error->show();
    // agar password eshtebah bud peighame errore pass
        else if( ui->lineEdit->text() == ad_user && ui->lineEdit_2->text()!=ad_pass)
            ui->Error->show();


           QString username= ui->lineEdit_3->text();
           QFile Files;
           Files.setFileName(username);
           Files.open(QIODevice::ReadWrite | QIODevice::Text);
           //QString UserFromFile;
           //QString PassFromFile;

           if(Files.exists())
       {
           qDebug()<<"exists";


           QTextStream files(&Files);

           QString str=files.readAll();
           int StartU= str.lastIndexOf('<');
           int EndU=str.lastIndexOf('>');
           int SizeU= EndU-StartU-1;

           int StartP=str.lastIndexOf('/');
           int EndP=str.lastIndexOf('@');
           int SizeP= EndP-StartP-1;

           QString user=ui->lineEdit->text();
           QString pass=ui->lineEdit_2->text();


           bool UserCheck=true;

           int k1=0;
           for( int i=StartU+1; i<EndU; i++)
           { if( str[i]  != user[k1])
                   UserCheck=false;
               k1++;
           }


           bool PassCheck=true;
           int k2=0;
           for( int j=StartP+1 ; j<EndP; j++)
           {
               if(str[j] != pass[k2])
                   PassCheck=false;
               k2++;
           }

           if( UserCheck==true && PassCheck==true && user.size()==SizeU && pass.size()==SizeP )
           {


               qDebug()<<"true";




               QFile Current("CurrentUser.txt");
               Current.open(QIODevice::ReadWrite | QIODevice::Text);
               QTextStream Current_file(&Current);

               // flush mikonam ke harchi az ghabl tushe pak she va usere alan tush neveshte she faghat.
               Current.flush();
               Current_file.flush();
               Current_file.operator <<(username);
               Current.close();


               this->centralWidget()->hide();

               this->setCentralWidget(memberPage);

           }
           else
                 ui->Error->show();

       }
           else if(!Files.exists())
                ui->Error2->show();


           Files.close();


}

// agar dokmeye exit click shod barname exit shavad.
void MainWindow::on_ExitButon_clicked()
{
    this->close();

}

void MainWindow::paintEvent(QPaintEvent *)
{
    p.begin(this);
    p.drawImage(QRect(0,0,550,550),bg);
    p.end();
}


void MainWindow::on_pushButton_2_clicked()
{
    // age do ta khate zir be jaye khate sevom ejra shavand safeye forgotPage yeki jadid dorost nemishavad.
    // be jaye safeye mainwindow miayad.

    //this->centralWidget()->hide();
   // this->setCentralWidget(forgotPage);
    forgotPage->show();
}
