#ifndef SWAY_OIS_WEB_EMSKEYBOARD_HPP
#define SWAY_OIS_WEB_EMSKEYBOARD_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/inputdevice.hpp>
#include <sway/ois/inputdevicemacros.hpp>
#include <sway/ois/inputdevicetypes.hpp>
#include <sway/ois/inputlistener.hpp>
#include <sway/ois/keyboardeventparams.hpp>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/html5.h>
#endif

namespace sway::ois {

#ifdef EMSCRIPTEN_PLATFORM
using EmscKeyboardEvent_t = EmscriptenKeyboardEvent;
#else
struct EmscKeyboardEvent_t {
  u64_t keyCode;
};
#endif

class InputDeviceManager;

class EMSKeyboard : public InputDevice {
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType::KEYBOARD);

public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  EMSKeyboard(typedefs::InputDeviceManagerPtr_t mngr);

  ~EMSKeyboard() = default;

  /** @} */
#pragma endregion

  auto handleKeyDown(const EmscKeyboardEvent_t &evt) -> bool;

  auto handleKeyUp(const EmscKeyboardEvent_t &evt) -> bool;

  auto handleKeyPress(const EmscKeyboardEvent_t &evt) -> bool;

#pragma region "Override InputDevice methods"

  /**
   * @brief Устанавливает слушатель событий.
   *
   * @param[in] listener Слушатель событий клавиатуры.
   */
  MTHD_OVERRIDE(void setListener(typedefs::InputListenerPtr_t listener));

  MTHD_OVERRIDE(void setInputEventListener(typedefs::InputEventListenerPtr_t listener));

#pragma endregion

private:
  typedefs::InputDeviceManagerPtr_t mngr_;
  std::function<void(InputEventParams *)> actionCallback_;

  std::function<void(const struct KeyboardEventParams &)> onKeyDown_;
  std::function<void(const struct KeyboardEventParams &)> onKeyUp_;
  std::function<void(const struct KeyboardEventParams &)> onKeyPress_;
};

}  // namespace sway::ois

#endif  // SWAY_OIS_WEB_EMSKEYBOARD_HPP
