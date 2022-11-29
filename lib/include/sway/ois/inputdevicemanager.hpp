#ifndef SWAY_OIS_INPUTDEVICEMANAGER_HPP
#define SWAY_OIS_INPUTDEVICEMANAGER_HPP

#include <sway/ois/inputdevicetypes.hpp>
#include <sway/ois/keyboard.hpp>
#include <sway/ois/mouse.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/**
 * @brief Класс управления вводом системы.
 *
 */
class InputDeviceManager {
public:
  /**
   * @brief Конструктор класса.
   * Выполняет инициализацию нового экземпляра класса.
   *
   * @param[in] display Указатель на структуру дисплея.
   * @param[in] window Уникальный идентификатор окна.
   *
   */
  InputDeviceManager(void *display, u32_t window);

  /**
   * @brief Деструктор класса.
   * Освобождает захваченные ресурсы.
   *
   */
  virtual ~InputDeviceManager();

  /**
   * @brief Регистрирует устройство ввода.
   *
   */
  template <typename TYPE>
  inline void registerDevice();

  /**
   * @brief Получает устройство ввода.
   *
   */
  template <typename TYPE>
  inline auto getDevice() -> std::shared_ptr<TYPE>;

  /**
   * @brief Проверяет устройство.
   *
   * @param[in] type Тип устройства для проверки.
   *
   */
  bool hasFreeDevice(InputDeviceType_t type);

  /**
   * @brief Устанавливает логическое значение использования клавиатуры.
   *
   * @param[in] used Обрабатывать события от клавиатуры?
   *
   * @note Внутренний метод.
   *
   */
  void setKeyboardUsed(bool used);

  /**
   * @brief Устанавливает логическое значение использования мышки.
   *
   * @param[in] used Обрабатывать события от мышки?
   *
   * @note Внутренний метод.
   *
   */
  void setMouseUsed(bool used);

  /**
   * @brief Получает указатель на структуру дисплея.
   *
   */
  auto getDisplay() const -> Display *;

  /**
   * @brief Получает идентификатор окна.
   *
   */
  auto getWindowHandle() const -> Window;

public:
  Display *display_; /*!< Указатель на структуру дисплея. */
  Window window_; /*!< Идентификатор окна. */
  InputDeviceFactory_t factories_;
  bool keyboardUsed_; /*!< Используется ли клавиатура. */
  bool mouseUsed_; /*!< Используется ли мышка. */
};

#include <sway/ois/inputdevicemanager.inl>

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTDEVICEMANAGER_HPP
