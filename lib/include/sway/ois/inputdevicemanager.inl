#include <sway/ois/inputdevicemanager.hpp>

#include <memory>

template <typename TConcreteInputDevice>
void InputDeviceManager::registerDevice() {
  auto deviceType = core::detail::toUnderlying(TConcreteInputDevice::getDeviceType());
  // auto device = boost::bind(boost::factory<std::shared_ptr<TConcreteInputDevice>>(), this);
  auto devicePtr = std::make_shared<TConcreteInputDevice>(this);
  // auto device = std::bind(devicePtr, this);

  //                               u32_t,      std::function<std::shared_ptr<InputDevice>()>
  // factories_.insert(std::make_pair(deviceType, device));
  factories_.insert(std::make_pair(deviceType, devicePtr));
}

template <typename TConcreteInputDevice>
auto InputDeviceManager::getDevice() -> std::shared_ptr<TConcreteInputDevice> {
  return std::static_pointer_cast<TConcreteInputDevice>(
      // factories_.at(core::detail::toUnderlying(TConcreteInputDevice::getDeviceType()))());
      factories_.at(core::detail::toUnderlying(TConcreteInputDevice::getDeviceType())));
}
