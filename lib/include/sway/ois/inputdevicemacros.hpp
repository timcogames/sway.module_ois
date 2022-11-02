#ifndef SWAY_OIS_INPUTDEVICEMACROS_HPP
#define SWAY_OIS_INPUTDEVICEMACROS_HPP

#define DECLARE_INPUTDEVICE_TYPE(TYPE) \
public:                                \
  static sway::ois::InputDeviceType_t getDeviceType() { return TYPE; }

#endif  // SWAY_OIS_INPUTDEVICEMACROS_HPP
