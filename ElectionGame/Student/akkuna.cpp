#include "akkuna.h"
#include "ui_akkuna.h"

void Akkuna::asetaKorttiKateen(shared_ptr<Interface::CardInterface> kortti)
{
    qDebug() << "Kortti käteen. T: Akkuna";
    /*if(peli_->currentPlayer()->cards().size() < 7){
        ui->kasikortit->addWidget(new Pelikortti(kortti,kortti->typeName()));
    }*/
    if(ui->kasikortit->count() < 7){
        ui->kasikortit->addWidget(new Pelikortti(kortti));
    }
}

void Akkuna::refreshHandToCurrentPlayer()
{
    peli_->nextPlayer();
    shared_ptr<Interface::Player> pelaaja = peli_->currentPlayer();
    std::vector<std::shared_ptr<Interface::CardInterface> > kortit = pelaaja->cards();
    /*while(ui->kasikortit->children().size() != 0){
        ui->kasikortit->removeItem(ui->kasikortit->itemAt(0));
    }
    ui->kasikortit->lay*/
    QLayoutItem *item;
    while((item = ui->kasikortit->takeAt(0))){
        delete item->widget();
        delete item;
    }
    if(kortit.size() > 0){
        unsigned int counter = 1;
        for (auto it = kortit.begin(); it != kortit.end(); ++it){
            ui->kasikortit->addWidget(new Pelikortti(*it));
        }
    }
}

Akkuna::Akkuna(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Akkuna)
{
    ui->setupUi(this);
}

Akkuna::Akkuna(shared_ptr<Interface::Game> peli, int pelaajamaara, bool pieniko, QString pelaajanimi, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Akkuna),
    pelaajanNimi(pelaajanimi),
    peli_(peli)
{
    ui->setupUi(this);
    kaupunginosat(pieniko);
    refreshHandToCurrentPlayer();

}


void Akkuna::kaupunginosat(bool pieniko)
{
    unsigned int gridkoko = 4;
    if(!pieniko){
        gridkoko = 4; // tähän pitää muuttaa suuren koko
    }
    unsigned char row = 0;
    shared_ptr<Akkuna> tama = make_shared<Akkuna>(this);
    for(unsigned char i = 0; i < gridkoko; i++){
        row = i/2;
        //Kaupunginosa* kaupunginosa = new Kaupunginosa(peli_,peli_->locations().at(i));
        Kaupunginosa* kaupunginosa = new Kaupunginosa(peli_,peli_->locations().at(i),tama,this);
        //kaupunginosa->setText(peli_->locations().at(i)->name());
        //ui->kaupunkigrid->addWidget(kaupunginosa,row,i%2);
        ui->kaupunkigrid->addWidget(kaupunginosa, row, i%2);

    }
}

Akkuna::~Akkuna()
{
    delete ui;
}

void Akkuna::addPlayer(shared_ptr<Interface::Player> pelaaja){

}
