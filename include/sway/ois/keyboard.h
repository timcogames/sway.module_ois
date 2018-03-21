#ifndef SWAY_OIS_KEYBOARD_H
#define SWAY_OIS_KEYBOARD_H

#include <sway/ois/inputevents.h>
#include <sway/ois/keyboardlistener.h>
#include <sway/core.h>

#include <boost/function.hpp> // boost::function
#include <boost/bind.hpp> // boost::bind

#include <X11/Xutil.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputManager;
class Keyboard : public core::foundation::Object {

	DECLARE_OBJECT(Keyboard, core::foundation::Object)

public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Keyboard(InputManager * manager);

	/*!
	 * \brief
	 *    Деструктор класса.
	 *
	 *    Освобождает захваченные ресурсы.
	 */
	virtual ~Keyboard();

	void setListener(KeyboardListener * listener);

	void notifyKeyPressed(const XEvent & event);

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
	InputManager * _manager;
	KeyboardEventCallbackFunc_t _onKeyPressed;
	KeyboardEventCallbackFunc_t _onKeyReleased;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif // SWAY_OIS_KEYBOARD_H
