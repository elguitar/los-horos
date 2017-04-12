#ifndef KAUPUNGINOSA_H
#define KAUPUNGINOSA_H

#include <QWidget>
#include "location.h"
#include "game.h"
#include "pelikortti.h"
#include "deckinterface.h"
#include <QDebug>
#include <QPixmap>
#include "agent.h"
#include "actionnostakortti.h"
#include "actionnostaagentti.h"
#include "actionasetaagentti.h"
#include "actionasetapelimerkki.h"
#include "actionagentillemerkki.h"
#include "akkuna.h"

namespace Ui {
class Kaupunginosa;
}

class Kaupunginosa : public QWidget
{
    Q_OBJECT

public:
    explicit Kaupunginosa(QWidget *parent = 0);
    explicit Kaupunginosa(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location, QWidget *parent=0);
    ~Kaupunginosa();

public slots:
    void nostaKortti();
    void nostaAgentti();
    void asetaAgentti();
    void asetaPelimerkki();

    void asetaPakkakuvat();
    void agentilleMerkki();
private:
    Ui::Kaupunginosa *ui;
    std::shared_ptr<Interface::Location> location_;
    std::vector<std::shared_ptr<Agent> > agentit_;
    std::shared_ptr<Interface::Game> peli_;
};

#endif // KAUPUNGINOSA_H
