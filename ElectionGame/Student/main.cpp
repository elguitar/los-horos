#ifdef QT_NO_DEBUG_OUTPUT
#undef QT_NO_DEBUG_OUTPUT
#endif

#include "deckinterface.h"
#include "game.h"
#include "influence.h"
#include "location.h"
#include "akkuna.h"
#include "setupwindow.h"
#include "agent.h"
#include "manualcontrol.h"
#include "runner.h"

#include <vector>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QApplication>
#include <QWidget>


using Interface::Game;
using Interface::Influence;
using Interface::Location;
using Interface::Player;
using std::make_shared;
using std::shared_ptr;


void addLocations(shared_ptr<Game> game);
void addCards(shared_ptr<Game> game);
void readInfluenceCards(shared_ptr<Game> game);
/*
 * The main program should initialize the game and open the main window, or
 * delegate these tasks elsewhere.
 */
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // create a game object
    shared_ptr<Game> game = make_shared<Game>();
    SetupWindow setuppiwindow(game);
    setuppiwindow.show();

    // set up locations of the board
    {
        // create and initialize a location, and add it to the game
        addLocations(game);

        // set up cards for the location deck
        {
            addCards(game);
        }

        // TODO: create more locations
    }

    // set up players

    {
        Interface::Runner runnaaja(game);
        // add a player to the game
        shared_ptr<Agent> kasiakentti = make_shared<Agent>("kasiakentti",true);
        shared_ptr<Player> player1 = game->addPlayer("Player 1");
        player1->addCard(kasiakentti);
        shared_ptr<Interface::ManualControl> pelaajakontrolli;
        runnaaja.setPlayerControl(player1,pelaajakontrolli);


        // TODO: perform other player setup as necessary

        // TODO: create more players
    }

    // open the main window
    //window.addPlayer(playervector.at(0));
    a.exec();
}

void addLocations(shared_ptr<Game> game)
{
    shared_ptr<Location> location1 = make_shared<Location>(1, "Metsämiesten kilta");
    shared_ptr<Location> location2 = make_shared<Location>(2, "Hengenpelastajatytöt");
    shared_ptr<Location> location3 = make_shared<Location>(3, "Kaupungin kuumakulmakundit");
    shared_ptr<Location> location4 = make_shared<Location>(4, "Kallion huolestuneet kansalaiset");
    location1->initialize();
    game->addLocation(location1);
    location2->initialize();
    game->addLocation(location2);
    location3->initialize();
    game->addLocation(location3);
    location4->initialize();
    game->addLocation(location4);
}

void addCards(shared_ptr<Game> game)
{
    // create influence cards and add them to location deck
    readInfluenceCards(game);

    // TODO: create more cards
    shared_ptr<Agent> agentti = make_shared<Agent>("koeakentti",true);
    location1->deck()->addCard(agentti);

    // shuffle the deck
    location1->deck()->shuffle();
}

void readInfluenceCards(shared_ptr<Game> game)
{
    QString kortit;
    QFile file;
    QString path = QDir::currentPath();
    path.append("/influence.json");
    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    kortit = file.readAll();
    file.close();

    QJsonDocument sd = QJsonDocument::fromJson(kortit.toUtf8());
    qWarning() << sd.isNull(); // <- print false :)
    QJsonObject sett2 = sd.object();
    for (unsigned int i = 0; i < 3; ++i)
    {
    QJsonArray jsonArray = sett2[QString::number(i)].toArray();

        shared_ptr<Location> location = game->locations().at(i);
        foreach (const QJsonValue & value, jsonArray)
        {
            QJsonObject obj = value.toObject();
            shared_ptr<Influence> uusiKortti = make_shared<Influence>(obj["nimi"].toString(), location, obj["vaikutus"].toInt());
            location->deck()->addCard(uusiKortti);
        }

    }
}

