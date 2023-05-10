#ifndef SWAY_OIS_INPUTDEVICEMANAGER_HPP
#define SWAY_OIS_INPUTDEVICEMANAGER_HPP

#include <sway/core.hpp>
#include <sway/ois/inputdevice.hpp>
#include <sway/ois/inputdevicetypes.hpp>

#include <memory>
#include <unordered_map>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/**
 * @brief Класс управления вводом системы.
 */
class InputDeviceManager {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   */
  InputDeviceManager();

  /**
   * @brief Деструктор класса. Освобождает захваченные ресурсы.
   */
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

private:
  std::unordered_map<u32_t, std::shared_ptr<InputDevice>> factories_;
  bool keyboardUsed_;  // Используется ли клавиатура.
  bool mouseUsed_;  // Используется ли мышка.
};

#include <sway/ois/inputdevicemanager.inl>

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTDEVICEMANAGER_HPP
