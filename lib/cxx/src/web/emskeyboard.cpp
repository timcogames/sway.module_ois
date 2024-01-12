#include <sway/ois/inputdevicemanager.hpp>
#include <sway/ois/web/emskeyboard.hpp>

#include <algorithm>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

EMSKeyboard::EMSKeyboard(InputDeviceManager *mngr)
    : mngr_(mngr) {
#ifdef EMSCRIPTEN_PLATFORM
  const EM_BOOL toUseCapture = EM_FALSE;

  emscripten_set_keydown_callback(
      EMSCRIPTEN_EVENT_TARGET_DOCUMENT, this, toUseCapture, [](int, const EmscriptenKeyboardEvent *evt, void *data) {
        return EM_BOOL(static_cast<EMSKeyboard *>(data)->onKeyDown(*evt));
      });

  emscripten_set_keyup_callback(
      EMSCRIPTEN_EVENT_TARGET_DOCUMENT, this, toUseCapture, [](int, const EmscriptenKeyboardEvent *evt, void *data) {
        return EM_BOOL(static_cast<EMSKeyboard *>(data)->onKeyUp(*evt));
      });

  emscripten_set_keypress_callback(
      EMSCRIPTEN_EVENT_TARGET_DOCUMENT, this, toUseCapture, [](int, const EmscriptenKeyboardEvent *evt, void *data) {
        return EM_BOOL(static_cast<EMSKeyboard *>(data)->onKeyPress(*evt));
      });
#endif
}

void EMSKeyboard::setListener(InputListener *listener) {
  onKeyDown_ = std::bind(&InputListener::onKeyDown, listener, std::placeholders::_1);
  onKeyUp_ = std::bind(&InputListener::onKeyUp, listener, std::placeholders::_1);
  onKeyPress_ = std::bind(&InputListener::onKeyPress, listener, std::placeholders::_1);
}

auto EMSKeyboard::onKeyDown(const EmscKeyboardEvent_t &evt) -> bool {
  if (onKeyDown_) {
    onKeyDown_(KeyboardEventArgs(evt.keyCode));
  }

  return true;
}

auto EMSKeyboard::onKeyUp(const EmscKeyboardEvent_t &evt) -> bool {
  if (onKeyUp_) {
    onKeyUp_(KeyboardEventArgs(evt.keyCode));
  }

  return true;
}

auto EMSKeyboard::onKeyPress(const EmscKeyboardEvent_t &evt) -> bool {
  if (onKeyPress_) {
    onKeyPress_(KeyboardEventArgs(evt.keyCode));
  }

  return true;
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
