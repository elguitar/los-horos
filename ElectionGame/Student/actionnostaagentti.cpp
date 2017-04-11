#include "actionnostaagentti.h"

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

}

void ActionNostaAgentti::perform()
{

}
