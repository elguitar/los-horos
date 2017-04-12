#include "actionagentillemerkki.h"

ActionAgentilleMerkki::ActionAgentilleMerkki()
{

}

ActionAgentilleMerkki::ActionAgentilleMerkki(std::shared_ptr<Interface::Game> peli, std::shared_ptr<Interface::Location> location)
{
    peli_ = peli;
    location_ = location;
}

ActionAgentilleMerkki::~ActionAgentilleMerkki()
{

}

bool ActionAgentilleMerkki::canPerform() const
{
    return true;
}

void ActionAgentilleMerkki::perform()
{
    for (unsigned int i = 0; i < location_->agents().size(); ++i)
    {
        //std::set<std::shared_ptr<Interface::AgentInterface> >::iterator = location_->agents().begin();
        std::shared_ptr<Interface::AgentInterface> agentti = *std::next(location_->agents().begin(), i);

        std::shared_ptr<Interface::Player> agentinOmistaja = agentti->owner().lock();
        if (agentinOmistaja == peli_->currentPlayer())
        {
            unsigned int oldconnections = agentti->connections();
            agentti->setConnections(oldconnections + 1);
        }
    }
}
