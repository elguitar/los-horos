#include "agent.h"


QString Agent::typeName() const
{

}

QString Agent::name() const
{

}

QString Agent::title() const
{

}

std::weak_ptr<Interface::Location> Agent::location() const
{

}

std::weak_ptr<Interface::Player> Agent::owner() const
{

}

void Agent::setOwner(std::weak_ptr<Interface::Player> owner)
{

}

bool Agent::isCommon() const
{

}

std::weak_ptr<Interface::Location> Agent::placement() const
{

}

void Agent::setPlacement(std::weak_ptr<Interface::Location> placement)
{

}

unsigned short Agent::connections() const
{

}

void Agent::setConnections(unsigned short connections)
{

}

void Agent::modifyConnections(short amount)
{

}
