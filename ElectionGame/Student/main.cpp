#ifdef QT_NO_DEBUG_OUTPUT
#undef QT_NO_DEBUG_OUTPUT
#endif

#include "deckinterface.h"
#include "game.h"
#include "influence.h"
#include "location.h"
#include "akkuna.h"
#include "setupwindow.h"

#include <vector>

#include <QApplication>
#include <QWidget>

using Interface::Game;
using Interface::Influence;
using Interface::Location;
using Interface::Player;
using std::make_shared;
using std::shared_ptr;

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

        // set up cards for the location deck
        {
            // create an influence card and add it to location deck
            shared_ptr<Influence> influence1 = make_shared<Influence>(location1->name() + " Influence", location1, 1);
            location1->deck()->addCard(influence1);

            // TODO: create more cards

            // shuffle the deck
            location1->deck()->shuffle();
        }

        // TODO: create more locations
    }

    // set up players

    {
        // add a player to the game
        shared_ptr<Player> player1 = game->addPlayer("Player 1");

        // TODO: perform other player setup as necessary

        // TODO: create more players
    }

    // open the main window
    //window.addPlayer(playervector.at(0));
    a.exec();
}
