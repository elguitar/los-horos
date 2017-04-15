#ifndef ENDDIALOG_H
#define ENDDIALOG_H

#include <QDialog>

namespace Ui {
class endDialog;
}

class endDialog : public QDialog
{
    Q_OBJECT

public:
    explicit endDialog(QString viesti, QWidget *parent = 0);

    ~endDialog();

public slots:
    void suljePeli();
private:
    Ui::endDialog *ui;
    QString viesti_;
};

#endif // ENDDIALOG_H
