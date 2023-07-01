#ifndef SWAY_OIS_WEB_EMSKEYBOARD_HPP
#define SWAY_OIS_WEB_EMSKEYBOARD_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/inputdevicemacros.hpp>
#include <sway/ois/keyboardeventargs.hpp>

#include <emscripten/html5.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputDeviceManager;

class EMSKeyboard : public InputDevice {
public:
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType::KEYBOARD);

  EMSKeyboard(InputDeviceManager *mngr);

  ~EMSKeyboard() = default;

  auto onKeyDown(const EmscriptenKeyboardEvent &evt) -> bool;

  auto onKeyUp(const EmscriptenKeyboardEvent &evt) -> bool;

  auto onKeyPress(const EmscriptenKeyboardEvent &evt) -> bool;

  /**
   * @brief Устанавливает слушатель событий.
   *
   * @param[in] listener Слушатель событий клавиатуры.
   */
  MTHD_OVERRIDE(void setListener(InputListener *listener));

private:
  InputDeviceManager *mngr_;
  std::function<void(const struct KeyboardEventArgs &)> onKeyDown_;
  std::function<void(const struct KeyboardEventArgs &)> onKeyUp_;
  std::function<void(const struct KeyboardEventArgs &)> onKeyPress_;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_WEB_EMSKEYBOARD_HPP
