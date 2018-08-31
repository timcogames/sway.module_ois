#ifndef SWAY_OIS_MOUSE_H
#define SWAY_OIS_MOUSE_H

#include <sway/ois/inputevents.h>
#include <sway/ois/mouselistener.h>
#include <sway/ois/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputManager;

/*!
 * \brief
 *    Представляет устройство мыши.
 */
class Mouse : public core::foundation::Object {
	
	DECLARE_OBJECT(Mouse, core::foundation::Object)

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
	Mouse(InputManager * manager);

	/*!
	 * \brief
	 *    Деструктор класса.
	 *
	 *    Освобождает захваченные ресурсы.
	 */
	virtual ~Mouse();

	/*!
	 * \brief
	 *    Устанавливает слушатель событий.
	 * 
	 * \param[in] listener
	 *    Слушатель событий мышки.
	 */
	void setListener(MouseListener * listener);

	void notifyMouseMove(const XEvent & event);

	void notifyMouseButtonDown(const XEvent & event);
	
	void notifyMouseButtonUp(const XEvent & event);

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
	MouseEventCallbackFunc_t _onMouseButtonDown;
	MouseEventCallbackFunc_t _onMouseButtonUp;
	MouseEventCallbackFunc_t _onMouseMove;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif // SWAY_OIS_MOUSE_H
