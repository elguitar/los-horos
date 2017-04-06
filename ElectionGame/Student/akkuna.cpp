#include "akkuna.h"
#include "ui_akkuna.h"

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
    unsigned int gridkoko = 4;
    if(!pieniko){
        gridkoko = 4; // tähän pitää muuttaa suuren koko
    }
    unsigned char row = 0;
    for(unsigned char i = 0; i < gridkoko; i++){
        row = i/2;
        QLabel* kaupunginosa = new QLabel;
        kaupunginosa->setText(peli_->locations().at(0)->name());
        ui->kaupunkigrid->addWidget(kaupunginosa,row,i%2);

    }
}

Akkuna::kaupunginosat()
{


}

Akkuna::~Akkuna()
{
    delete ui;
}

void Akkuna::addPlayer(shared_ptr<Interface::Player> pelaaja){
    ui->pekaajakyltti->setText(pelaaja->name());
}
