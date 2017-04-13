#ifndef PELIKORTTI_H
#define PELIKORTTI_H

#include <QWidget>
#include "game.h"
#include "cardinterface.h"
using std::make_shared;
using std::shared_ptr;
#include "agent.h"
#include "player.h"

namespace Ui {
class Pelikortti;
}

class Pelikortti : public QWidget
{
    Q_OBJECT

public:
    explicit Pelikortti(QWidget *parent = 0);
    explicit Pelikortti(shared_ptr<Interface::CardInterface> kortti, QWidget *parent = 0);
    explicit Pelikortti(shared_ptr<Agent> kortti, QWidget *parent=0);

    ~Pelikortti();

private:
    Ui::Pelikortti *ui;
    shared_ptr<Interface::CardInterface> kortti_;
    QString tyyppi_;
    unsigned short agentconnections_;
};

#endif // PELIKORTTI_H
