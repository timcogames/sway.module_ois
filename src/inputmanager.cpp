#include <sway/ois/inputmanager.h>

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

core::foundation::Object * InputManager::createDevice(DeviceType_t type) {
	if (!_window && hasFreeDevice(type))
		return NULL;

	core::foundation::Object * device = NULL;
	if (type == DeviceType_t::kKeyboard)
		device = new Keyboard(this);
	else if (type == DeviceType_t::kMouse)
		device = new Mouse(this);

	if (device)
		registerObject(device);

	return device;
}

bool InputManager::hasFreeDevice(DeviceType_t type) {
	switch (type) {
	case DeviceType_t::kKeyboard: return _keyboardUsed;
	case DeviceType_t::kMouse: return _mouseUsed;
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
