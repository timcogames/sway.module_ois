#ifndef SWAY_OIS_INPUTMANAGER_H
#define SWAY_OIS_INPUTMANAGER_H

#include <sway/ois/devicetypes.h>
#include <sway/ois/keyboard.h>
#include <sway/ois/mouse.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputManager : public core::foundation::Context {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param window
	 *    Уникальный идентификатор окна.
	 */
	InputManager(u32_t window);

	/*!
	 * \brief
	 *    Деструктор класса.
	 *
	 *    Освобождает захваченные ресурсы.
	 */
	virtual ~InputManager();

	/*!
	 * \brief
	 *    Создает объект устройства ввода.
	 *
	 * \param[in] type
	 *    Тип устройства.
	 */
	core::foundation::Object * createDevice(DeviceTypes type);

	/*!
	 * \brief
	 *    Проверяет устройство.
	 *
	 * \param[in] type
	 *    Тип устройства для проверки.
	 */
	bool hasFreeDevice(DeviceTypes type);

	/*!
	 * \brief
	 *    Устанавливает логическое значение использования клавиатуры.
	 *
	 * \param[in] used
	 *    Обрабатывать события от клавиатуры?
	 *
	 * \note
	 *    Внутренний метод.
	 */
	void setKeyboardUsed(bool used);

	/*!
	 * \brief
	 *    Устанавливает логическое значение использования мышки.
	 *
	 * \param[in] used
	 *    Обрабатывать события от мышки?
	 *
	 * \note
	 *    Внутренний метод.
	 */
	void setMouseUsed(bool used);

	/*!
	 * \brief
	 *    Получает указатель на структуру дисплея.
	 */
	Display * getDisplay() const;

	/*!
	 * \brief
	 *    Получает идентификатор окна.
	 */
	Window getWindowHandle() const;

public:
	Display * _display; /*!< Указатель на структуру дисплея. */
	Window _window; /*!< Идентификатор окна. */
	bool _keyboardUsed; /*!< Используется ли клавиатура. */
	bool _mouseUsed; /*!< Используется ли мышка. */
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif // SWAY_OIS_INPUTMANAGER_H
