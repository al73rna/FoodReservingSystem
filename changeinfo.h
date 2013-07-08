#ifndef CHANGEINFO_H
#define CHANGEINFO_H

#include <QWidget>
#include<QPainter>
#include<QImage>


namespace Ui {
class ChangeInfo;
}

class ChangeInfo : public QWidget
{
    Q_OBJECT
    
public:
    explicit ChangeInfo(QWidget *parent = 0);
    QPainter p;
    QImage bg;
     void paintEvent(QPaintEvent *);

    ~ChangeInfo();
    
private slots:
    void on_changesdone_clicked();

private:
    Ui::ChangeInfo *ui;
};

#endif // CHANGEINFO_H
