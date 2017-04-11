#include "action.h"


Action::Action()
{
}

Action::Action(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location)
{
    peli_ = peli;
    location_ = location;
}

Action::~Action()
{

}

bool Action::canPerform() const
{
    bool yes = true;
    return yes;
}

void Action::perform()
{

}

void Action::nostaKortti()
{
    if (location_->deck()->canDraw() & (peli_->currentPlayer()->cards().size() < 7))
    {
        peli_->currentPlayer()->addCard(location_->deck()->draw());
    }
    else
    {
        //qDebug << "KORTIT LOPPUSI";
    }
}

void Action::asetaAgentti()
{
    for (std::shared_ptr<Interface::CardInterface> card : peli_->currentPlayer()->cards())
    {
        if (card->typeName() == "Agent")
        {
            std::shared_ptr<Agent> kortti = std::dynamic_pointer_cast<Agent>(card);
            kortti->setPlacement(location_);
            peli_->currentPlayer()->playCard(card);

        }
    }
}

void Action::nostaAgentti()
{

}
