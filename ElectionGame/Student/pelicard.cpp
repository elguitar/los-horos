#include "pelicard.h"
#include "ui_pelicard.h"

#include "akkuna.h"

PeliCard::PeliCard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PeliCard)
{
    ui->setupUi(this);
}

PeliCard::PeliCard(shared_ptr<Interface::CardInterface> kortti, bool cardInHand, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PeliCard),
    kortti_(kortti)

{

    ui->setupUi(this);
    ui->kortinnimi->setText(kortti_->name());
    if(kortti->typeName() == "Agent"){
        agentconnections_ = std::dynamic_pointer_cast<Agent>(kortti)->connections();
        setConnections(agentconnections_);
    } else{
        short unsigned int influence = std::dynamic_pointer_cast<Interface::Influence>(kortti)->amount();
        ui->pelimerkit->setText(QString::number(influence));
    }
    setColour();
    if(cardInHand && kortti_->typeName() != "Agent"){
        QPushButton *button = new QPushButton("Discard", this);
        ui->horizontalLayout->addWidget(button);
        QObject::connect(button, SIGNAL(clicked()),
                          this, SLOT(discard()));
    }
}

void PeliCard::setConnections(int maara)
{
    ui->pelimerkit->setText(QString::number(maara));
}

void PeliCard::setColour()
{
    if (kortti_->typeName() == "Agent")
    {
        this->setStyleSheet("background-color:white;");
    }
    else
    {
        unsigned int id = std::dynamic_pointer_cast<Interface::Influence>(kortti_)->location().lock()->id();
        if (id == 1)
        {
            this->setStyleSheet("background-color:green;");
        }
        else if (id == 2)
        {
            this->setStyleSheet("background-color:pink;");
        }
        else if (id == 3)
        {
            this->setStyleSheet("background-color:grey;");
        }
        else if (id == 4)
        {
            this->setStyleSheet("background-color:brown;");
        }
    }
}

void PeliCard::discard()
{
    std::shared_ptr<Interface::Player> pleijjeri = kortti_->owner().lock();
    pleijjeri->playCard(kortti_);
    ((Akkuna*)this->parentWidget())->refreshUI();
    ((Akkuna*)this->parentWidget())->refreshHandToCurrentPlayer();
}

std::weak_ptr<Interface::Player> PeliCard::getOwner(){
    return kortti_->owner();
}

PeliCard::~PeliCard()
{
    delete ui;
}
