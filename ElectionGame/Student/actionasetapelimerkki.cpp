#include "actionasetapelimerkki.h"

ActionAsetaPelimerkki::ActionAsetaPelimerkki()
{

}

ActionAsetaPelimerkki::ActionAsetaPelimerkki(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location)
{
    peli_ = peli;
    location_ = location;
}

ActionAsetaPelimerkki::~ActionAsetaPelimerkki()
{

}

bool ActionAsetaPelimerkki::canPerform() const
{
    return true;
}

void ActionAsetaPelimerkki::perform()
{
    unsigned int oldinfluence = location_->influence(peli_->currentPlayer());

    for (std::shared_ptr<Interface::Player> pelaaja : peli_->players()) {
        for (std::shared_ptr<Interface::AgentInterface> agentti : location_->agents())
        {
            if (agentti->owner().lock() == peli_->currentPlayer())
            {
                if (agentti->connections() == 2)
                {
                    location_->setInfluence(peli_->currentPlayer(), oldinfluence + 2);
                }
                else
                {
                    location_->setInfluence(peli_->currentPlayer(), oldinfluence + 1);
                }
            }
        }

    }

}
