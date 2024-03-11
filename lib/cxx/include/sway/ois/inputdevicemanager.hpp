#ifndef SWAY_OIS_INPUTDEVICEMANAGER_HPP
#define SWAY_OIS_INPUTDEVICEMANAGER_HPP

#include <sway/core.hpp>
#include <sway/ois/inputdevice.hpp>
#include <sway/ois/inputdevicetypes.hpp>
#include <sway/oismacros.hpp>

#include <memory>
#include <unordered_map>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/**
 * @brief Класс управления вводом системы.
 */
class InputDeviceManager {
public:
  DECLARE_EMSCRIPTEN(InputDeviceManager)

  InputDeviceManager();

  virtual ~InputDeviceManager() = default;

  /**
   * @brief Регистрирует устройство ввода.
   */
  template <typename TConcreteInputDevice>
  inline void registerDevice();

  /**
   * @brief Получает устройство ввода.
   */
  template <typename TConcreteInputDevice>
  inline auto getDevice() -> std::shared_ptr<TConcreteInputDevice>;

  /**
   * @brief Проверяет устройство.
   *
   * @param[in] type Тип устройства для проверки.
   */
  auto hasFreeDevice(InputDeviceType type) -> bool;

  /**
   * @brief Устанавливает логическое значение использования клавиатуры.
   *
   * @param[in] used Обрабатывать события от клавиатуры?
   * @note Внутренний метод.
   */
  void setKeyboardUsed(bool used);

  /**
   * @brief Устанавливает логическое значение использования мышки.
   *
   * @param[in] used Обрабатывать события от мышки?
   * @note Внутренний метод.
   */
  void setMouseUsed(bool used);

  void setEventBus(std::shared_ptr<core::evts::EventBus> evtbus) { evtbus_ = evtbus; }

  auto getEventBus() -> std::shared_ptr<core::evts::EventBus> { return evtbus_; }

private:
  std::shared_ptr<core::evts::EventBus> evtbus_;
  std::unordered_map<u32_t, std::shared_ptr<InputDevice>> factories_;
  bool keyboardUsed_;  // Используется ли клавиатура.
  bool mouseUsed_;  // Используется ли мышка.
};

#include <sway/ois/inputdevicemanager.inl>

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

D_MODULE_OIS_INTERFACE_EXPORT_API auto createInputDeviceManager() -> InputDeviceManager::JsPtr_t;

EXTERN_C_END
#endif

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTDEVICEMANAGER_HPP
