#ifndef AICONTROL_H
#define AICONTROL_H

#include "controlinterface.h"


class AIcontrol : Interface::ControlInterface
{
public:
    AIcontrol();
    virtual ~AIcontrol();
    virtual std::shared_ptr<Interface::ActionInterface> nextAction();

};

#endif // AICONTROL_H
