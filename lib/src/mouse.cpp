#include <sway/ois/inputdevicemanager.hpp>
#include <sway/ois/mouse.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

Mouse::Mouse(InputDeviceManager *manager)
    : manager_(manager)
    , mouseGrabbed_(false) {
  initialize_();
}

Mouse::~Mouse() {
  // if (mouseGrabbed_) {
  // 	XUngrabPointer(manager_->getDisplay(), CurrentTime);
  // 	mouseGrabbed_ = false;
  // }

  manager_->setMouseUsed(false);
}

void Mouse::initialize_() {
  manager_->setMouseUsed(true);

  // int err = XGrabPointer(manager_->getDisplay(), manager_->getWindowHandle(), True, 0, GrabModeAsync, GrabModeAsync,
  // manager_->getWindowHandle(), None, CurrentTime); if (err != GrabSuccess) { 	mouseGrabbed_ = true;
  // }
}

void Mouse::setListener(InputListener *listener) {
  onMouseButtonDown_ = std::bind(&InputListener::onMouseButtonDown, listener, std::placeholders::_1);
  onMouseButtonUp_ = std::bind(&InputListener::onMouseButtonUp, listener, std::placeholders::_1);
  onMouseMove_ = std::bind(&InputListener::onMouseMove, listener, std::placeholders::_1);
}

void Mouse::notifyMouseMove(const XEvent &event) {
  MouseEventArgs args;
  args.x = event.xmotion.x;
  args.y = event.xmotion.y;

  if (onMouseMove_) {
    onMouseMove_(args);
  }
}

void Mouse::notifyMouseButtonDown(const XEvent &event) {
  MouseEventArgs args;
  args.x = event.xmotion.x;
  args.y = event.xmotion.y;
  args.button = event.xbutton.button;

  if (onMouseButtonDown_) {
    onMouseButtonDown_(args);
  }
}

void Mouse::notifyMouseButtonUp(const XEvent &event) {
  MouseEventArgs args;
  args.x = event.xmotion.x;
  args.y = event.xmotion.y;
  args.button = event.xbutton.button;

  if (onMouseButtonUp_) {
    onMouseButtonUp_(args);
  }
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
