#ifndef FORGOT_H
#define FORGOT_H

#include <QWidget>
#include<QMainWindow>
#include<QPainter>
#include<QImage>



namespace Ui {
class Forgot;
}

class Forgot : public QWidget
{
    Q_OBJECT
    
public:
    explicit Forgot(QWidget *parent = 0);
     QMainWindow *mainW;

     QPainter p;
     QImage bg;
     void paintEvent(QPaintEvent *);
    ~Forgot();
      void setMain(QMainWindow *m);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Forgot *ui;
};

#endif // FORGOT_H
