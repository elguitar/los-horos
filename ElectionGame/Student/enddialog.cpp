#include "enddialog.h"
#include "ui_enddialog.h"

endDialog::endDialog(QString viesti, QWidget *parent) :
    QDialog(parent),
    viesti_(viesti),
    ui(new Ui::endDialog)
{
    ui->setupUi(this);
    ui->teksti->setText(viesti_);
    QObject::connect(ui->endButton, SIGNAL(clicked()),
                this, SLOT(suljePeli()));
}

void endDialog::suljePeli()
{
    this->close();

}

endDialog::~endDialog()
{
    delete ui;
}
