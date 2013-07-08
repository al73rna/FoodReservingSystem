#ifndef FOODRESERVE_H
#define FOODRESERVE_H

#include <QWidget>
#include <QMainWindow>
#include<usersettings.h>
#include<QPainter>
#include<QImage>
#include<QDebug>

namespace Ui {
class FoodReserve;
}

class FoodReserve : public QWidget
{
    Q_OBJECT
    
public:
    explicit FoodReserve(QWidget *parent = 0);
    QMainWindow *mainW2;
    UserSettings * userInfo;
    QPainter p;
    QImage bg;



    ~FoodReserve();
    void setMain(QMainWindow *m);
     void paintEvent(QPaintEvent *);

private slots:
    void on_Submit_clicked();

    void on_Settings_clicked();

    void on_comboBox_1_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox_3_currentTextChanged(const QString &arg1);

    void on_comboBox_4_currentTextChanged(const QString &arg1);

    void on_comboBox_5_currentTextChanged(const QString &arg1);

    void on_comboBox_6_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_NextWeek_clicked();

private:
    Ui::FoodReserve *ui;
};

#endif // FOODRESERVE_H
