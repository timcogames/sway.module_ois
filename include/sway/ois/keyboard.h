#ifndef SWAY_OIS_KEYBOARD_H
#define SWAY_OIS_KEYBOARD_H

#include <sway/ois/inputevents.h>
#include <sway/ois/keyboardlistener.h>
#include <sway/ois/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputManager;

/*!
 * \brief
 *    Представляет устройство клавиатуры.
 */
class Keyboard : public core::foundation::Object {

	DECLARE_OBJECT(Keyboard, core::foundation::Object)

public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param[in] manager
	 *    Указатель на менеджер ввода.
	 */
	Keyboard(InputManager * manager);

	/*!
	 * \brief
	 *    Деструктор класса.
	 *
	 *    Освобождает захваченные ресурсы.
	 */
	virtual ~Keyboard();

	/*!
	 * \brief
	 *    Устанавливает слушатель событий.
	 * 
	 * \param[in] listener
	 *    Слушатель событий клавиатуры.
	 */
	void setListener(KeyboardListener * listener);

	/*!
	 * \brief
	 *    Уведомляет об нажатии на клавишу.
	 * 
	 * \param[in] event
	 *    Хранилище события.
	 */
	void notifyKeyPressed(const XEvent & event);

	/*!
	 * \brief
	 *    Уведомляет об отпускании клавиши.
	 * 
	 * \param[in] event
	 *    Хранилище события.
	 */
	void notifyKeyReleased(const XEvent & event);

private:
	/*!
	 * \brief
	 *    Инициализация устройства.
	 *
	 * \note
	 *    Внутренний метод, вызывается в конструкторе.
	 */
	void _initialize();

private:
	InputManager * _manager; /*!< Указатель на менеджер ввода. */
	KeyboardEventCallbackFunc_t _onKeyPressed;
	KeyboardEventCallbackFunc_t _onKeyReleased;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif // SWAY_OIS_KEYBOARD_H
