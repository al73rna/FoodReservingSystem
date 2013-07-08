#ifndef INCMONEY_H
#define INCMONEY_H

#include <QWidget>
#include<QPainter>
#include<QImage>

namespace Ui {
class IncMoney;
}

class IncMoney : public QWidget
{
    Q_OBJECT
    
public:
    explicit IncMoney(QWidget *parent = 0);
    QPainter p;
    QImage bg;
    void paintEvent(QPaintEvent *);
     ~IncMoney();
    
private slots:
    void on_pushButton_clicked();

    void on_TransferButton_clicked();

private:
    Ui::IncMoney *ui;
};

#endif // INCMONEY_H
