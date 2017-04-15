#ifndef KAUPUNGINOSA_H
#define KAUPUNGINOSA_H

#include <QWidget>
#include "location.h"
#include "game.h"
#include "pelicard.h"
#include "deckinterface.h"
#include <QDebug>
#include <QPixmap>
#include "agent.h"
#include "actionnostakortti.h"
#include "actionnostaagentti.h"
#include "actionasetaagentti.h"
#include "actionasetapelimerkki.h"
#include "actionagentillemerkki.h"
#include <memory>


class Akkuna;
namespace Ui {
class Kaupunginosa;
}

class Kaupunginosa : public QWidget
{
    Q_OBJECT

public:
    explicit Kaupunginosa(QWidget *parent = 0);
    explicit Kaupunginosa(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location, std::shared_ptr<QWidget> akkuna, QWidget *parent=0);
    ~Kaupunginosa();

    Kaupunginosa(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location, QWidget *parent=0);
    void hideButtons();
    void enableButtons();
    void paivitaAgentit();
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
    std::shared_ptr<QWidget> akkuna_;
    void poistaPelaajanAgentti();
    std::shared_ptr<Agent> etsiPelaajanKadestaAgentti();
};

#endif // KAUPUNGINOSA_H
