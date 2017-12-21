#ifndef CALAIX_H
#define CALAIX_H

#include <QWidget>

class calculadora;
class Calendari;
class Opcions;
namespace Ui {
class calaix;
}

class calaix : public QWidget
{
    Q_OBJECT

public:
    explicit calaix(QWidget *parent = 0);
    ~calaix();



public slots:
    void on_tanca_clicked();

private slots:
    void on_calculadora_clicked();

    void on_p_3_clicked();

    void on_p_7_clicked();

private:
    Ui::calaix *ui;
    calculadora *calculadoraa;
    Opcions *opcions;
    Calendari *calendari;



};

#endif // CALAIX_H
