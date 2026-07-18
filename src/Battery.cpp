#include "Battery.h"

Battery::Battery()
{

}

bool Battery::setChargeLevel(std::uint8_t level)
{
    if(level > 100)
    {
        return false;
    }

    chargeLevel_ = level;
    return true;

}

void Battery::installInSlot()
{
    isInstalled_ = true;
}

void Battery::removeFromSlot()
{
    isInstalled_ = false;
}

std::uint8_t Battery::getChargeLevel() const
{
    return chargeLevel_;
}

bool Battery::isInstalled() const
{
    return isInstalled_;
}

bool Battery::isFullycharged() const
{
    return chargeLevel_ == 100;
}

BatteryState Battery::getState() const
{
    return state_;
}

void Battery::update()
{
    switch (state_)
    {
    case BatteryState::NoSlot:
        if(isInstalled_)
        {
            if(isFullycharged())
            {
                transitionTo(BatteryState::InSlotNotCharging);
            }else
            {
                transitionTo(BatteryState::InSlotCharging);   
            }
        }
        break;
    case BatteryState::InSlotCharging:
        if(!isInstalled_)
        {
            transitionTo(BatteryState::NoSlot);
        }
        else if(isFullycharged())
        {
            transitionTo(BatteryState::InSlotNotCharging);
        }
        break;
    case BatteryState::InSlotNotCharging:
        if(!isInstalled_)
        {
            transitionTo(BatteryState::NoSlot);
        }
        else if(!isFullycharged())
        {
            transitionTo(BatteryState::InSlotCharging);
        }
        break;
    default:
        break;
    }
}

void Battery::transitionTo(BatteryState newState)
{
    state_ = newState;
}