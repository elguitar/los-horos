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
}

SetupWindow::~SetupWindow()
{
    delete ui;
    delete akkunaptr;
}

void SetupWindow::aloita_peli()
{
    qDebug() << "connectworks";
    std::cout << "Moi" << endl;
    if (ui->Nimimerkki->toPlainText().length() != 0 && ui->Pelaajat->value() != 0)
    {
        pelaajanNimi = ui->Nimimerkki->toPlainText();
        pelaajat = ui->Pelaajat->value();
        if (ui->Kentankoko->currentText() == "Pieni")
        {
            onkoPieni = true;
        }
        akkunaptr = new Akkuna(peli_, pelaajat, onkoPieni, pelaajanNimi);
        akkunaptr->show();
        close();

    }
    else
    {
        qDebug() << "setupwindown ehto ei täyty";
    }
}
