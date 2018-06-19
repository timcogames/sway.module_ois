#include <sway/ois/keyboard.h>
#include <sway/ois/inputmanager.h>
#include <sway/ois/keymappinglist.h>

#include <iostream>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

Keyboard::Keyboard(InputManager * manager) : core::foundation::Object(manager) {
	_initialize();
}

Keyboard::~Keyboard() {
	XUngrabKeyboard(_manager->getDisplay(), CurrentTime);
	_manager->setKeyboardUsed(false);
}

void Keyboard::_initialize() {
	_manager = static_cast<InputManager *>(getContext());
	_manager->setKeyboardUsed(true);
	
	int err = XGrabKeyboard(_manager->getDisplay(), _manager->getWindowHandle(), True, GrabModeAsync, GrabModeAsync, CurrentTime);
	if (err != GrabSuccess) {
		// TODO
	}
}

void Keyboard::setListener(KeyboardListener * listener) {
	_onKeyPressed = boost::bind(&KeyboardListener::onKeyPressed, listener, _1);
	_onKeyReleased = boost::bind(&KeyboardListener::onKeyReleased, listener, _1);
}

void Keyboard::notifyKeyPressed(const XEvent & event) {
	KeySym key = NoSymbol;
	XLookupString((XKeyEvent *)&event.xkey, 0, 0, &key, 0);

	for (const KeyMapping & mapping : XtoKeycode) {
		if (mapping.keysym == key) {
			KeyboardEventArgs args;
			args.keycode = mapping.keycode;

			if (_onKeyPressed)
				_onKeyPressed(args);
		}
	}
}

void Keyboard::notifyKeyReleased(const XEvent & event) {
	KeySym key = NoSymbol;
	XLookupString((XKeyEvent *)&event.xkey, 0, 0, &key, 0);

	for (const KeyMapping & mapping : XtoKeycode) {
		if (mapping.keysym == key) {
			KeyboardEventArgs args;
			args.keycode = mapping.keycode;

			if (_onKeyReleased)
				_onKeyReleased(args);
		}
	}
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
