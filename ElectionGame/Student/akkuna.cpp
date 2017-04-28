#include "akkuna.h"
#include "ui_akkuna.h"

void Akkuna::asetaKorttiKateen(shared_ptr<Interface::CardInterface> kortti)
{
    qDebug() << "Kortti käteen. T: Akkuna";
    if(ui->kasikortit->count() < 7){
        ui->kasikortit->addWidget(new PeliCard(kortti));
    }
}

void Akkuna::refreshHandToCurrentPlayer()
{
    shared_ptr<Interface::Player> pelaaja = peli_->currentPlayer();
    ui->pelaajakyltti->setText(pelaaja->name());
    std::vector<std::shared_ptr<Interface::CardInterface> > kortit = pelaaja->cards();

    QLayoutItem *item;
    while((item = ui->kasikortit->takeAt(0))){
        delete item->widget();
        delete item;
    }
    if(kortit.size() > 0){
        for (auto it = kortit.begin(); it != kortit.end(); ++it){
            ui->kasikortit->addWidget(new PeliCard(*it, true));
        }
    } ui->kasikortit->addStretch();
}

void Akkuna::laskeVoittaja()
{
    std::map<shared_ptr<Interface::Player>, int> pisteet;
    std::map<shared_ptr<Interface::Player>, int> jasenet;
    shared_ptr<Interface::Player> voittaja;

    for (shared_ptr<Interface::Location> paikka : peli_->locations())
    {
        shared_ptr<Interface::Councilor> jasen = paikka->councilor();
        unsigned int vaikutus = 0;
        shared_ptr<Interface::Player> valivoittaja;

        for (shared_ptr<Interface::Player> pelaaja : peli_->players())
        {
            pisteet.insert(std::pair<shared_ptr<Interface::Player>,int> {pelaaja,0});
            unsigned int valivaikutus = paikka->influence(pelaaja);
            qDebug() << "influencepöydässä: " << valivaikutus;

            for (shared_ptr<Interface::CardInterface> kortti: pelaaja->cards())
            {
                std::shared_ptr<Interface::Influence> card = std::dynamic_pointer_cast<Interface::Influence>(kortti);
                if (kortti->typeName() == "Influence")
                {
                    if (card->location().lock() == paikka)
                    {
                        valivaikutus += card->amount();
                    }
                }
            }
            if (valivaikutus > vaikutus)
            {
                jasen->setOwner(pelaaja);
                vaikutus = valivaikutus;
                valivoittaja = pelaaja;
            }
            pisteet.at(pelaaja) += valivaikutus;
        }
        if (valivoittaja != nullptr)
        {
            jasenet.insert(std::pair<shared_ptr<Interface::Player>,int> {valivoittaja,0});
            jasenet.at(valivoittaja) += 1;
        }
    }

    if (jasenet.size() != 0)
    {
        shared_ptr<Interface::Player> voittava;
        shared_ptr<Interface::Player> toinen;
        int eniten = -1;
        unsigned int laskuri = 0;
        bool onkoUseampi = false;
        for (auto player : jasenet)
        {
            if (player.second > eniten)
            {
                if (player.first != nullptr)
                {
                    eniten = player.second;
                    voittava = player.first;
                    onkoUseampi = false;
                    qDebug() << "voitto";
                }
            }
            else if (player.second == eniten)
            {
                onkoUseampi = true;
                ++laskuri;
                toinen = player.first;
                qDebug() << "tasan";
            }
        }
        if (toinen && jasenet.at(toinen) == jasenet.at(voittava))
        {
            if (laskuri != 3)
            {
                if (pisteet.at(voittava) > pisteet.at(toinen))
                {
                    voittaja = voittava;
                    qDebug() << "tasavoitto";
                }
                else
                {
                    voittaja = toinen;
                    qDebug() << "tasavoitto";
                }
            }
            else
            {
                int eniten = -1;
                for (auto member : pisteet)
                {
                    qDebug() << "kaikille yks";
                    if (member.second > eniten)
                    {
                        eniten = member.second;
                        voittaja = member.first;
                    }
                }
            }
        }
        else
        {
            voittaja = voittava;
        }

    }
    else
    {
        //tänne jos kukaan ei voita yhtään aluetta
    }
    if (voittaja != nullptr)
    {
        QString viesti = "Voittaja on " + voittaja->name();
        lopetin_ = new endDialog(viesti);
        lopetin_->show();
        this->close();
    }
    this->close();
}


void Akkuna::refreshUI()
{
    QString akkunakierroskyltti = "Kierros: " + QString::number((usedTurns+peli_->players().size())/peli_->players().size()) + "/15";
    ui->kierroslaskuri->setText(akkunakierroskyltti);
    if (usedTurns/peli_->players().size() >= 15)
    {
        laskeVoittaja();
    }

    for (unsigned int i = 0; i < peli_->locations().size(); ++i)
    {
        ActionNostaAgentti* testi = new ActionNostaAgentti(peli_, peli_->locations().at(i));
        Kaupunginosa *osa = dynamic_cast<Kaupunginosa*>(ui->kaupunkigrid->itemAt(i)->widget());
        if (testi->canPerform())
        {
            osa->enableButtons();
        }
        else
        {
            osa->hideButtons();
        }
    osa->paivitaInfluence();
    }

}

Akkuna::Akkuna(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Akkuna)
{
    ui->setupUi(this);
}

Akkuna::Akkuna(shared_ptr<Interface::Game> peli, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Akkuna),
    peli_(peli),
    usedTurns(0)
{
    ui->setupUi(this);
    kaupunginosat();
    refreshHandToCurrentPlayer();

}


void Akkuna::kaupunginosat()
{
    unsigned int gridkoko = 4;
    unsigned char row = 0;
    shared_ptr<Akkuna> tama = make_shared<Akkuna>(this);
    for(unsigned char i = 0; i < gridkoko; i++){
        row = i/2;
        Kaupunginosa* kaupunginosa = new Kaupunginosa(peli_,peli_->locations().at(i),tama,this);
        ui->kaupunkigrid->addWidget(kaupunginosa, row, i%2);

    }
}

void Akkuna::kaytaVuoro()
{
    ++usedTurns;
}

Akkuna::~Akkuna()
{
    delete ui;
}

void Akkuna::addPlayer(shared_ptr<Interface::Player> pelaaja){

}
