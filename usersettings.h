#ifndef USERSETTINGS_H
#define USERSETTINGS_H

#include <QWidget>
#include<QMainWindow>
#include <changeinfo.h>
#include<QPainter>
#include<QImage>
#include <incmoney.h>
#include<history.h>

namespace Ui {
class UserSettings;
}

class UserSettings : public QWidget
{
    Q_OBJECT
    
public:
    explicit UserSettings(QWidget *parent = 0);
    QMainWindow *mainW2;
    ChangeInfo * CI;
    IncMoney * IM;
    History * H;
    QPainter p;
    QImage bg;


    void setMain(QMainWindow *m2);
    void paintEvent(QPaintEvent *);
    ~UserSettings();
    
private slots:
    void on_change_clicked();

    void on_money_clicked();

    void on_history_clicked();

private:
    Ui::UserSettings *ui;
};

#endif // USERSETTINGS_H
