#ifndef SWAY_OIS_INPUTLISTENER_HPP
#define SWAY_OIS_INPUTLISTENER_HPP

#include <sway/core.hpp>
#include <sway/ois/_stdafx.hpp>
#include <sway/ois/_typedefs.hpp>
#include <sway/ois/inputactiontypes.hpp>
#include <sway/ois/inputeventparams.hpp>
#include <sway/ois/keyboardeventparams.hpp>
#include <sway/ois/mouseeventparams.hpp>

namespace sway::ois {

class InputEventListener {

public:
#pragma region "Pure virtual methods"

  virtual void processInputEvent(InputEventParams *params) = 0;

#pragma endregion
};

class InputListener {
public:
#pragma region "Методы обработки событий клавиатуры"

  // MTHD_VIRTUAL(void onKeyPressed(const KeyboardEventParams &params)) {}

  // MTHD_VIRTUAL(void onKeyReleased(const KeyboardEventParams &params)) {}

  MTHD_VIRTUAL(void onKeyDown(const KeyboardEventParams &params)) {}

  MTHD_VIRTUAL(void onKeyUp(const KeyboardEventParams &params)) {}

  MTHD_VIRTUAL(void onKeyPress(const KeyboardEventParams &params)) {}

#pragma endregion

#pragma region "Методы обработки событий мышки"

  MTHD_VIRTUAL(void onMouseButtonDown(const MouseEventParams &params)) {}

  MTHD_VIRTUAL(void onMouseButtonUp(const MouseEventParams &params)) {}

  MTHD_VIRTUAL(void onMouseDblClick(const MouseEventParams &params)) {}

  MTHD_VIRTUAL(void onMouseMoved(const MouseEventParams &params)) {}

  MTHD_VIRTUAL(void onMouseWheeled(const MouseEventParams &params)) {}

#pragma endregion
};

}  // namespace sway::ois

#endif  // SWAY_OIS_INPUTLISTENER_HPP
