#ifndef SWAY_OIS_INPUTLISTENER_HPP
#define SWAY_OIS_INPUTLISTENER_HPP

#include <sway/core.hpp>
#include <sway/ois/inputevents.hpp>
#include <sway/ois/keyboardeventargs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputListener {
public:
#pragma region Методы обработки событий клавиатуры

  MTHD_VIRTUAL(void onKeyPressed(const KeyboardEventArgs &eventArgs){/* Empty */})

  MTHD_VIRTUAL(void onKeyReleased(const KeyboardEventArgs &eventArgs){/* Empty */})

#pragma endregion

#pragma region Методы обработки событий мышки

  MTHD_VIRTUAL(void onMouseButtonDown(const MouseEventArgs &eventArgs){/* Empty */})

  MTHD_VIRTUAL(void onMouseButtonUp(const MouseEventArgs &eventArgs){/* Empty */})

  MTHD_VIRTUAL(void onMouseMove(const MouseEventArgs &eventArgs){/* Empty */})

#pragma endregion
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTLISTENER_HPP
