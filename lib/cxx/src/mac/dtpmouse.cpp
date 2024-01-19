#include <sway/ois/inputdevicemanager.hpp>
#include <sway/ois/mac/dtpmouse.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

DTPMouse::DTPMouse(InputDeviceManager *mngr)
    : manager_(mngr)
    , mouseGrabbed_(false) {
  initialize_();
}

DTPMouse::~DTPMouse() {
  // if (mouseGrabbed_) {
  // 	XUngrabPointer(manager_->getDisplay(), CurrentTime);
  // 	mouseGrabbed_ = false;
  // }

  manager_->setMouseUsed(false);
}

void DTPMouse::initialize_() {
  manager_->setMouseUsed(true);

  // int err = XGrabPointer(manager_->getDisplay(), manager_->getWindowHandle(), True, 0, GrabModeAsync, GrabModeAsync,
  // manager_->getWindowHandle(), None, CurrentTime); if (err != GrabSuccess) { 	mouseGrabbed_ = true;
  // }
}

void DTPMouse::setListener(InputListener *listener) {
  onMouseButtonDown_ = std::bind(&InputListener::onMouseButtonDown, listener, std::placeholders::_1);
  onMouseButtonUp_ = std::bind(&InputListener::onMouseButtonUp, listener, std::placeholders::_1);
  onMouseMove_ = std::bind(&InputListener::onMouseMoved, listener, std::placeholders::_1);
}

void DTPMouse::notifyMouseMove(const XEvent &event) {
  MouseEventParams params;
  params.position = math::point2f_t(event.xmotion.x, event.xmotion.y);

  if (onMouseMove_) {
    onMouseMove_(params);
  }
}

void DTPMouse::notifyMouseButtonDown(const XEvent &event) {
  MouseEventParams params;
  params.position = math::point2f_t(event.xmotion.x, event.xmotion.y);
  params.button = event.xbutton.button;

  if (onMouseButtonDown_) {
    onMouseButtonDown_(params);
  }
}

void DTPMouse::notifyMouseButtonUp(const XEvent &event) {
  MouseEventParams params;
  params.position = math::point2f_t(event.xmotion.x, event.xmotion.y);
  params.button = event.xbutton.button;

  if (onMouseButtonUp_) {
    onMouseButtonUp_(params);
  }
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
