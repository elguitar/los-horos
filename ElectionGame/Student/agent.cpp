#include "agent.h"

Agent::Agent(const QString &name, const bool &common):
  name_(name),
  common_(common),
  connections_(0),
  place_(),
  owner_(),
  title_(),
  typename_()

{

}

QString Agent::typeName() const
{

}

QString Agent::name() const
{
    return name_;
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
