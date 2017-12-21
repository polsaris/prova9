#include "analogclock.h"
#include "ui_analogclock.h"
#include <QPainter>
#include <QPushButton>
#include <QLabel>
#include "calaix.h"
#include "rdigital.h"

AnalogClock::AnalogClock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalogClock)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

    calaixx = new calaix(this);
    calaixx->close();
    rdigital = new RDigital(this);
    rdigital->close();




    //AnalogClock::setStyleSheet("background-color:blue;");

    /*this->setGeometry(0,0,100,100);
    QWidget *test = new QWidget(this);
    test->setGeometry(0,0,320,240);
    test->setStyleSheet("background-color:blue;");*/

    //resize(480,320);
}

AnalogClock::~AnalogClock()
{
    delete ui;
}
void AnalogClock::paintEvent(QPaintEvent *)
{

    static const QPoint hourHand[3] = {
         QPoint(7, 8),
         QPoint(-7, 8),
         QPoint(0, -40)
     };
     static const QPoint minuteHand[3] = {
         QPoint(7, 8),
         QPoint(-7, 8),
         QPoint(0, -70)
     };
     static const QPoint secondHand[3] = {
         QPoint(7, 8),
         QPoint(-7, 8),
         QPoint(0, -80)
     };
     QColor hourColor(0, 0, 0);
     QColor minuteColor(0, 0, 0, 191);
     QColor secondColor(0, 0, 0);
     QColor backgroundColor(255,255,255);

      int side = qMin(width(), height());
      time = QTime::currentTime();
      QPainter painter(this);
      painter.setPen(Qt::NoPen);
      painter.setBrush(backgroundColor);

      painter.drawRect(0, 0, 480,320);
      painter.setRenderHint(QPainter::Antialiasing);
      painter.translate(width() / 2, height() / 2);
      painter.scale(side / 200.0, side / 200.0);

      painter.setPen(Qt::NoPen);
      painter.setBrush(hourColor);

      painter.save();
      painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
      painter.drawConvexPolygon(hourHand, 3);
      painter.restore();
      painter.setPen(hourColor);

       for (int i = 0; i < 12; ++i) {
           painter.drawLine(88, 0, 96, 0);
           painter.rotate(30.0);
       }

       painter.setPen(Qt::NoPen);
       painter.setBrush(minuteColor);

       painter.save();
       painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
       painter.drawConvexPolygon(minuteHand, 3);
       painter.restore();

       painter.setPen(minuteColor);

       for (int j = 0; j < 60; ++j) {
            if ((j % 5) != 0)
                painter.drawLine(92, 0, 96, 0);
            painter.rotate(6.0);
        }
       painter.drawLine(-2, -96, -2, -88);
       painter.drawLine(2, -96, 2, -88);
       painter.setPen(Qt::NoPen);
       painter.setBrush(secondColor);

       painter.save();
       painter.rotate(6.0 * time.second());
       painter.drawConvexPolygon(secondHand, 3);
       painter.restore();
}




void AnalogClock::on_pushButton_2_clicked()
{
    calaixx->show();
}

void AnalogClock::on_pushButton_clicked()
{
    rdigital->show();
}


