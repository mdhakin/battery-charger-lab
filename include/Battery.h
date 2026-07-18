#pragma once

#include <cstdint>

enum class BatteryState
{
    NoSlot,
    InSlotCharging,
    InSlotNotCharging
};

class Battery
{
    public:
        Battery();

        bool setChargeLevel(std::uint8_t level);
        void installInSlot();
        void removeFromSlot();

        void update();

        [[nodiscard]] std::uint8_t getChargeLevel() const;
        [[nodiscard]] bool isInstalled() const;
        [[nodiscard]] bool isFullycharged() const;
        [[nodiscard]] BatteryState getState() const;

    private:
        BatteryState state_{BatteryState::NoSlot};
        void transitionTo(BatteryState newState);
        std::uint8_t chargeLevel_{0};
        bool isInstalled_{false};
};