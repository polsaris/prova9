#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QTimer>
#include <QTime>
class calaix;
class RDigital;
namespace Ui {
class AnalogClock;
}

class AnalogClock : public QWidget
{
    Q_OBJECT
    
public:
    explicit AnalogClock(QWidget *parent = 0);
    ~AnalogClock();
    QTimer *timer;
    QTime time;
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


private:
    Ui::AnalogClock *ui;
    calaix *calaixx;
    RDigital *rdigital;
};

#endif // ANALOGCLOCK_H
