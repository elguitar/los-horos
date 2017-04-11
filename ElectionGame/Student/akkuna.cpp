#include "akkuna.h"
#include "ui_akkuna.h"

void Akkuna::asetaKorttiKateen(shared_ptr<Interface::CardInterface> kortti)
{
    qDebug() << "Kortti käteen. T: Akkuna";
    /*if(peli_->currentPlayer()->cards().size() < 7){
        ui->kasikortit->addWidget(new Pelikortti(kortti,kortti->typeName()));
    }*/
    if(ui->kasikortit->count() < 7){
        ui->kasikortit->addWidget(new Pelikortti(kortti,kortti->typeName()));
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

}


void Akkuna::kaupunginosat(bool pieniko)
{
    unsigned int gridkoko = 4;
    if(!pieniko){
        gridkoko = 4; // tähän pitää muuttaa suuren koko
    }
    unsigned char row = 0;
    for(unsigned char i = 0; i < gridkoko; i++){
        row = i/2;
        Kaupunginosa* kaupunginosa = new Kaupunginosa(peli_,peli_->locations().at(i));
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
