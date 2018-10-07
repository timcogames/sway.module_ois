#include <sway/ois/inputdevicemanager.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

InputDeviceManager::InputDeviceManager(void * display, u32_t window)
	: _display(static_cast<Display *>(display))
	, _window(static_cast<Window>(window))
	, _keyboardUsed(false), _mouseUsed(false) {
	// Empty
}

InputDeviceManager::~InputDeviceManager() {
	// Empty
}

bool InputDeviceManager::hasFreeDevice(InputDeviceType_t type) {
	switch (type) {
	case InputDeviceType_t::kKeyboard: return _keyboardUsed;
	case InputDeviceType_t::kMouse: return _mouseUsed;
	default:
		return 0;
	}
}

void InputDeviceManager::setKeyboardUsed(bool used) {
	_keyboardUsed = used;
}

void InputDeviceManager::setMouseUsed(bool used) {
	_mouseUsed = used;
}

Display * InputDeviceManager::getDisplay() const {
	return _display;
}

Window InputDeviceManager::getWindowHandle() const {
	return _window;
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
