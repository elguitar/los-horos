#ifndef ACTIONNOSTAKORTTI_H
#define ACTIONNOSTAKORTTI_H

#include "actioninterface.h"
#include "player.h"
#include "agent.h"
#include "location.h"
#include "game.h"
#include "deck.h"
#include "cardinterface.h"

class ActionNostaKortti : Interface::ActionInterface
{
public:
    /**
     * @brief Rajapintaluokan oletusrakentaja (olemassa dokumentaatiota varten).
     */
    ActionNostaKortti();

    ActionNostaKortti(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location);


    /**
     * @brief Rajapintaluokassa on oletusarvoinen virtuaalipurkaja (olemassa, koska kantaluokalla tulee olla virtuaalipurkaja).
     */
    virtual ~ActionNostaKortti();

    /**
     * @brief canPerform kertoo, onko siirto tehtävissä
     * @pre -
     * @return tosi, joss siirto on tehtävissä
     * @post Poikkeustakuu: nothrow
     */
    virtual bool canPerform() const;

    /**
     * @brief perform suorittaa siirron
     * @pre siirto on tehtävissä
     * @post Poikkeustakuu: nothrow
     */
    virtual void perform();
    void nostaKortti();
private:
    std::shared_ptr<Interface::Location> location_;
    std::shared_ptr<Interface::Game> peli_;
};

#endif // ACTIONNOSTAKORTTI_H
