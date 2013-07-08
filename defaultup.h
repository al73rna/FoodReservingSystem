#ifndef DEFAULTUP_H
#define DEFAULTUP_H

#include <QWidget>
#include<QMainWindow>
#include<QPainter>
#include<QImage>
#include<QDebug>

namespace Ui {
class DefaultUP;
}

class DefaultUP : public QWidget
{
    Q_OBJECT
    
public:
    explicit DefaultUP(QWidget *parent = 0);
    QMainWindow *mainW;
    void setMain(QMainWindow *m);


    QPainter p;
    QImage bg;
    void paintEvent(QPaintEvent *);


    ~DefaultUP();
    
private slots:
    void on_CopyToFileButton_clicked();

    void on_lineEdit_editingFinished();

    void on_DefaultsFinished_clicked();

private:
    Ui::DefaultUP *ui;
};

#endif // DEFAULTUP_H
