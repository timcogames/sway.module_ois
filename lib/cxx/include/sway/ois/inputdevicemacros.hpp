#ifndef SWAY_OIS_INPUTDEVICEMACROS_HPP
#define SWAY_OIS_INPUTDEVICEMACROS_HPP

#define DECLARE_INPUTDEVICE_TYPE(TYPE) \
public:                                \
  static auto getDeviceType() -> sway::ois::InputDeviceType { return TYPE; }

#endif  // SWAY_OIS_INPUTDEVICEMACROS_HPP
