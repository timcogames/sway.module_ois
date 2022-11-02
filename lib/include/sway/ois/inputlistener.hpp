#ifndef SWAY_OIS_INPUTLISTENER_HPP
#define SWAY_OIS_INPUTLISTENER_HPP

#include <sway/namespacemacros.hpp>
#include <sway/ois/inputevents.hpp>
#include <sway/ois/keyboardeventargs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputListener {
public:
#pragma region Методы обработки событий клавиатуры

  virtual void onKeyPressed(const KeyboardEventArgs &event) {
    // Empty
  }

  virtual void onKeyReleased(const KeyboardEventArgs &event) {
    // Empty
  }

#pragma endregion

#pragma region Методы обработки событий мышки

  virtual void onMouseButtonDown(const MouseEventArgs &event) {
    // Empty
  }

  virtual void onMouseButtonUp(const MouseEventArgs &event) {
    // Empty
  }

  virtual void onMouseMove(const MouseEventArgs &event) {
    // Empty
  }

#pragma endregion
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTLISTENER_HPP
