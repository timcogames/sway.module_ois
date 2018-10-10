#include <sway/ois/keyboard.h>
#include <sway/ois/inputdevicemanager.h>
#include <sway/ois/keymappinglist.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

Keyboard::Keyboard(InputDeviceManager * manager)
	: _manager(manager)
	, _listener(NULL)
	, _keyboardGrabbed(false) {
	_initialize();
}

Keyboard::~Keyboard() {
	//_enableSystemKeys();
	_manager->setKeyboardUsed(false);
}

void Keyboard::_initialize() {
	//_disableSystemKeys();
	_manager->setKeyboardUsed(true);
}

void Keyboard::_disableSystemKeys() {
	int err = XGrabKeyboard(_manager->getDisplay(), _manager->getWindowHandle(), True, GrabModeAsync, GrabModeAsync, CurrentTime);
	if (err != GrabSuccess)
		_keyboardGrabbed = true;
}

void Keyboard::_enableSystemKeys() {
	if (_keyboardGrabbed) {
		XUngrabKeyboard(_manager->getDisplay(), CurrentTime);
		_keyboardGrabbed = false;
	}
}

void Keyboard::setListener(InputListener * listener) {
	_listener = listener;
}

void Keyboard::notifyKeyPressed(const XEvent & event) {
	if (!_listener)
		return;
		
	KeySym key = NoSymbol;
	XLookupString((XKeyEvent *)&event.xkey, 0, 0, &key, 0);

	for (const KeyMapping & mapping : XtoKeycode) {
		if (mapping.keysym == key) {
			_listener->onKeyPressed((KeyboardEventArgs) {
				.keycode = mapping.keycode
			});
		}
	}
}

void Keyboard::notifyKeyReleased(const XEvent & event) {
	if (!_listener)
		return;
		
	KeySym key = NoSymbol;
	XLookupString((XKeyEvent *)&event.xkey, 0, 0, &key, 0);

	for (const KeyMapping & mapping : XtoKeycode) {
		if (mapping.keysym == key) {
			_listener->onKeyReleased((KeyboardEventArgs) {
				.keycode = mapping.keycode
			});
		}
	}
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
