#ifndef SWAY_OIS_INPUTLISTENER_H
#define SWAY_OIS_INPUTLISTENER_H

#include <sway/namespacemacros.h>
#include <sway/ois/inputevents.h>

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

#endif  // SWAY_OIS_INPUTLISTENER_H
