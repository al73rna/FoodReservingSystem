#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<adminpage.h>

#include <defaultup.h>
#include<foodreserve.h>
#include<QPainter>
#include<QImage>
#include<QDebug>
#include<forgot.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:


    explicit MainWindow(QWidget *parent = 0);

   AdminPage * adminp;
   FoodReserve * memberPage;
   Forgot * forgotPage;
   QPainter p;
   QImage bg;


    ~MainWindow();
   void paintEvent(QPaintEvent *);
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_ExitButon_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
