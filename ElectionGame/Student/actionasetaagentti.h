#ifndef ACTIONASETAAGENTTI_H
#define ACTIONASETAAGENTTI_H

#include "actioninterface.h"
#include "game.h"
#include "location.h"
#include "player.h"
#include "agent.h"
#include "cardinterface.h"


class ActionAsetaAgentti : Interface::ActionInterface
{
public:
    ActionAsetaAgentti();

    ActionAsetaAgentti(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location);


    /**
     * @brief Rajapintaluokassa on oletusarvoinen virtuaalipurkaja (olemassa, koska kantaluokalla tulee olla virtuaalipurkaja).
     */
    virtual ~ActionAsetaAgentti();

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

private:
    std::shared_ptr<Interface::Location> location_;
    std::shared_ptr<Interface::Game> peli_;
};

#endif // ACTIONASETAAGENTTI_H
