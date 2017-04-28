#include "actionasetaagentti.h"

ActionAsetaAgentti::ActionAsetaAgentti()
{

}

ActionAsetaAgentti::ActionAsetaAgentti(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location)
{
    peli_ = peli;
    location_ = location;
}

ActionAsetaAgentti::~ActionAsetaAgentti()
{

}

bool ActionAsetaAgentti::canPerform() const
{
    if (!(location_->canSendAgent(peli_->currentPlayer())) || location_->agents().size() > 2)
    {
        return false;
    }


    for (std::shared_ptr<Interface::CardInterface> card : peli_->currentPlayer()->cards())
    {
        if (card->typeName() == "Agent")
        {
            return true;
        }
    }
    return false;
}

void ActionAsetaAgentti::perform()
{
    for (std::shared_ptr<Interface::CardInterface> card : peli_->currentPlayer()->cards())
    {
        if (card->typeName() == "Agent")
        {
            std::shared_ptr<Agent> kortti = std::dynamic_pointer_cast<Agent>(card);
            kortti->setPlacement(location_);
            location_->sendAgent(kortti);
            peli_->currentPlayer()->playCard(card);
            break;
        }
    }
}
