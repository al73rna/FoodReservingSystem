#ifndef PERCENT_H
#define PERCENT_H

#include <QWidget>
#include<QPainter>
#include<QImage>

namespace Ui {
class Percent;
}

class Percent : public QWidget
{
    Q_OBJECT
    
public:
    explicit Percent(QWidget *parent = 0);
    QPainter p;
    QImage bg;
    void paintEvent(QPaintEvent *);
    ~Percent();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Percent *ui;
};

#endif // PERCENT_H
