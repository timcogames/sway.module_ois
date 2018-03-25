#include <sway/ois/inputmanager.h>

#include <stdio.h>  // printf, NULL
#include <stdlib.h> // strtoull

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

InputManager::InputManager(void * display, u32_t window)
	: _display(static_cast<Display *>(display))
	, _window(static_cast<Window>(window))
	, _keyboardUsed(false), _mouseUsed(false) {

	// Empty
}

InputManager::~InputManager() {
	// Empty
}

core::foundation::Object * InputManager::createDevice(DeviceTypes type) {
	if (!_window && hasFreeDevice(type))
		return NULL;

	core::foundation::Object * device = NULL;
	if (type == kDeviceType_Keyboard)
		device = new Keyboard(this);
	else if (type == kDeviceType_Mouse)
		device = new Mouse(this);

	if (device)
		registerObject(device);

	return device;
}

bool InputManager::hasFreeDevice(DeviceTypes type) {
	switch(type) {
	case kDeviceType_Keyboard: return _keyboardUsed;
	case kDeviceType_Mouse: return _mouseUsed;
	default:
		return 0;
	}
}

void InputManager::setKeyboardUsed(bool used) {
	_keyboardUsed = used;
}

void InputManager::setMouseUsed(bool used) {
	_mouseUsed = used;
}

Display * InputManager::getDisplay() const {
	return _display;
}

Window InputManager::getWindowHandle() const {
	return _window;
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
