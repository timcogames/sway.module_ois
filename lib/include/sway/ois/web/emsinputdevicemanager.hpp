#ifndef SWAY_OIS_WEB_EMSINPUTDEVICEMANAGER_HPP
#define SWAY_OIS_WEB_EMSINPUTDEVICEMANAGER_HPP

#include <sway/core.hpp>

#include <emscripten/html5.h>  // EmscriptenMouseEvent

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class EMSInputDeviceManager {
public:
  EMSInputDeviceManager();

  ~EMSInputDeviceManager() = default;

private:
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_WEB_EMSINPUTDEVICEMANAGER_HPP
