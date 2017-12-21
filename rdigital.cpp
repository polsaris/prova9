#include "rdigital.h"
#include "ui_rdigital.h"
#include <QTime>
#include <QTimer>
#include <QDate>
#include <QPainter>
#include "calaix.h"

RDigital::RDigital(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RDigital)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    data_avui();

    calaixx = new calaix(this);
    calaixx->close();

    QFont f("Ubuntu",15,QFont::Bold);      //font de la data
    ui->label_2->setFont(f);
    RDigital::setStyleSheet("background-color:white;");      //color fons
    fontNormal();


}

RDigital::~RDigital()
{
    delete ui;
}



void RDigital::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    QString text2 = time.toString("ss");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    ui->label->setText(text);
    ui->label_3->setText(text2);
}

void RDigital::data_avui() {
    QDate date = QDate::currentDate();
        QString s = date.toString("dddd/MMMM/yyyy");
        ui->label_2->setText(s);

}

void RDigital::fontDigital() {
    QFont digital("Segment7",47,QFont::Bold);
    QFont digitalss("Segment7",27,QFont::Bold);
    ui->label->setFont(digital);
    ui->label_3->setFont(digitalss);
}

void RDigital::fontNormal() {
    QFont normal("Ubuntu",50,10,QFont::Bold);
    QFont normalss("Ubuntu",30,10,QFont::Bold);
    ui->label->setFont(normal);
    ui->label_3->setFont(normalss);
}


void RDigital::on_pushButton_clicked()
{
    fontNormal();
}

void RDigital::on_pushButton_2_clicked()
{
    fontDigital();
}

void RDigital::on_pushButton_3_clicked()
{
    QDate date = QDate::currentDate();
        QString s = date.toString("dd/MM/yy");
        ui->label_2->setText(s);
        QFont f("Ubuntu",30,50,QFont::Bold);      //font de la data
        ui->label_2->setFont(f);


}

void RDigital::on_pushButton_4_clicked()
{
    QDate date = QDate::currentDate();
        QString s = date.toString("dddd/MMMM/yyyy");
        ui->label_2->setText(s);
        QFont f("Ubuntu",15,QFont::Bold);      //font de la data
        ui->label_2->setFont(f);

}

void RDigital::on_pushButton_5_clicked()
{
    close();
}

void RDigital::on_pushButton_6_clicked()
{
    calaixx->show();
}
