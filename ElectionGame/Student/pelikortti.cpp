#include "pelikortti.h"
#include "ui_pelikortti.h"

Pelikortti::Pelikortti(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pelikortti)
{
    ui->setupUi(this);
}

Pelikortti::Pelikortti(shared_ptr<Interface::CardInterface> kortti, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pelikortti),
    kortti_(kortti)

{
    ui->setupUi(this);
    ui->kortinnimi->setText(kortti_->name());
    ui->pelaaja->setText(kortti_->owner().lock()->name());
}

Pelikortti::Pelikortti(shared_ptr<Agent> kortti, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pelikortti),
    kortti_(kortti)

{
    if(kortti->typeName() == "Agent"){
        shared_ptr<Agent> tempagent = std::dynamic_pointer_cast<Agent>(kortti);
        agentconnections_ = tempagent->connections();
        //ui->pelimerkit->setText(QString::number(agentconnections_));
        //ui->pelimerkit->setText(QString::number(1));
    }
    ui->setupUi(this);
    ui->kortinnimi->setText(kortti_->name());
    ui->pelaaja->setText(kortti_->owner().lock()->name());
}

Pelikortti::~Pelikortti()
{
    delete ui;
}
