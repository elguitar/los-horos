#include "setupwindow.h"
#include "ui_setupwindow.h"
#include <QDebug>
#include <iostream>

SetupWindow::SetupWindow(shared_ptr<Interface::Game> peli, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupWindow),
    peli_(peli)
{
    ui->setupUi(this);
    QObject::connect(ui->Aloitabutton, SIGNAL(clicked()),
                      this, SLOT(aloita_peli()));
    QObject::connect(ui->Suljebutton, SIGNAL(clicked()),
                     this, SLOT(sulje_peli()));
}

SetupWindow::~SetupWindow()
{
    delete ui;
    delete akkunaptr;
}

void SetupWindow::sulje_peli()
{
    ((QApplication*)this->parentWidget())->closeAllWindows();
}

void SetupWindow::aloita_peli()
{
    qDebug() << "connectworks";
    if (teePelaajat())
    {
        akkunaptr = new Akkuna(peli_, pelaajat, onkoPieni, pelaajanNimi);
        akkunaptr->show();
        close();

    }
    else
    {
        qDebug() << "setupwindown ehto ei täyty";
    }
}

bool SetupWindow::teePelaajat()
{
    std::vector<std::pair<QString,QString> > valtuustovektori = { {"Mikko", "Metsuri"},
                                                                  {"Linda", "Sukeltaja"},
                                                                  {"Jesse","Stud"},
                                                                  {"Anneli","Putkinainen"} };
    unsigned int pelaajaLaskuri = 0;
    for (unsigned i = 0; i < 4; ++i)
    {
        QWidget* widket = ui->playerLayout->itemAt(i, QFormLayout::FieldRole)->widget();
        shared_ptr<Interface::Location> paikka = peli_->locations().at(i);
        shared_ptr<Interface::Councilor> jasen = make_shared<Interface::Councilor>
                (valtuustovektori.at(i).first,
                 valtuustovektori.at(i).second,
                 peli_->locations().at(i));
        if (dynamic_cast<QLineEdit*>(widket)->text() != "")
        {
            pelaajaLaskuri += 1;
            QString pelaaja = dynamic_cast<QLineEdit*>(widket)->text();
            shared_ptr<Interface::Player> player = peli_->addPlayer(pelaaja);

            player->setCouncilor(jasen);

            for (int i = 0; i < 3; ++i)
            {
                shared_ptr<Agent> agentti = make_shared<Agent>("agentti" + QString::number(i+1),true);
                player->addCard(agentti);

            }
        }
        paikka->setCouncilor(jasen);
    }
    if (pelaajaLaskuri > 1)
    {
        return true;
    }
    return false;
}
