#ifndef AKKUNA_H
#define AKKUNA_H

#include <QWidget>
#include "player.h"
#include "game.h"
#include "location.h"
using std::make_shared;
using std::shared_ptr;

#include "kaupunginosa.h"
#include "influence.h"
#include "councilor.h"
#include "enddialog.h"

namespace Ui {
class Akkuna;
class endDialog;
}

class Akkuna : public QWidget
{
    Q_OBJECT

public slots:
    void asetaKorttiKateen(shared_ptr<Interface::CardInterface> kortti);
    void refreshHandToCurrentPlayer();
    void refreshUI();

public:
    explicit Akkuna(QWidget *parent = 0);
    explicit Akkuna(shared_ptr<Interface::Game> peli, QWidget *parent=0);
    void addPlayer(shared_ptr<Interface::Player> pelaaja);
    void kaupunginosat();
    ~Akkuna();

    void laskeVoittaja();
private:
    Ui::Akkuna *ui;
    endDialog *lopetin_;
    unsigned int usedTurns;
    shared_ptr<Interface::Game> peli_;
};

#endif // AKKUNA_H
