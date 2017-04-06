#ifndef AKKUNA_H
#define AKKUNA_H

#include <QWidget>
#include "player.h"
#include "game.h"
#include "location.h"
using std::make_shared;
using std::shared_ptr;

#include "kaupunginosa.h"
namespace Ui {
class Akkuna;
}

class Akkuna : public QWidget
{
    Q_OBJECT

public:
    explicit Akkuna(QWidget *parent = 0);
    explicit Akkuna(shared_ptr<Interface::Game> peli, int pelaajamaara, bool pieniko, QString pelaajanimi, QWidget *parent=0);
    void addPlayer(shared_ptr<Interface::Player> pelaaja);
    void kaupunginosat(bool pieniko);
    ~Akkuna();

private:
    Ui::Akkuna *ui;
    int pelaajat;
    bool onkoPieni;
    QString pelaajanNimi;
    shared_ptr<Interface::Game> peli_;
};

#endif // AKKUNA_H
