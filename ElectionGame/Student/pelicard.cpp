#include "pelicard.h"
#include "ui_pelicard.h"

PeliCard::PeliCard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PeliCard)
{
    ui->setupUi(this);
}

PeliCard::PeliCard(shared_ptr<Interface::CardInterface> kortti, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PeliCard),
    kortti_(kortti)

{

    ui->setupUi(this);
    ui->kortinnimi->setText(kortti_->name());
    if(kortti->typeName() == "Agent"){
        agentconnections_ = std::dynamic_pointer_cast<Agent>(kortti)->connections();
        ui->pelimerkit->setText(QString::number(agentconnections_));
        //ui->pelimerkit->setText(QString::number(1));
    } else{
        ui->pelimerkit->setText("");
    }
}

std::weak_ptr<Interface::Player> PeliCard::getOwner(){
    return kortti_->owner();
}

PeliCard::~PeliCard()
{
    delete ui;
}
