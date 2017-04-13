#include "kaupunginosa.h"
#include "ui_kaupunginosa.h"

#include "akkuna.h"


Kaupunginosa::Kaupunginosa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kaupunginosa)
{
    ui->setupUi(this);
    //ui->setToken->setEnabled(false);
}

Kaupunginosa::Kaupunginosa(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kaupunginosa),
    location_(location),
    peli_(peli)
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


Kaupunginosa::Kaupunginosa(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location, std::shared_ptr<QWidget> akkuna, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kaupunginosa),
    location_(location),
    peli_(peli)
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
    //akkuna_ = std::dynamic_pointer_cast<Akkuna>(akkuna);

}

void Kaupunginosa::enableButtons()
{
    ui->setToken->setEnabled(true);
    ui->drawCard->setEnabled(true);
    ui->agentToken->setEnabled(true);

    ui->setAgent->setText("Nosta agentti");
    QObject::connect(ui->setAgent, SIGNAL(clicked()),
                      this, SLOT(nostaAgentti()));
}

void Kaupunginosa::hideButtons()
{
    ui->setToken->setEnabled(false);
    ui->drawCard->setEnabled(false);
    ui->agentToken->setEnabled(false);

    ui->setAgent->setText("Aseta agentti");
    QObject::connect(ui->setAgent, SIGNAL(clicked()),
                      this, SLOT(asetaAgentti()));

}

// Runner hoitaa canperformit ja performit. Meillä on kai vaan et lähetetään pleijjerille nextActioniin actioneita
void Kaupunginosa::nostaKortti()
{
    ActionNostaKortti* toiminto = new ActionNostaKortti(peli_, location_);
    if (toiminto->canPerform())
    {
        toiminto->perform();
        qDebug() << "nosta kortti";

    }
    std::shared_ptr<ActionNostaKortti> kortti = make_shared<ActionNostaKortti>();

    peli_->nextPlayer();
    //((Akkuna*)this->parentWidget()->parentWidget())->refreshUI();
    ((Akkuna*)this->parentWidget())->refreshHandToCurrentPlayer();



}

void Kaupunginosa::nostaAgentti()
{
    ActionNostaAgentti* toiminto = new ActionNostaAgentti(peli_, location_);
    if (toiminto->canPerform())
    {
        toiminto->perform();
        hideButtons();
        qDebug() << "nosta agentti";

    }

    peli_->nextPlayer();
    //((Akkuna*)this->parentWidget()->parentWidget())->refreshUI();
    ((Akkuna*)this->parentWidget())->refreshHandToCurrentPlayer();

}

void Kaupunginosa::asetaAgentti()
{
    ActionAsetaAgentti* toiminto = new ActionAsetaAgentti(peli_, location_);

    if (toiminto->canPerform())
    {
        toiminto->perform();
        enableButtons();
        ui->agentit->addWidget(new Pelikortti());
        qDebug() << "aseta agentti";

    }
    //std::shared_ptr<Akkuna> polo = std::dynamic_pointer_cast<Akkuna>(akkuna_);
    //polo->refreshHandToCurrentPlayer();
    //Akkuna* mutsis_muuttuja = dynamic_cast<Akkuna*>(this->parentWidget());
    //mutsis_muuttuja->refreshHandToCurrentPlayer();
    //((Akkuna*)parentWidget())->refreshHandToCurrentPlayer();*/
    //((Akkuna*)this->parentWidget())->refreshHandToCurrentPlayer();
    peli_->nextPlayer();
    //((Akkuna*)this->parentWidget()->parentWidget())->refreshUI();
    ((Akkuna*)this->parentWidget())->refreshHandToCurrentPlayer();

}

void Kaupunginosa::agentilleMerkki()
{
    ActionAgentilleMerkki* toiminto = new ActionAgentilleMerkki(peli_, location_);
    if (toiminto->canPerform())
    {
        toiminto->perform();
        qDebug() << "agentille merkki";

    }
    peli_->nextPlayer();
    //((Akkuna*)this->parentWidget()->parentWidget())->refreshUI();
    ((Akkuna*)this->parentWidget())->refreshHandToCurrentPlayer();
}

void Kaupunginosa::asetaPelimerkki()
{
    ActionAsetaPelimerkki* toiminto = new ActionAsetaPelimerkki(peli_, location_);

    if (toiminto->canPerform())
    {
        toiminto->perform();
        qDebug() << "aseta pelimerkki";

    }
    peli_->nextPlayer();
    //((Akkuna*)this->parentWidget()->parentWidget())->refreshUI();
    ((Akkuna*)this->parentWidget())->refreshHandToCurrentPlayer();
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
