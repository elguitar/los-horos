#include "kaupunginosa.h"
#include "ui_kaupunginosa.h"

Kaupunginosa::Kaupunginosa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kaupunginosa)
{
    ui->setupUi(this);
}

Kaupunginosa::~Kaupunginosa()
{
    delete ui;
}
