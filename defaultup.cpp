#include "defaultup.h"
#include "ui_defaultup.h"
#include "QFile"
#include<QTextStream>
#include<adminpage.h>
#include<mainwindow.h>

DefaultUP::DefaultUP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DefaultUP)
{

    ui->setupUi(this);
    bool flag=bg.load("E:/green lines.png");
    qDebug()<<flag;

}

DefaultUP::~DefaultUP()
{
    delete ui;
}

void DefaultUP::on_CopyToFileButton_clicked()
{

    // baraye namayesh e inke etela'ate chandomin memeber darad vared mishavad.
    static int MemberNum=2;
    ui->numberLable->setText(QString("%1").arg(MemberNum));

    // baraye inke tedad e member ha dar yek file zakhire shavad va har bar yeki ziad shavad.
 /* QFile Number("NumberOfMembers");
  Number.open(QIODevice::ReadWrite| QIODevice::Text);
  QDataStream Number_file(&Number);
  qint32 size;
  Number_file.operator >>(size);
  size= size+1;
  Number_file.operator <<(size);

 Number.close();
*/



    QFile users_file; // ba zadane dokmeye next yek file sakhte mishavad. baraye useri ke info ash vared shode
    QString ID= ui->IDlineEdit->text();  // shomare daneshjuyi ash dar yek string rikhte mishavad.

    users_file.setFileName(ID); // name e file be shomare daneshjuyi taghir mikonad.
    users_file.open(QIODevice::ReadWrite | QIODevice::Text);  // file baz mishavad.
    QTextStream users_fileStream(&users_file);  // yek QTextStream sakhte mishavad ke address e file be an dade mishavad.



     QString username= ui->UserlineEdit->text();  // username va pass dakhele yek string rikhte mishavand.
     QString password= ui->PasslineEdit->text();
     QString mojudi= ui->MojudilineEdit->text();


 // shomare daneshjuyi va username va pass va mojudie avalie ke 50000 toman ast dakhele file rikhte mishavand
    users_fileStream.operator <<(ID);
    users_fileStream.operator <<("\n");
    users_fileStream.operator <<('<');
    users_fileStream.operator <<(username);
    users_fileStream.operator <<('>');
    users_fileStream.operator <<("\n");
    users_fileStream.operator <<('/');
    users_fileStream.operator <<(password);
    users_fileStream.operator <<('@');

    //mikham adade mojudi ba koli fasele neveshte beshe ke badan mogheye taghire user va pass
    // chizish pak nashe

    //for( int i=0; i<20; i++)
    users_fileStream.operator <<("\n");
    users_fileStream.operator <<('$');
    users_fileStream.operator <<(mojudi);
    users_fileStream.operator <<("%");
    users_fileStream.operator <<("\n");



    users_file.close();  // file baste mishavad.

    // lable ha baraye info e karbare jadid pak mishavand.
    ui->IDlineEdit->clear();
    ui->UserlineEdit->clear();
    ui->PasslineEdit->clear();
    ui->MojudilineEdit->clear();

    //MemberNum++;


}

void DefaultUP::setMain(QMainWindow *m)
{
    this->mainW = m ;

}

void DefaultUP::on_lineEdit_editingFinished()
{
}

void DefaultUP::on_DefaultsFinished_clicked()
{

    this->close();
}

void DefaultUP::paintEvent(QPaintEvent *)
{
    p.begin(this);
    p.drawImage(QRect(0,0,550,550),bg);
    p.end();
}
