#ifndef ADMINMONEYCHANGE_H
#define ADMINMONEYCHANGE_H

#include <QWidget>
#include<QPainter>
#include<QImage>


namespace Ui {
class AdminMoneyChange;
}

class AdminMoneyChange : public QWidget
{
    Q_OBJECT
    
public:
    explicit AdminMoneyChange(QWidget *parent = 0);

    QPainter p;
    QImage bg;
    void paintEvent(QPaintEvent *);

    ~AdminMoneyChange();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdminMoneyChange *ui;
};

#endif // ADMINMONEYCHANGE_H
