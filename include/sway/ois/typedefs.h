#ifndef SWAY_OIS_TYPEDEFS_H
#define SWAY_OIS_TYPEDEFS_H

#include <sway/namespacemacros.h>

#include <boost/shared_ptr.hpp> // boost::shared_ptr
#include <boost/function.hpp> // boost::function

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

typedef boost::shared_ptr<class Keyboard> KeyboardRef_t;
typedef boost::shared_ptr<class Mouse> MouseRef_t;
typedef boost::shared_ptr<class InputManager> InputManagerRef_t;

typedef boost::function<void (const struct KeyboardEventArgs &)> KeyboardEventCallbackFunc_t;
typedef boost::function<void (const struct MouseEventArgs &)> MouseEventCallbackFunc_t;

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif // SWAY_OIS_TYPEDEFS_H
