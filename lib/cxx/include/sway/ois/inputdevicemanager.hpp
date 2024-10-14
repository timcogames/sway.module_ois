#ifndef SWAY_OIS_INPUTDEVICEMANAGER_HPP
#define SWAY_OIS_INPUTDEVICEMANAGER_HPP

#include <sway/core.hpp>
#include <sway/ois/inputdevice.hpp>
#include <sway/ois/inputdevicetypes.hpp>
#include <sway/ois/typedefs.hpp>
#include <sway/oismacros.hpp>

#include <memory>
#include <unordered_map>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

/**
 * @brief Класс управления вводом системы.
 */
class InputDeviceManager {
  DECLARE_PTR_ALIASES(InputDeviceManager)
  DECLARE_EMSCRIPTEN(InputDeviceManager)

public:
  InputDeviceManager();

  virtual ~InputDeviceManager() = default;

  /**
   * @brief Регистрирует устройство ввода.
   */
  template <typename CONCRETE_DEVICE>
  inline void registerDevice();

  /**
   * @brief Получает устройство ввода.
   */
  template <typename CONCRETE_DEVICE>
  inline auto getDevice() -> std::shared_ptr<CONCRETE_DEVICE>;

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

  void setEventBus(core::evts::EventBus::SharedPtr_t evtbus) { evtbus_ = evtbus; }

  auto getEventBus() -> core::evts::EventBus::SharedPtr_t { return evtbus_; }

private:
  core::evts::EventBus::SharedPtr_t evtbus_;
  std::unordered_map<u32_t, InputDevice::SharedPtr_t> factories_;
  bool keyboardUsed_;  // Используется ли клавиатура.
  bool mouseUsed_;  // Используется ли мышка.
};

#include <sway/ois/inputdevicemanager.inl>

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

D_MODULE_OIS_INTERFACE_EXPORT_API auto createInputDeviceManager() -> InputDeviceManager::JavaScriptPtr_t;

EXTERN_C_END
#endif

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_INPUTDEVICEMANAGER_HPP
