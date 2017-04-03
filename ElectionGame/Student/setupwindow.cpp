#include "setupwindow.h"
#include "ui_setupwindow.h"
#include <QDebug>


SetupWindow::SetupWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupWindow)
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
    if (ui->Nimimerkki->toPlainText().length() != 0 && ui->Pelaajat->value() != 0)
    {
        pelaajanNimi = ui->Nimimerkki->toPlainText();
        pelaajat = ui->Pelaajat->value();
        if (ui->Kentankoko->currentText() == "Pieni")
        {
            onkoPieni = true;
        }
        akkunaptr = new Akkuna(pelaajat, onkoPieni, pelaajanNimi);
        akkunaptr->show();
        close();

    }
    else
    {
        qDebug() << "setupwindown iffi vituillaa";
    }
}
