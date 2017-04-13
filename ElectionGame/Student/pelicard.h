#ifndef PELICARD_H
#define PELICARD_H

#include <QFrame>
#include "game.h"
#include "cardinterface.h"
using std::make_shared;
using std::shared_ptr;
#include "agent.h"
#include "player.h"

namespace Ui {
class PeliCard;
}

class PeliCard : public QFrame
{
    Q_OBJECT

public:
    explicit PeliCard(QWidget *parent = 0);
    explicit PeliCard(shared_ptr<Interface::CardInterface> kortti, QWidget *parent = 0);
    ~PeliCard();


    std::weak_ptr<Interface::Player> getOwner();
private:
    Ui::PeliCard *ui;
    shared_ptr<Interface::CardInterface> kortti_;
    QString tyyppi_;
    unsigned short agentconnections_;

};

#endif // PELICARD_H
