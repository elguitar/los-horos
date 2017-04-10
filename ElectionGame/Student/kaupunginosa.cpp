#include "kaupunginosa.h"
#include "ui_kaupunginosa.h"

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
}

Kaupunginosa::~Kaupunginosa()
{
    delete ui;
}
