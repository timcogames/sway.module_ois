#include <sway/ois/inputdevicemanager.hpp>

#include <memory>  // std::static_pointer_cast, std::make_shared
#include <utility>  // std::make_pair

template <typename CONCRETE_DEVICE>
void InputDeviceManager::registerDevice() {
  auto deviceType = core::toBase(CONCRETE_DEVICE::getDeviceType());
  auto devicePtr = std::make_shared<CONCRETE_DEVICE>(this);
  factories_.insert(std::make_pair(deviceType, devicePtr));
}

template <typename CONCRETE_DEVICE>
auto InputDeviceManager::getDevice() -> std::shared_ptr<CONCRETE_DEVICE> {
  return std::static_pointer_cast<CONCRETE_DEVICE>(factories_.at(core::toBase(CONCRETE_DEVICE::getDeviceType())));
}
