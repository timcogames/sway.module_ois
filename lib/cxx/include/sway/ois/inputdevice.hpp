#ifndef SWAY_OIS_INPUTDEVICE_HPP
#define SWAY_OIS_INPUTDEVICE_HPP

#include <sway/core.hpp>
#include <sway/ois/inputlistener.hpp>
#include <sway/ois/typedefs.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

class InputDevice {
  DECLARE_PTR_ALIASES(InputDevice)

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

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_INPUTDEVICE_HPP
