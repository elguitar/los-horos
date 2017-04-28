#include "actionnostakortti.h"


ActionNostaKortti::ActionNostaKortti()
{
}

ActionNostaKortti::ActionNostaKortti(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location)
{
    peli_ = peli;
    location_ = location;
}

ActionNostaKortti::~ActionNostaKortti()
{

}

bool ActionNostaKortti::canPerform() const
{
    return location_->deck()->canDraw() && peli_->currentPlayer()->cards().size() < 7;
}

void ActionNostaKortti::perform()
{
    if (location_->deck()->canDraw() & (peli_->currentPlayer()->cards().size() < 7))
    {
        peli_->currentPlayer()->addCard(location_->deck()->draw());
    }
}
