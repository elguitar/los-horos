#include "kaupunginosa.h"
#include "ui_kaupunginosa.h"
#include "deckinterface.h"
#include <QDebug>


Kaupunginosa::Kaupunginosa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kaupunginosa)
{
    ui->setupUi(this);
}

Kaupunginosa::Kaupunginosa(std::shared_ptr<Interface::Location> location, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kaupunginosa),
    location_(location)
{
    ui->setupUi(this);
    ui->nimi->setText(location_->name());
    if(location_->name() == "Hengenpelastajatytöt"){
        ui->pakka->setStyleSheet("QWidget {background-image: url(.Assets/naiskorttiback.png) }");
    }
    QObject::connect(ui->drawCard, SIGNAL(clicked()),
                      this, SLOT(nostaKortti()));
    QObject::connect(ui->setAgent, SIGNAL(clicked()),
                      this, SLOT(asetaAgentti()));
    QObject::connect(ui->setToken, SIGNAL(clicked()),
                      this, SLOT(asetaPelimerkki()));
    QObject::connect(ui->drawAgent, SIGNAL(clicked()),
                      this, SLOT(nostaAgentti()));
}

void Kaupunginosa::nostaKortti()
{
    qDebug() << "nosta kortti";
    if (location_->deck()->canDraw())
    {
        location_->deck()->draw();
    }
    else
    {

    }
}

void Kaupunginosa::nostaAgentti()
{
    qDebug() << "nosta agentti";
}

void Kaupunginosa::asetaAgentti()
{
    qDebug() << "aseta agentti";
}

void Kaupunginosa::asetaPelimerkki()
{
    qDebug() << "aseta pelimerkki";
}

Kaupunginosa::~Kaupunginosa()
{
    delete ui;
}
