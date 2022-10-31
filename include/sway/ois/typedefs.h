#ifndef SWAY_OIS_TYPEDEFS_H
#define SWAY_OIS_TYPEDEFS_H

#include <boost/function.hpp>  // boost::function
#include <boost/unordered_map.hpp>  // boost::unordered_map

#include <memory>  // std::shared_ptr
#include <sway/namespacemacros.h>
#include <sway/types.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

typedef std::shared_ptr<class InputDeviceManager> InputDeviceManagerRef_t;
typedef std::shared_ptr<class InputDeviceBase> InputDeviceRef_t;
typedef std::shared_ptr<class Keyboard> KeyboardRef_t;
typedef std::shared_ptr<class Mouse> MouseRef_t;

typedef boost::function<InputDeviceRef_t()> InputDeviceCreator_t;
typedef boost::unordered_map<u32_t, InputDeviceCreator_t> InputDeviceFactory_t;

typedef boost::function<void(const struct KeyboardEventArgs &)> KeyboardEventCallbackFunc_t;
typedef boost::function<void(const struct MouseEventArgs &)> MouseEventCallbackFunc_t;

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_TYPEDEFS_H
