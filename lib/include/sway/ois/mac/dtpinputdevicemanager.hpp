#ifndef SWAY_OIS_MAC_DTPINPUTDEVICEMANAGER_HPP
#define SWAY_OIS_MAC_DTPINPUTDEVICEMANAGER_HPP

#include <sway/ois/inputdevicetypes.hpp>
#include <sway/ois/mac/dtpkeyboard.hpp>
#include <sway/ois/mac/dtpmouse.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/**
 * @brief Класс управления вводом системы.
 */
class DTPInputDeviceManager : public std::enable_shared_from_this<DTPInputDeviceManager> {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   *
   * @param[in] display Указатель на структуру дисплея.
   * @param[in] window Уникальный идентификатор окна.
   */
  DTPInputDeviceManager(void *display, u32_t window);

  /**
   * @brief Деструктор класса. Освобождает захваченные ресурсы.
   */
  ~DTPInputDeviceManager() = default;

  /**
   * @brief Регистрирует устройство ввода.
   */
  template <typename TYPE>
  inline void registerDevice();

  /**
   * @brief Получает устройство ввода.
   */
  template <typename TYPE>
  inline auto getDevice() -> std::shared_ptr<TYPE>;

  /**
   * @brief Проверяет устройство.
   *
   * @param[in] type Тип устройства для проверки.
   */
  bool hasFreeDevice(InputDeviceType type);

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

  /**
   * @brief Получает указатель на структуру дисплея.
   */
  [[nodiscard]] auto getDisplay() const -> Display *;

  /**
   * @brief Получает идентификатор окна.
   */
  [[nodiscard]] auto getWindowHandle() const -> Window;

private:
  Display *display_;  // Указатель на структуру дисплея.
  Window window_;  // Идентификатор окна.
  // InputDeviceFactory_t factories_;
  std::unordered_map<u32_t, std::shared_ptr<InputDevice>> factories_;
  bool keyboardUsed_;  // Используется ли клавиатура.
  bool mouseUsed_;  // Используется ли мышка.
};

#include <sway/ois/mac/dtpinputdevicemanager.inl>

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_MAC_DTPINPUTDEVICEMANAGER_HPP
