// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "ArmSwing.hpp"

namespace teo
{

/************************************************************************/

bool ArmSwing::configure(yarp::os::ResourceFinder &rf)
{
    yarp::os::Property options;
    options.put("device","remote_controlboard");
    options.put("remote","/teo/leftArm");
    options.put("local","/local");
    dd.open(options);
    if(!dd.isValid()) {
      printf("RaveBot device not available.\n");
      dd.close();
      yarp::os::Network::fini();
      return 1;
    }

    bool ok = dd.view(pos);
    if (!ok) {
        printf("[warning] Problems acquiring robot interface\n");
        return false;
    } else printf("[success] testAsibot acquired robot interface\n");
    pos->setPositionMode();

    phase = false;

    return true;
}

/************************************************************************/

bool ArmSwing::interruptModule()
{
    dd.close();
    return true;
}

/************************************************************************/

double ArmSwing::getPeriod()
{
    return 2.0; // Fixed, in seconds, the slow thread that calls updateModule below
}

/************************************************************************/

bool ArmSwing::updateModule()
{
    if(phase)
    {
        pos->positionMove(0, 10);
    }
    else
    {
        pos->positionMove(0, 10);
    }

    return true;
}

/************************************************************************/

}  // namespace teo

//printf("test positionMove(1,-35)\n");
//yarp::os::Time::delay(5);
