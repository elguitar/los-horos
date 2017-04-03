#include "akkuna.h"
#include "ui_akkuna.h"

Akkuna::Akkuna(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Akkuna)
{
    ui->setupUi(this);
}

Akkuna::Akkuna(int pelaajamaara, bool pieniko, QString pelaajanimi, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Akkuna),
    pelaajanNimi(pelaajanimi)
{
    ui->setupUi(this);
}

Akkuna::~Akkuna()
{
    delete ui;
}

void Akkuna::addPlayer(shared_ptr<Interface::Player> pelaaja){
    ui->pekaajakyltti->setText(pelaaja->name());
}
