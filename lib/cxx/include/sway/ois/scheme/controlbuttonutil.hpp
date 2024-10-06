#ifndef SWAY_OIS_SCHEME_CONTROLBUTTONUTIL_HPP
#define SWAY_OIS_SCHEME_CONTROLBUTTONUTIL_HPP

#include <sway/core.hpp>
#include <sway/ois/inputactiontypes.hpp>
#include <sway/ois/keycodes.hpp>
#include <sway/ois/scheme/controlbutton.hpp>

#include <memory>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

struct ControlButtonUtil {
  static auto makeKeyboardControlButton(KeyCode key) -> std::shared_ptr<ControlButton<InputActionType::KEY>> {
    return std::make_shared<ControlButton<InputActionType::KEY>>(key);
  }

  static auto makeKeyboardControlButtonU32(u32_t key) -> std::shared_ptr<ControlButton<InputActionType::KEY>> {
    return std::make_shared<ControlButton<InputActionType::KEY>>(key);
  }
};

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_SCHEME_CONTROLBUTTONUTIL_HPP
