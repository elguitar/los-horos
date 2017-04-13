#include "pelikortti.h"
#include "ui_pelikortti.h"

#include <QDebug>
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
    if(kortti->typeName() == "Agent"){
        agentconnections_ = std::dynamic_pointer_cast<Agent>(kortti)->connections();
        ui->pelimerkit->setText(QString::number(agentconnections_));
        //ui->pelimerkit->setText(QString::number(1));
    }
}

Pelikortti::~Pelikortti()
{
    delete ui;
}
