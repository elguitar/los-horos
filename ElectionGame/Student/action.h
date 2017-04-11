#ifndef ACTION_H
#define ACTION_H

#include "actioninterface.h"
#include "kaupunginosa.h"
#include "player.h"
#include "agent.h"
#include "cardinterface.h"


class Action: public Interface::ActionInterface
{
public:
    /**
     * @brief Rajapintaluokan oletusrakentaja (olemassa dokumentaatiota varten).
     */
    Action();

    Action(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location);


    /**
     * @brief Rajapintaluokassa on oletusarvoinen virtuaalipurkaja (olemassa, koska kantaluokalla tulee olla virtuaalipurkaja).
     */
    virtual ~Action();

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
    void asetaAgentti();
    void nostaAgentti();
private:
    std::shared_ptr<Interface::Location> location_;
    std::shared_ptr<Interface::Game> peli_;
};

#endif // ACTION_H
