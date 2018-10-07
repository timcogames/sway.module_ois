#include <sway/ois/mouse.h>
#include <sway/ois/inputdevicemanager.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

Mouse::Mouse(InputDeviceManager * manager)
	: _manager(manager)
	, _mouseGrabbed(false) {
	_initialize();
}

Mouse::~Mouse() {
	// if (_mouseGrabbed) {
	// 	XUngrabPointer(_manager->getDisplay(), CurrentTime);
	// 	_mouseGrabbed = false;
	// }

	_manager->setMouseUsed(false);
}

void Mouse::_initialize() {
	_manager->setMouseUsed(true);
	
	// int err = XGrabPointer(_manager->getDisplay(), _manager->getWindowHandle(), True, 0, GrabModeAsync, GrabModeAsync, _manager->getWindowHandle(), None, CurrentTime);
	// if (err != GrabSuccess) {
	// 	_mouseGrabbed = true;
	// }
}

void Mouse::setListener(InputListener * listener) {
	_onMouseButtonDown = boost::bind(&InputListener::onMouseButtonDown, listener, _1);
	_onMouseButtonUp = boost::bind(&InputListener::onMouseButtonUp, listener, _1);
	_onMouseMove = boost::bind(&InputListener::onMouseMove, listener, _1);
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
