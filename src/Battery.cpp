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

void Battery::update(std::uint64_t nowMs)
{
    switch (state_)
    {
    case BatteryState::NoSlot:
        if(isInstalled_)
        {
            if(isFullycharged())
            {
                transitionTo(BatteryState::InSlotNotCharging, nowMs);
            }else
            {
                transitionTo(BatteryState::InSlotCharging, nowMs);   
            }
        }else if (chargeLevel_ > 60)
        {
           const std::uint64_t elapsedMs = nowMs -stateEntryTimeMs_;

           if(elapsedMs >= storageDelayMs_)
           {
                transitionTo(BatteryState::StorageDischarge, nowMs);
           }
        }
        break;
    case BatteryState::InSlotCharging:
        if(!isInstalled_)
        {
            transitionTo(BatteryState::NoSlot, nowMs);
        }
        else if(isFullycharged())
        {
            transitionTo(BatteryState::InSlotNotCharging, nowMs);
        }
        break;
    case BatteryState::InSlotNotCharging:
        if(!isInstalled_)
        {
            transitionTo(BatteryState::NoSlot, nowMs);
        }
        else if(!isFullycharged())
        {
            transitionTo(BatteryState::InSlotCharging, nowMs);
        }
        break;
    case BatteryState::StorageDischarge:
        if(isInstalled_)
        {
            if(isFullycharged())
            {
                transitionTo(BatteryState::InSlotNotCharging, nowMs);
            }
            else
            {
                 transitionTo(BatteryState::InSlotCharging, nowMs);
            }
        }
        else if (chargeLevel_ <= 60)
        {
            transitionTo(BatteryState::NoSlot, nowMs);
        }
        
        break;
    default:
        break;
    }
}

void Battery::transitionTo(BatteryState newState, std::uint64_t nowMs)
{
    state_ = newState;
    stateEntryTimeMs_ = nowMs;
}