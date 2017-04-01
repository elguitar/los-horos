#ifndef SETUPWINDOW_H
#define SETUPWINDOW_H

#include <QDialog>
#include "akkuna.h"

namespace Ui {
class SetupWindow;
}

class SetupWindow : public QDialog
{
    Q_OBJECT


public:
    explicit SetupWindow(QWidget *parent = 0);
    ~SetupWindow();

public slots:
    void aloita_peli();

private:
    Ui::SetupWindow *ui;
    int pelaajat;
    bool onkoPieni = false;
    QString pelaajanNimi;
};

#endif // SETUPWINDOW_H
