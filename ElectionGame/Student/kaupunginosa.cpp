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
    disconnect(ui->setAgent, SIGNAL(clicked()), this, SLOT(asetaAgentti()));
    QObject::connect(ui->setAgent, SIGNAL(clicked()),
                      this, SLOT(nostaAgentti()));
}

void Kaupunginosa::hideButtons()
{
    ui->setToken->setEnabled(false);
    ui->drawCard->setEnabled(false);
    ui->agentToken->setEnabled(false);

    ui->setAgent->setText("Aseta agentti");
    disconnect(ui->setAgent, SIGNAL(clicked()), this, SLOT(nostaAgentti()));
    QObject::connect(ui->setAgent, SIGNAL(clicked()),
                      this, SLOT(asetaAgentti()));

}

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
    ((Akkuna*)this->parentWidget())->refreshUI();
    ((Akkuna*)this->parentWidget())->refreshHandToCurrentPlayer();
    delete toiminto;


}

void Kaupunginosa::nostaAgentti()
{
    ActionNostaAgentti* toiminto = new ActionNostaAgentti(peli_, location_);
    if (toiminto->canPerform())
    {
        toiminto->perform();
        poistaPelaajanAgentti();
        hideButtons();


        peli_->nextPlayer();
        ((Akkuna*)this->parentWidget())->refreshUI();
        ((Akkuna*)this->parentWidget())->refreshHandToCurrentPlayer();
        qDebug() << "nosta agentti";
    }
    delete toiminto;
}

void Kaupunginosa::asetaAgentti()
{
    ActionAsetaAgentti* toiminto = new ActionAsetaAgentti(peli_, location_);

    if (toiminto->canPerform())
    {
        std::shared_ptr<Agent> agentti = etsiPelaajanKadestaAgentti();
        toiminto->perform();
        ui->agentit->addWidget(new PeliCard(agentti));
        enableButtons();
        peli_->nextPlayer();
        ((Akkuna*)this->parentWidget())->refreshUI();
        ((Akkuna*)this->parentWidget())->refreshHandToCurrentPlayer();
        qDebug() << "aseta agentti";

    }
    delete toiminto;
}

void Kaupunginosa::agentilleMerkki()
{
    ActionAgentilleMerkki* toiminto = new ActionAgentilleMerkki(peli_, location_);
    if (toiminto->canPerform())
    {
        toiminto->perform();
        paivitaAgentit();

        peli_->nextPlayer();
        ((Akkuna*)this->parentWidget())->refreshUI();
        ((Akkuna*)this->parentWidget())->refreshHandToCurrentPlayer();
        qDebug() << "agentille merkki";
    }
    delete toiminto;
}

void Kaupunginosa::asetaPelimerkki()
{
    ActionAsetaPelimerkki* toiminto = new ActionAsetaPelimerkki(peli_, location_);

    if (toiminto->canPerform())
    {
        toiminto->perform();

        peli_->nextPlayer();
        ((Akkuna*)this->parentWidget())->refreshUI();
        ((Akkuna*)this->parentWidget())->refreshHandToCurrentPlayer();
        qDebug() << "aseta pelimerkki";

    }
    delete toiminto;

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

void Kaupunginosa::poistaPelaajanAgentti()
{
    shared_ptr<Interface::Player> pelaaja = peli_->currentPlayer();
    QLayoutItem *item;
    unsigned short i = 0;
    while((item = ui->agentit->takeAt(i))){
        QWidget* witketti = item->widget();
        PeliCard* kortti = dynamic_cast<PeliCard*> (witketti);
        if(pelaaja == kortti->getOwner().lock()){
            delete item->widget();
            delete item;
            break;
        }
        ++i;
    }
}

std::shared_ptr<Agent> Kaupunginosa::etsiPelaajanKadestaAgentti()
{
    for (std::shared_ptr<Interface::CardInterface> card : peli_->currentPlayer()->cards())
    {
        if (card->typeName() == "Agent")
        {
            std::shared_ptr<Agent> kortti = std::dynamic_pointer_cast<Agent>(card);
            return kortti;
        }
    }
}

void Kaupunginosa::paivitaAgentit()
{
    shared_ptr<Interface::Player> pelaaja = peli_->currentPlayer();
    {
        QLayoutItem *item;
        unsigned short i = 0;
        while((item = ui->agentit->takeAt(i))){
            QWidget* witketti = item->widget();
            PeliCard* kortti = dynamic_cast<PeliCard*> (witketti);
            if (pelaaja = kortti->getOwner().lock())
            {
                qDebug() << "täällä vielä";
                for (auto agentti : location_->agents())
                {
                    if (agentti->owner().lock() == pelaaja)
                    {
                        qDebug() << agentti->connections();
                        kortti->setConnections(agentti->connections());
                    }
                }
            }
        }
    }
}

Kaupunginosa::~Kaupunginosa()
{
    delete ui;
}
