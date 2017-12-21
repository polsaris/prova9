#include "calaix.h"
#include "ui_calaix.h"
#include "calculadora.h"
#include "ui_calculadora.h"
#include "calendari.h"
#include "ui_calendari.h"
#include "opcions.h"
#include "ui_opcions.h"

calaix::calaix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calaix)
{
    ui->setupUi(this);
    calculadoraa = new calculadora(this);
    calculadoraa->close();
    calendari = new Calendari(this);
    calendari->close();
    opcions = new Opcions(this);
    opcions->close();

}



calaix::~calaix()
{
    delete ui;
}


void calaix::on_tanca_clicked()
{
    close();
}

void calaix::on_calculadora_clicked()
{
    calculadoraa->show();

}

void calaix::on_p_3_clicked()
{
    calendari->show();
}

void calaix::on_p_7_clicked()
{
    opcions->show();
}
