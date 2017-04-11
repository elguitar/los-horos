#ifndef ACTION_H
#define ACTION_H

#include "actioninterface.h"


class Action: public Interface::ActionInterface
{
public:
    /**
     * @brief Rajapintaluokan oletusrakentaja (olemassa dokumentaatiota varten).
     */
    Action();


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
};

#endif // ACTION_H
