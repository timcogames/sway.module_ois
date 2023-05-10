#include <sway/ois/inputdevicemanager.hpp>

#include <memory>  // std::static_pointer_cast, std::make_shared
#include <utility>  // std::make_pair

template <typename TConcreteInputDevice>
void InputDeviceManager::registerDevice() {
  auto deviceType = core::detail::toUnderlying(TConcreteInputDevice::getDeviceType());
  auto devicePtr = std::make_shared<TConcreteInputDevice>(this);
  factories_.insert(std::make_pair(deviceType, devicePtr));
}

template <typename TConcreteInputDevice>
auto InputDeviceManager::getDevice() -> std::shared_ptr<TConcreteInputDevice> {
  return std::static_pointer_cast<TConcreteInputDevice>(
      factories_.at(core::detail::toUnderlying(TConcreteInputDevice::getDeviceType())));
}
