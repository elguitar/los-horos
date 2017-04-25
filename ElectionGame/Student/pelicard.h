#ifndef PELICARD_H
#define PELICARD_H

#include <QFrame>
#include <QPushButton>
#include "game.h"
#include "cardinterface.h"
using std::make_shared;
using std::shared_ptr;
#include "agent.h"
#include "influence.h"
#include "player.h"

namespace Ui {
class PeliCard;
}

class PeliCard : public QFrame
{
    Q_OBJECT

public:
    explicit PeliCard(QWidget *parent = 0);
    explicit PeliCard(shared_ptr<Interface::CardInterface> kortti, bool cardInHand = 0, QWidget *parent = 0);
    ~PeliCard();


    std::weak_ptr<Interface::Player> getOwner();
    void setConnections(int maara);

public slots:
    void discard();

private:
    Ui::PeliCard *ui;
    shared_ptr<Interface::CardInterface> kortti_;
    unsigned short agentconnections_;

};

#endif // PELICARD_H
