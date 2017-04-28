#include "agent.h"

Agent::Agent(const QString &name, const bool &common):
  name_(name),
  common_(common),
  connections_(0),
  pleismentti_(),
  lokaatio_(),
  owner_(),
  title_(),
  typename_()

{

}

QString Agent::typeName() const
{
    return "Agent";
}

QString Agent::name() const
{
    return name_;
}

QString Agent::title() const
{
    return title_;
}

std::weak_ptr<Interface::Location> Agent::location() const
{
    return lokaatio_;
}

std::weak_ptr<Interface::Player> Agent::owner() const
{
    return owner_;
}

void Agent::setOwner(std::weak_ptr<Interface::Player> owner)
{
    owner_ = owner;
}

bool Agent::isCommon() const
{
    return common_;
}

std::weak_ptr<Interface::Location> Agent::placement() const
{
    return pleismentti_;
}

void Agent::setPlacement(std::weak_ptr<Interface::Location> placement)
{
    pleismentti_ = placement;
    if(placement.lock() != nullptr){
        connections_ = 1;
    }
}

unsigned short Agent::connections() const
{
    return connections_;
}

void Agent::setConnections(unsigned short connections)
{
    connections_ = connections;
}

void Agent::modifyConnections(short amount)
{
    connections_ = amount;
}
