#ifndef RDIGITAL_H
#define RDIGITAL_H
#include <QTime>
#include <QTimer>
#include <QWidget>
#include <QDate>

#include <QWidget>
class calaix;
namespace Ui {
class RDigital;
}

class RDigital : public QWidget
{
    Q_OBJECT
    QTime startTime;
    QTimer *timer;
    QDate *dia;

public:
    explicit RDigital(QWidget *parent = 0);
    ~RDigital();
private slots:
  void showTime();
  void data_avui();
  void fontDigital();
  void fontNormal();

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

private:
    Ui::RDigital *ui;
    calaix *calaixx;

};

#endif // RDIGITAL_H
