#ifndef SWAY_OIS_INPUTDEVICE_HPP
#define SWAY_OIS_INPUTDEVICE_HPP

#include <sway/core.hpp>
#include <sway/ois/_typedefs.hpp>
#include <sway/ois/inputlistener.hpp>

namespace sway::ois {

class InputDevice {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  virtual ~InputDevice() = default;

  /** @} */
#pragma endregion

#pragma region "Pure virtual methods"
  /** \~english @name Pure virtual methods */ /** \~russian @name Чисто виртуальные методы */
  /** @{ */

  /**
   * \~english
   * @brief Sets listener for events.
   * @param[in] listener Listener for events.
   *
   * \~russian
   * @brief Устанавливает слушатель событий.
   * @param[in] listener Слушатель событий.
   */
  virtual void setListener(typedefs::InputListenerPtr_t listener) = 0;

  virtual void setInputEventListener(typedefs::InputEventListenerPtr_t listener) = 0;

  /** @} */
#pragma endregion
};

}  // namespace sway::ois

#endif  // SWAY_OIS_INPUTDEVICE_HPP
