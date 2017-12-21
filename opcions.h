#ifndef OPCIONS_H
#define OPCIONS_H

#include <QWidget>


namespace Ui {
class Opcions;
}

class Opcions : public QWidget
{
    Q_OBJECT

public:
    explicit Opcions(QWidget *parent = 0);
    ~Opcions();

private slots:


    void on_p_6_clicked();

private:
    Ui::Opcions *ui;



};

#endif // OPCIONS_H
