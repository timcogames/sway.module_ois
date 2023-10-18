#ifndef SWAY_OIS_INPUTDEVICEMACROS_HPP
#define SWAY_OIS_INPUTDEVICEMACROS_HPP

#define DECLARE_INPUTDEVICE_TYPE(TYPE) \
  static sway::ois::InputDeviceType getDeviceType() { return TYPE; }

#endif  // SWAY_OIS_INPUTDEVICEMACROS_HPP
