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
    QObject::connect(ui->drawCard, SIGNAL(clicked()),
                      this, SLOT(nostaKortti()));
    QObject::connect(ui->setAgent, SIGNAL(clicked()),
                      this, SLOT(asetaAgentti()));
    QObject::connect(ui->setToken, SIGNAL(clicked()),
                      this, SLOT(asetaPelimerkki()));
    QObject::connect(ui->drawAgent, SIGNAL(clicked()),
                      this, SLOT(nostaAgentti()));
    asetaPakkakuvat();

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
    if(ui->agentit->count() < 3){
        ui->agentit->addWidget(new Pelikortti());
    }
}

void Kaupunginosa::asetaPelimerkki()
{
    qDebug() << "aseta pelimerkki";
}

void Kaupunginosa::asetaPakkakuvat()
{
    if(location_->name() == "Hengenpelastajatytöt"){
        QPixmap pic("Assets/naiskorttiback.png");
        QPixmap scaled = pic.scaled(61, 91, Qt::IgnoreAspectRatio, Qt::FastTransformation);

        ui->pakka->setPixmap(scaled);
    }
    else if(location_->name() == "Metsämiesten kilta"){
        QPixmap pic("Assets/metsakorttiback.png");
        QPixmap scaled = pic.scaled(61, 91, Qt::IgnoreAspectRatio, Qt::FastTransformation);

        ui->pakka->setPixmap(scaled);
    }
   else if(location_->name() == "Kaupungin kuumakulmakundit"){
        QPixmap pic("Assets/citykorttiback.png");
        QPixmap scaled = pic.scaled(61, 91, Qt::IgnoreAspectRatio, Qt::FastTransformation);

        ui->pakka->setPixmap(scaled);
    }
    else if(location_->name() == "Kallion huolestuneet kansalaiset"){
        QPixmap pic("Assets/kalliokorttiback.png");
        QPixmap scaled = pic.scaled(61, 91, Qt::IgnoreAspectRatio, Qt::FastTransformation);

        ui->pakka->setPixmap(scaled);
    }
}

Kaupunginosa::~Kaupunginosa()
{
    delete ui;
}
