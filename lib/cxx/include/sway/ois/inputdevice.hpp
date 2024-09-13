#ifndef SWAY_OIS_INPUTDEVICE_HPP
#define SWAY_OIS_INPUTDEVICE_HPP

#include <sway/core.hpp>
#include <sway/ois/inputlistener.hpp>
#include <sway/ois/typedefs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputDevice {
  DECLARE_CLASS_POINTER_ALIASES(InputDevice)

public:
#pragma region "Ctors/Dtor"

  virtual ~InputDevice() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  /**
   * @brief Устанавливает слушатель событий.
   *
   * @param[in] listener Слушатель событий клавиатуры.
   */
  PURE_VIRTUAL(void setListener(InputListener::Ptr_t listener));

  PURE_VIRTUAL(void setInputEventListener(InputEventListener::Ptr_t listener));

#pragma endregion
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTDEVICE_HPP
