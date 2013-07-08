#include "foodreserve.h"
#include "ui_foodreserve.h"
#include <QFile>
#include <QDebug>
#include <usersettings.h>
#include<QChar>
#include<qmath.h>
#include <QDate>

FoodReserve::FoodReserve(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FoodReserve)
{

    //userPage=new UserSettings; // jadid
    ui->setupUi(this);
    userInfo=new UserSettings; // jadid
    bool flag=bg.load("E:/green lines.png");
    qDebug()<<flag;
    ui->errorLable->hide();
    userInfo ->setMain( this->mainW2 );

    ui->MojudiLable->hide();

    int year= QDate::currentDate().year();
    int month=QDate::currentDate().month();
    int day= QDate::currentDate().day();
    qDebug()<<month<<"/" <<day <<"/"<<year;
    ui->y->setText(QString("%1").arg(year));
    ui->m->setText(QString("%1").arg(month));
    ui->d->setText(QString("%1").arg(day));


    ui->label_30->hide();
    ui->label_31->hide();
    ui->label_32->hide();
    ui->label_33->hide();
    ui->label_34->hide();
    ui->label_35->hide();

    if( day== ui->label_10->text().toInt()&& month==ui->label_8->text().toInt() )
        ui->label_30->show();

    if( day== ui->label_12->text().toInt() && month==ui->label_11->text().toInt())
        ui->label_31->show();

    if( day== ui->label_14->text().toInt() && month==ui->label_13->text().toInt())
        ui->label_32->show();

    if( day== ui->label_17->text().toInt()&& month==ui->label_16->text().toInt())
        ui->label_33->show();

    if( day== ui->label_19->text().toInt()&& month==ui->label_18->text().toInt())
        ui->label_34->show();

    if( day== ui->label_21->text().toInt()&& month==ui->label_20->text().toInt())
        ui->label_35->show();

    QFile Current("CurrentUSer.txt");
    Current.open(QIODevice::ReadWrite | QIODevice::Text);

    QTextStream Current_stream(&Current);

    QString s = Current_stream.readAll();
     int StartIndex = s.lastIndexOf('$');
     int EndIndex =s.lastIndexOf('%');

     int size=EndIndex-StartIndex -1;

     qDebug()<<"index1 is" << StartIndex;
     qDebug()<<"index2 is" << EndIndex;
     int p=0;
     int index=EndIndex-1;

     for( int i=0; i<size;i++)
     {
        static int tavan=0;
        p= p+ ((s[index]).digitValue())* (qPow(10,tavan));
         index--;
         tavan++;
     }
     qDebug()<<"p is"<<p;
     ui->perc->setText(QString("%1").arg(p));


}

void FoodReserve::on_Settings_clicked()
{
    qDebug()<<"i am in hide";

    this->hide();
    mainW2->setCentralWidget(userInfo);


}


void FoodReserve::setMain(QMainWindow *m2)
{
    this->mainW2 = m2 ;
}





FoodReserve::~FoodReserve()
{
    delete ui;
}

void FoodReserve::on_Submit_clicked()
{

    bool CanBuy=true;

    if(ui->checkBox_1->isChecked())
    {
        QFile Current("CurrentUSer.txt");
        Current.open(QIODevice::ReadWrite | QIODevice::Text);

        QTextStream Current_file(&Current);
        QString CurrentUser= Current_file.readLine();

        Current.close();

        QFile members;
        members.setFileName(CurrentUser);
         members.open(QIODevice::ReadWrite | QIODevice::Text |QIODevice::Append);

          QTextStream members_file(&members);

          members_file.operator <<(ui->comboBox_1->currentText()) ;
          members_file.operator <<("\n");
          members_file.operator << (ui->comboBox_7->currentText());
          members_file.operator <<("\n");
          members_file.operator <<(ui->label_2->text());
          members_file.operator <<("\n");




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

         int moneyTemp=money;

         // kam kardane hazineye ghazaye reserve shode az kole mojudi
         if(ui->label_30->isHidden()==false)
         {
             qDebug()<<"here in if";
             int RealPrice=(((ui->perc->text().toInt())*(0.01))+1) * (ui->label_2->text().toInt());
             qDebug()<<RealPrice;
             moneyTemp -= RealPrice;
         }
         else if( ui->label_30->isHidden()==true)
         {
             moneyTemp -=( ui->label_2->text()).toInt();
         }




          qDebug()<<moneyTemp;
          if(moneyTemp <= 0)
             {
              CanBuy=false;
              ui->errorLable->show();
             }



        // write kardane mojudie jadid dar file
        if(CanBuy==true)
        {
            members_file.operator <<('$');
            members_file.operator <<(moneyTemp);
            members_file.operator <<('%');
            members_file.operator <<('\n');
        }




          GetIndex.close();


          members.close();


    }

    if(ui->checkBox_2->isChecked())
    {
        QFile Current("CurrentUSer.txt");
        Current.open(QIODevice::ReadWrite | QIODevice::Text);

        QTextStream Current_file(&Current);
        QString CurrentUser= Current_file.readLine();

        Current.close();

        QFile members;
        members.setFileName(CurrentUser);
         members.open(QIODevice::ReadWrite | QIODevice::Text |QIODevice::Append);

         QTextStream members_file(&members);

          members_file.operator <<(ui->comboBox_2->currentText()) ;
          members_file.operator <<("\n");
          members_file.operator << (ui->comboBox_8->currentText());
          members_file.operator <<("\n");
          members_file.operator <<(ui->label_3->text());
          members_file.operator <<("\n");


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

           int moneyTemp=money;

           // kam kardane hazineye ghazaye reserve shode az kole mojudi
           if(ui->label_31->isHidden()==false)
           {
               qDebug()<<"here in if";
               int RealPrice=(((ui->perc->text().toInt())*(0.01))+1) * (ui->label_3->text().toInt());
               qDebug()<<RealPrice;
               moneyTemp -= RealPrice;
           }
           else if( ui->label_31->isHidden()==true)
           {
               moneyTemp -=( ui->label_3->text()).toInt();
           }


            qDebug()<<moneyTemp;

            if(moneyTemp <= 0)
               {
                CanBuy=false;
                ui->errorLable->show();
               }



          // write kardane mojudie jadid dar file
          if(CanBuy==true)
          {
              members_file.operator <<('$');
              members_file.operator <<(moneyTemp);
              members_file.operator <<('%');
              members_file.operator <<('\n');
          }

           GetIndex.close();
           members.close();


    }



    if(ui->checkBox_3->isChecked())
    {
        QFile Current("CurrentUSer.txt");
        Current.open(QIODevice::ReadWrite | QIODevice::Text);

        QTextStream Current_file(&Current);
        QString CurrentUser= Current_file.readLine();

        Current.close();

        QFile members;
        members.setFileName(CurrentUser);
         members.open(QIODevice::ReadWrite | QIODevice::Text |QIODevice::Append);

          QTextStream members_file(&members);

          members_file.operator <<(ui->comboBox_3->currentText()) ;
          members_file.operator <<("\n");
          members_file.operator << (ui->comboBox_9->currentText());
          members_file.operator <<("\n");
          members_file.operator <<(ui->label_4->text());
          members_file.operator <<("\n");



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

           int moneyTemp=money;

           // kam kardane hazineye ghazaye reserve shode az kole mojudi
           if(ui->label_32->isHidden()==false)
           {
               qDebug()<<"here in if";
               int RealPrice=(((ui->perc->text().toInt())*(0.01))+1) * (ui->label_4->text().toInt());
               qDebug()<<RealPrice;
               moneyTemp -= RealPrice;
           }
           else if( ui->label_32->isHidden()==true)
           {
               moneyTemp -=( ui->label_4->text()).toInt();
           }

            qDebug()<<moneyTemp;


            if(moneyTemp <= 0)
               {
                CanBuy=false;
                ui->errorLable->show();
               }



          // write kardane mojudie jadid dar file
          if(CanBuy==true)
          {
              members_file.operator <<('$');
              members_file.operator <<(moneyTemp);
              members_file.operator <<('%');
              members_file.operator <<('\n');
          }


          GetIndex.close();



          members.close();


    }




    if(ui->checkBox_4->isChecked())
    {
        QFile Current("CurrentUSer.txt");
        Current.open(QIODevice::ReadWrite | QIODevice::Text);

        QTextStream Current_file(&Current);
        QString CurrentUser= Current_file.readLine();

        Current.close();

        QFile members;
        members.setFileName(CurrentUser);
         members.open(QIODevice::ReadWrite | QIODevice::Text |QIODevice::Append);

          QTextStream members_file(&members);

          members_file.operator <<(ui->comboBox_4->currentText()) ;
          members_file.operator <<("\n");
          members_file.operator << (ui->comboBox_10->currentText());
          members_file.operator <<("\n");
          members_file.operator <<(ui->label_5->text());
          members_file.operator <<("\n");


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

           int moneyTemp=money;

           // kam kardane hazineye ghazaye reserve shode az kole mojudi
           if(ui->label_33->isHidden()==false)
           {
               qDebug()<<"here in if";
               int RealPrice=(((ui->perc->text().toInt())*(0.01))+1) * (ui->label_5->text().toInt());
               qDebug()<<RealPrice;
               moneyTemp -= RealPrice;
           }
           else if( ui->label_33->isHidden()==true)
           {
               moneyTemp -=( ui->label_5->text()).toInt();
           }


            qDebug()<<moneyTemp;
            if(moneyTemp <= 0)
               {
                CanBuy=false;
                ui->errorLable->show();
               }



          // write kardane mojudie jadid dar file
          if(CanBuy==true)
          {
              members_file.operator <<('$');
              members_file.operator <<(moneyTemp);
              members_file.operator <<('%');
              members_file.operator <<('\n');
          }


          GetIndex.close();

          members.close();


    }




    if(ui->checkBox_5->isChecked())
    {
        QFile Current("CurrentUSer.txt");
        Current.open(QIODevice::ReadWrite | QIODevice::Text);

        QTextStream Current_file(&Current);
        QString CurrentUser= Current_file.readLine();

        Current.close();

        QFile members;
        members.setFileName(CurrentUser);
        members.open(QIODevice::ReadWrite | QIODevice::Text |QIODevice::Append);



         QTextStream members_file(&members);

          members_file.operator <<(ui->comboBox_5->currentText()) ;
          members_file.operator <<("\n");
          members_file.operator << (ui->comboBox_11->currentText());
          members_file.operator <<("\n");
          members_file.operator <<(ui->label_6->text());
          members_file.operator <<("\n");


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

           int moneyTemp=money;

           // kam kardane hazineye ghazaye reserve shode az kole mojudi
           if(ui->label_34->isHidden()==false)
           {
               qDebug()<<"here in if";
               int RealPrice=(((ui->perc->text().toInt())*(0.01))+1) * (ui->label_6->text().toInt());
               qDebug()<<RealPrice;
               moneyTemp -= RealPrice;
           }
           else if( ui->label_34->isHidden()==true)
           {
               moneyTemp -=( ui->label_6->text()).toInt();
           }

            qDebug()<<moneyTemp;

            if(moneyTemp <= 0)
               {
                CanBuy=false;
                ui->errorLable->show();
               }



          // write kardane mojudie jadid dar file
          if(CanBuy==true)
          {
              members_file.operator <<('$');
              members_file.operator <<(moneyTemp);
              members_file.operator <<('%');
              members_file.operator <<('\n');
          }


          GetIndex.close();

          members.close();


    }



    if(ui->checkBox_6->isChecked())
    {
        QFile Current("CurrentUSer.txt");
        Current.open(QIODevice::ReadWrite | QIODevice::Text);

        QTextStream Current_file(&Current);
        QString CurrentUser= Current_file.readLine();
        Current.close();

        QFile members;
        members.setFileName(CurrentUser);
         members.open(QIODevice::ReadWrite | QIODevice::Text |QIODevice::Append);

          QTextStream members_file(&members);

          members_file.operator <<(ui->comboBox_6->currentText()) ;
          members_file.operator <<("\n");
          members_file.operator << (ui->comboBox_12->currentText());
          members_file.operator <<("\n");
          members_file.operator <<(ui->label_7->text());
          members_file.operator <<("\n");




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

           int moneyTemp=money;

           // kam kardane hazineye ghazaye reserve shode az kole mojudi
           if(ui->label_35->isHidden()==false)
           {
               qDebug()<<"here in if";
               int RealPrice=(((ui->perc->text().toInt())*(0.01))+1) * (ui->label_7->text().toInt());
               qDebug()<<RealPrice;
               moneyTemp -= RealPrice;
           }
           else if( ui->label_35->isHidden()==true)
           {
               moneyTemp -=( ui->label_7->text()).toInt();
           }

            qDebug()<<moneyTemp;

            if(moneyTemp <= 0)
               {
                CanBuy=false;
                ui->errorLable->show();
               }



          // write kardane mojudie jadid dar file
          if(CanBuy==true)
          {
              members_file.operator <<('$');
              members_file.operator <<(moneyTemp);
              members_file.operator <<('%');
              members_file.operator <<('\n');
          }



            GetIndex.close();

          members.close();

    }





}


void FoodReserve::paintEvent(QPaintEvent *)
{
    p.begin(this);
    p.drawImage(QRect(0,0,550,550),bg);
    p.end();
}


void FoodReserve::on_comboBox_1_currentTextChanged(const QString &arg1)
{
    int cost;
    if(arg1=="Meigu")
    {
    cost=3000;
    ui->label_2->setText(QString("%1").arg(cost));
    }
    else if(arg1=="Lazania")
    {
        cost=2000;
        ui->label_2->setText(QString("%1").arg(cost));

    }

}

void FoodReserve::on_comboBox_2_currentTextChanged(const QString &arg1)
{

    int cost;
    if(arg1=="Steak")
    {
    cost=4000;
    ui->label_3->setText(QString("%1").arg(cost));
    }
    else if(arg1=="Juje")
    {
        cost=1000;
        ui->label_3->setText(QString("%1").arg(cost));

    }
}

void FoodReserve::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    int cost;
    if(arg1=="Khaviar")
    {
    cost=6000;
    ui->label_4->setText(QString("%1").arg(cost));
    }
    else if(arg1=="Makaroni")
    {
        cost=1000;
        ui->label_4->setText(QString("%1").arg(cost));

    }
}

void FoodReserve::on_comboBox_4_currentTextChanged(const QString &arg1)
{
    int cost;
    if(arg1=="Biff")
    {
    cost=4000;
    ui->label_5->setText(QString("%1").arg(cost));
    }
    else if(arg1=="Fesenjan")
    {
        cost=2000;
        ui->label_5->setText(QString("%1").arg(cost));

    }
}

void FoodReserve::on_comboBox_5_currentTextChanged(const QString &arg1)
{
    int cost;
    if(arg1=="Olovie")
    {
    cost=1500;
    ui->label_6->setText(QString("%1").arg(cost));
    }
    else if(arg1=="Shenitsel")
    {
        cost=2000;
        ui->label_6->setText(QString("%1").arg(cost));

    }
}

void FoodReserve::on_comboBox_6_currentTextChanged(const QString &arg1)
{
    int cost;
    if(arg1=="Kabab")
    {
    cost=1000;
    ui->label_7->setText(QString("%1").arg(cost));
    }
    else if(arg1=="Omlet")
    {
        cost=500;
        ui->label_7->setText(QString("%1").arg(cost));

    }
}

void FoodReserve::on_pushButton_clicked()
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
      ui->MojudiLable->setText(QString("%1").arg(money));
      ui->MojudiLable->show();

}

void FoodReserve::on_NextWeek_clicked()
{
    int date= (ui->label_21->text()).toInt() +1;
    int date2=date;
    int date3=0;

    int month= ui->label_20->text().toInt();

    if( date2+1 <31)
        date3=date2+1;
    else
      {

        date3= date2+1-30;
        month++;
    }

    ui->label_10->setText(QString("%1").arg(date3));

    ui->label_8->setText(QString("%1").arg(month));


    if( date2+2 <31)
        date3=date2+2;
    else
        date3= date2+2-30;
    ui->label_12->setText(QString("%1").arg(date3));
    if(ui->label_12->text().toInt() < ui->label_10->text().toInt())
        month++;
    ui->label_11->setText(QString("%1").arg(month));




    if( date2+3 <31)
        date3=date2+3;
    else
        date3= date2+3-30;
   ui->label_14->setText(QString("%1").arg(date3));
   if(ui->label_14->text().toInt() < ui->label_12->text().toInt())
       month++;

   ui->label_13->setText(QString("%1").arg(month));




    if( date2+4 <31)
        date3=date2+4;
    else
        date3= date2+4-30;
    ui->label_17->setText(QString("%1").arg(date3));
    if(ui->label_17->text().toInt() < ui->label_14->text().toInt())
        month++;
    ui->label_16->setText(QString("%1").arg(month));




    if( date2+5 <31)
        date3=date2+5;
    else
        date3= date2+5-30;
    ui->label_19->setText(QString("%1").arg(date3));
    if(ui->label_19->text().toInt() < ui->label_17->text().toInt())
        month++;
    ui->label_18->setText(QString("%1").arg(month));




    if( date2+6 <31)
        date3=date2+6;
    else
        date3= date2+6-30;
    ui->label_21->setText(QString("%1").arg(date3));
    if(ui->label_21->text().toInt() < ui->label_19->text().toInt())
        month++;
    ui->label_20->setText(QString("%1").arg(month));



    int day= QDate::currentDate().day();
    int m= QDate::currentDate().month();

    if( day== ui->label_10->text().toInt()&& m==ui->label_8->text().toInt() )
        ui->label_30->show();

    if( day== ui->label_12->text().toInt() && m==ui->label_11->text().toInt())
        ui->label_31->show();

    if( day== ui->label_14->text().toInt() && m==ui->label_13->text().toInt())
        ui->label_32->show();

    if( day== ui->label_17->text().toInt()&& m==ui->label_16->text().toInt())
        ui->label_33->show();

    if( day== ui->label_19->text().toInt()&& m==ui->label_18->text().toInt())
        ui->label_34->show();

    if( day== ui->label_21->text().toInt()&& m==ui->label_20->text().toInt())
        ui->label_35->show();



}
