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
    QObject::connect(ui->draw, SIGNAL(clicked()),
                      this, SLOT(nostaKortti()));
}

void Kaupunginosa::nostaKortti()
{
    qDebug() << "Mennäännostoon";
    if (location_->deck()->canDraw())
    {
        location_->deck()->draw();
    }
    else
    {

    }
}

Kaupunginosa::~Kaupunginosa()
{
    delete ui;
}
