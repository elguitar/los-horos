#ifndef AGENT_H
#define AGENT_H

#include "agentinterface.h"
#include "stateexception.h"

/**
 * @file
 * @brief Määrittelee agenttikorttien luokan
 */
namespace Interface
{
class Player;
}

/**
 * @brief Agent määrittää agenttikortin.
 *
 * Agent on periytetty AgentInterface-rajapinnasta, joka on periytetty CardInterface-rajapinnasta eli sisältää ne molemmat.
 *
 * Jos luokan metodi ei ole poikkeustakuultaan nothrow, voi metodista aina vuotaa ulos poikkeus 'std::bad_alloc' (muisti loppui).
 *
 * @invariant jos (placement().lock() != nullptr) niin (connections() > 0) eli jos agentti pelilaudan alueella, sillä on suhteita
 */
class Agent: public Interface::AgentInterface
{
public:
    /**
     * @brief Luokan oletusrakentaja
     * @pre -
     * @param name, agentin nimi
     * @param common, määrittää, onko agentti pelattavissa kaikille alueille vai vain tietylle.
     * @post Agentti ei ole millään pelilaudan alueella ja sillä on nolla (0) suhdetta. Agentilla on nimi ja tieto commonisuudesta.
     */
    Agent(const QString &name, const bool &common);

   /**
    * @brief Luokan oletuspurkaja
    */
    virtual ~Agent() = default;
    /**
     * @brief typeName palauttaa kortin tyypin. Agentilla "Agent"
     * @pre -
     * @return QString "Agent"
     * @post Poikkeustakuu: nothrow
     */
    virtual QString typeName() const;
    /**
     * @brief name kertoo, mikä on agenttikortin nimi.
     * @pre -
     * @return QStringinä agentin nimi
     * @post Poikkeustakuu: nothrow
     */
    virtual QString name() const;
    /**
     * @brief title palauttaa agentin tittelin
     * @pre -
     * @return QString titteli
     * @post Poikkeustakuu: nothrow
     */
    virtual QString title() const;
    /**
     * @brief location kertoo, mille pelialueelle kortti kuuluu
     * @pre -
     * @return heikko osoitin locationiin
     * @post Poikkeustakuu: nothrow
     */
    virtual std::weak_ptr<Interface::Location> location() const;
    /**
     * @brief owner kertoo, kuka kortin omistaa
     * @pre -
     * @return heikko osoitin omistajaan, tyhjä osoitin jos omistajaa ei ole
     * @post Poikkeustakuu: nothrow
     */
    virtual std::weak_ptr<Interface::Player> owner() const;
    /**
     * @brief setOwner asettaa agentille omistajan
     * @pre -
     * @param owner, heikko osoitin omistajaan.
     * @post agentti tietää omistajansa
     * @post Poikkeustakuu: nothrow
     */
    virtual void setOwner(std::weak_ptr<Interface::Player> owner);
    /*!
     * @brief isCommon kertoo, onko kyseessä "geneerinen" agentti, joka ei liity mihinkään pelilaudan alueeseen
     * @pre -
     * @return tosi, joss agentti ei liity mihinkään pelilaudan alueeseen
     * @post Poikkeustakuu: nothrow
     */
    virtual bool isCommon() const;

    /**
     * @brief placement palauttaa tiedon agentin sijainnista
     * @pre -
     * @return heikko osoitin pelilaudan alueelle jossa agentti sijaitsee, tai tyhjä osoitin jos se ei ole laudalla
     * @post Poikkeustakuu: nothrow
     */
    virtual std::weak_ptr<Interface::Location> placement() const;
    /**
     * @brief setPlacement kertoo agentille millä pelialueella se on
     * @pre -
     * @param placement pelialue, tai tyhjä osoitin jos agentti ei ole laudalla
     * @post agentti tietää olevansa alueella
     * @post agentilla on yksi connection
     * @post Poikkeustakuu: nothrow
     */
    virtual void setPlacement(std::weak_ptr<Interface::Location> placement);
    /**
     * @brief connections kertoo suhteiden tason
     * @pre -
     * @return palauttaa suhteiden senhetkisen tilanteen
     * @post Poikkeustakuu: nothrow
     */
    virtual unsigned short connections() const;
    /**
     * @brief setConnections asettaa agentille suhteiden tason
     * @pre -
     * @param connections uusi suhteiden taso
     * @post suhteet ovat parametrin mukaiset
     * @post Poikkeustakuu: vahva
     * @exception GameException jos rikkoisi invariantin
     */
    virtual void setConnections(unsigned short connections);
    /**
     * @brief setConnections muuttaa agentin suhteiden tasoa
     * @pre -
     * @param change suhteiden muutos
     * @post suhteita on muutettu parametrin mukaisesti
     * @post Poikkeustakuu: vahva
     * @exception GameException jos rikkoisi invariantin
     */
    virtual void modifyConnections(short amount);
private:
    QString name_;
    QString title_;
    QString typename_;
    std::weak_ptr<Interface::Player> owner_;
    unsigned short connections_;
    bool common_;
    std::weak_ptr<Interface::Location> lokaatio_;
    std::weak_ptr<Interface::Location> pleismentti_;
    bool invariantti();

};

#endif // AGENT_H
