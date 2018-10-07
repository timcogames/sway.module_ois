#ifndef SWAY_OIS_INPUTDEVICEMANAGER_H
#define SWAY_OIS_INPUTDEVICEMANAGER_H

#include <sway/ois/inputdevicetypes.h>
#include <sway/ois/keyboard.h>
#include <sway/ois/mouse.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/*!
 * \brief
 *    Класс управления вводом системы.
 */
class InputDeviceManager {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param[in] display
	 *    Указатель на структуру дисплея.
	 * 
	 * \param[in] window
	 *    Уникальный идентификатор окна.
	 */
	InputDeviceManager(void * display, u32_t window);

	/*!
	 * \brief
	 *    Деструктор класса.
	 *
	 *    Освобождает захваченные ресурсы.
	 */
	virtual ~InputDeviceManager();

	/*!
	 * \brief
	 *    Регистрирует устройство ввода.
	 */
	template<typename TYPE>
	inline void registerDevice();

	/*!
	 * \brief
	 *    Получает устройство ввода.
	 */
	template<typename TYPE>
	inline boost::shared_ptr<TYPE> getDevice();

	/*!
	 * \brief
	 *    Проверяет устройство.
	 *
	 * \param[in] type
	 *    Тип устройства для проверки.
	 */
	bool hasFreeDevice(InputDeviceType_t type);

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
	InputDeviceFactory_t _factories;
	bool _keyboardUsed; /*!< Используется ли клавиатура. */
	bool _mouseUsed; /*!< Используется ли мышка. */
};

#include <sway/ois/inputdevicemanager.inl>

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif // SWAY_OIS_INPUTDEVICEMANAGER_H
