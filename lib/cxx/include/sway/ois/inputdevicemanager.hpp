#ifndef SWAY_OIS_INPUTDEVICEMANAGER_HPP
#define SWAY_OIS_INPUTDEVICEMANAGER_HPP

#include <sway/core.hpp>
#include <sway/ois/_stdafx.hpp>
#include <sway/ois/_typedefs.hpp>
#include <sway/ois/inputdevice.hpp>
#include <sway/ois/inputdevicetypes.hpp>
#include <sway/oismacros.hpp>

namespace sway::ois {

/**
 * @brief \~english Class for input device management. \~russian Класс управления вводом системы.
 */
class InputDeviceManager : public core::Emscripteable<InputDeviceManager> {

public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  InputDeviceManager();

  virtual ~InputDeviceManager() = default;

  /** @} */
#pragma endregion

  /**
   * @brief \~english Registers input device. \~russian Регистрирует устройство ввода.
   */
  template <typename CONCRETE_DEVICE>
  inline void registerDevice();

  /**
   * @brief \~english Gets input device. \~russian Получает устройство ввода.
   */
  template <typename CONCRETE_DEVICE>
  inline auto getDevice() -> std::shared_ptr<CONCRETE_DEVICE>;

  /**
   * \~english
   * @brief Checks device.
   * @param[in] type Device type for check.
   *
   * \~russian
   * @brief Проверяет устройство.
   * @param[in] type Тип устройства для проверки.
   */
  auto hasFreeDevice(InputDeviceType type) -> bool;

  /**
   * \~english
   * @brief Sets logical value of keyboard usage.
   * @param[in] used Process keyboard events?
   * @note Internal method.
   *
   * \~russian
   * @brief Устанавливает логическое значение использования клавиатуры.
   * @param[in] used Обрабатывать события от клавиатуры?
   * @note Внутренний метод.
   */
  void setKeyboardUsed(bool used);

  /**
   * \~english
   * @brief Sets logical value of mouse usage.
   * @param[in] used Process mouse events?
   * @note Internal method.
   *
   * \~russian
   * @brief Устанавливает логическое значение использования мышки.
   * @param[in] used Обрабатывать события от мышки?
   * @note Внутренний метод.
   */
  void setMouseUsed(bool used);

  void setEventBus(core::EventBusTypedefs::SharedPtr_t evtbus) { evtbus_ = evtbus; }

  auto getEventBus() -> core::EventBusTypedefs::SharedPtr_t { return evtbus_; }

private:
  core::EventBusTypedefs::SharedPtr_t evtbus_;
  typedefs::InputDeviceContainer_t factories_;
  bool keyboardUsed_;  //!< \~english Keyboard used. \~russian Используется ли клавиатура.
  bool mouseUsed_;  //!< \~english Mouse used. \~russian Используется ли мышка.
};

#include <sway/ois/inputdevicemanager.inl>

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

D_MODULE_OIS_INTERFACE_EXPORT_API auto createInputDeviceManager() -> iptr_t;

EXTERN_C_END
#endif

}  // namespace sway::ois

#endif  // SWAY_OIS_INPUTDEVICEMANAGER_HPP
