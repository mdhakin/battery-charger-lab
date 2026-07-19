#pragma once

#include <cstdint>

enum class BatteryState
{
    NoSlot,
    InSlotCharging,
    InSlotNotCharging,
    StorageDischarge
};

class Battery
{
    public:
        Battery();

        bool setChargeLevel(std::uint8_t level);
        void installInSlot();
        void removeFromSlot();

        void update(std::uint64_t nowMs);

        [[nodiscard]] std::uint8_t getChargeLevel() const;
        [[nodiscard]] bool isInstalled() const;
        [[nodiscard]] bool isFullycharged() const;
        [[nodiscard]] BatteryState getState() const;

    private:
        BatteryState state_{BatteryState::NoSlot};
        void transitionTo(BatteryState newState, std::uint64_t nowMs);
        std::uint8_t chargeLevel_{0};
        bool isInstalled_{false};
        std::uint64_t stateEntryTimeMs_{0};

        static constexpr std::uint64_t storageDelayMs_{5000};
};