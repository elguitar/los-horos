#include "actionnostaagentti.h"
#include <QDebug>

ActionNostaAgentti::ActionNostaAgentti()
{

}

ActionNostaAgentti::ActionNostaAgentti(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location)
{
    peli_ = peli;
    location_ = location;
}

ActionNostaAgentti::~ActionNostaAgentti()
{

}

bool ActionNostaAgentti::canPerform() const
{
    if (peli_->currentPlayer()->cards().size() < 7)
    {
        for (uint i = 0; i < location_->agents().size(); ++i)
        {
            //std::set<std::shared_ptr<Interface::AgentInterface> >::iterator = location_->agents().begin();
            std::shared_ptr<Interface::AgentInterface> agentti = *std::next(location_->agents().begin(), i);

            std::shared_ptr<Interface::Player> agentinOmistaja = agentti->owner().lock();
            if (agentinOmistaja == peli_->currentPlayer())
            {
                return true;
            }
        }

    }
    else
    {
       return false;
    }
    return false;
}

void ActionNostaAgentti::perform()
{
    //for (std::shared_ptr<Agent> agentti : location_->agents())
    for (uint i = 0; i < location_->agents().size(); ++i)
    {
        //std::set<std::shared_ptr<Interface::AgentInterface> >::iterator = location_->agents().begin();
        std::shared_ptr<Interface::AgentInterface> agentti = *std::next(location_->agents().begin(), i);

        std::shared_ptr<Interface::Player> agentinOmistaja = agentti->owner().lock();
        if (agentinOmistaja == peli_->currentPlayer())
        {
            peli_->currentPlayer()->addCard(agentti);
            location_->removeAgent(agentti);
            agentti->setConnections(0);
            qDebug() << "Agentti poistettu";
        }
    }
}
