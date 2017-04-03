#ifndef SETUPWINDOW_H
#define SETUPWINDOW_H

#include <QDialog>
#include "akkuna.h"
#include "game.h"

namespace Ui {
class SetupWindow;
}

class SetupWindow : public QDialog
{
    Q_OBJECT


public:
    explicit SetupWindow(shared_ptr<Interface::Game> peli, QWidget *parent = 0);
    ~SetupWindow();

public slots:
    void aloita_peli();

private:
    Ui::SetupWindow *ui;
    int pelaajat;
    bool onkoPieni = false;
    QString pelaajanNimi;
    Akkuna* akkunaptr;
    shared_ptr<Interface::Game> peli_;
};

#endif // SETUPWINDOW_H
