#include <sway/ois/mouse.h>
#include <sway/ois/inputmanager.h>

#include <iostream>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

Mouse::Mouse(InputManager * manager) : core::foundation::Object(manager) {
	_initialize();
}

Mouse::~Mouse() {
	XUngrabPointer(_manager->getDisplay(), CurrentTime);
	_manager->setMouseUsed(false);
}

void Mouse::_initialize() {
	_manager = static_cast<InputManager *>(getContext());
	_manager->setMouseUsed(true);
	
	int err = XGrabPointer(_manager->getDisplay(), _manager->getWindowHandle(), True, 0, GrabModeAsync, GrabModeAsync, _manager->getWindowHandle(), None, CurrentTime);
	if (err != GrabSuccess) {
		// TODO
	}
}

void Mouse::setListener(MouseListener * listener) {
	_onMouseButtonDown = boost::bind(&MouseListener::onMouseButtonDown, listener, _1);
	_onMouseButtonUp = boost::bind(&MouseListener::onMouseButtonUp, listener, _1);
	_onMouseMove = boost::bind(&MouseListener::onMouseMove, listener, _1);
}

void Mouse::notifyMouseMove(const XEvent & event) {
	MouseEventArgs args;
	args.x = event.xmotion.x;
	args.y = event.xmotion.y;
	
	if (_onMouseMove)
		_onMouseMove(args);
}

void Mouse::notifyMouseButtonDown(const XEvent & event) {
	MouseEventArgs args;
	args.x = event.xmotion.x;
	args.y = event.xmotion.y;
	args.button = event.xbutton.button;
	
	if (_onMouseButtonDown)
		_onMouseButtonDown(args);
}

void Mouse::notifyMouseButtonUp(const XEvent & event) {
	MouseEventArgs args;
	args.x = event.xmotion.x;
	args.y = event.xmotion.y;
	args.button = event.xbutton.button;
	
	if (_onMouseButtonUp)
		_onMouseButtonUp(args);
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
