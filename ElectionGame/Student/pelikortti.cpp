#include "pelikortti.h"
#include "ui_pelikortti.h"

Pelikortti::Pelikortti(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pelikortti)
{
    ui->setupUi(this);
}

Pelikortti::Pelikortti(shared_ptr<Interface::CardInterface> kortti, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pelikortti),
    kortti_(kortti)
{
    ui->setupUi(this);
}

Pelikortti::~Pelikortti()
{
    delete ui;
}
