#include "kaupunginosa.h"
#include "ui_kaupunginosa.h"



Kaupunginosa::Kaupunginosa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kaupunginosa)
{
    ui->setupUi(this);
    //ui->setToken->setEnabled(false);
}

Kaupunginosa::Kaupunginosa(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location, Ui::Akkuna *akkuna, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kaupunginosa),
    location_(location),
    peli_(peli),
    akkuna_(akkuna)

{
    ui->setupUi(this);
    ui->nimi->setText(location_->name());
    QObject::connect(ui->drawCard, SIGNAL(clicked()),
                      this, SLOT(nostaKortti()));
    QObject::connect(ui->setAgent, SIGNAL(clicked()),
                      this, SLOT(asetaAgentti()));
    QObject::connect(ui->setToken, SIGNAL(clicked()),
                      this, SLOT(asetaPelimerkki()));
    QObject::connect(ui->agentToken, SIGNAL(clicked()),
                      this, SLOT(agentilleMerkki()));
    asetaPakkakuvat();

}

// Runner hoitaa canperformit ja performit. Meillä on kai vaan et lähetetään pleijjerille nextActioniin actioneita
void Kaupunginosa::nostaKortti()
{
    ActionNostaKortti* toiminto = new ActionNostaKortti(peli_, location_);
    if (toiminto->canPerform())
    {
        toiminto->perform();
    }
    qDebug() << "nosta kortti";
    std::shared_ptr<ActionNostaKortti> kortti = make_shared<ActionNostaKortti>();

}

void Kaupunginosa::nostaAgentti()
{
    ActionNostaAgentti* toiminto = new ActionNostaAgentti(peli_, location_);
    if (toiminto->canPerform())
    {
        ui->setToken->setEnabled(false);
        ui->drawCard->setEnabled(false);
        ui->agentToken->setEnabled(false);
        toiminto->perform();

        ui->setAgent->setText("Aseta agentti");
        QObject::connect(ui->setAgent, SIGNAL(clicked()),
                          this, SLOT(asetaAgentti()));
    }
    qDebug() << "nosta agentti";
}

void Kaupunginosa::asetaAgentti()
{
    ActionAsetaAgentti* toiminto = new ActionAsetaAgentti(peli_, location_);
    qDebug() << "aseta agentti";

    if (toiminto->canPerform())
    {
        ui->setToken->setEnabled(true);
        ui->drawCard->setEnabled(true);
        ui->agentToken->setEnabled(true);
        toiminto->perform();

        ui->setAgent->setText("Nosta agentti");
        QObject::connect(ui->setAgent, SIGNAL(clicked()),
                          this, SLOT(nostaAgentti()));
        ui->agentit->addWidget(new Pelikortti());
    }
}

void Kaupunginosa::agentilleMerkki()
{
    ActionAgentilleMerkki* toiminto = new ActionAgentilleMerkki(peli_, location_);
    if (toiminto->canPerform())
    {
        toiminto->perform();
    }
    qDebug() << "agentille merkki";
}

void Kaupunginosa::asetaPelimerkki()
{
    ActionAsetaPelimerkki* toiminto = new ActionAsetaPelimerkki(peli_, location_);

    if (toiminto->canPerform())
    {
        toiminto->perform();
    }
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
