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
    uint oldinfluence = location_->influence(peli_->currentPlayer());

    location_->setInfluence(peli_->currentPlayer(), oldinfluence + 1);

    //if-lauseella jos agentilla merkkejä, tehokkaampi operaatio
    //location_->setInfluence(peli_->currentPlayer(), oldinfluence + 2);
}
