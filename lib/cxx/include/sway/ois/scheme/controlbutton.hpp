#ifndef SWAY_OIS_SCHEME_CONTROLBUTTON_HPP
#define SWAY_OIS_SCHEME_CONTROLBUTTON_HPP

#include <sway/core.hpp>
#include <sway/ois/inputactiontypes.hpp>
#include <sway/ois/keycodes.hpp>
#include <sway/ois/mousebuttoncodes.hpp>
#include <sway/ois/mousewheelscrollactions.hpp>

#include <memory>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

template <typename TYPE>
struct Equalable {
  using SharedPtr_t = std::shared_ptr<Equalable<TYPE>>;

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(auto equal(TYPE key) const -> bool);

#pragma endregion
};

template <InputActionType TYPE>
struct ControlButton : public Equalable<u32_t> {
#pragma region "Static members"

  static const InputActionType type = TYPE;

#pragma endregion

#pragma region "Override Equalable methods"

  MTHD_OVERRIDE(auto equal(u32_t key) const -> bool) { return true; }

#pragma endregion
};

template <>
struct ControlButton<InputActionType::KEY> : public Equalable<u32_t> {
#pragma region "Public members"

  u32_t keyCode;

#pragma endregion

#pragma region "Static members"

  static const InputActionType type = InputActionType::KEY;

#pragma endregion

#pragma region "Ctors/Dtor"

  ControlButton(KeyCode code)
      : keyCode(core::detail::toBase(code)) {}

  ControlButton(u32_t code)
      : keyCode(code) {}

#pragma endregion

#pragma region "Override Equalable methods"

  MTHD_OVERRIDE(auto equal(u32_t code) const -> bool) { return keyCode == code; }

#pragma endregion
};

template <>
struct ControlButton<InputActionType::MOUSE_BUTTON> : public Equalable<u32_t> {
#pragma region "Public members"

  u32_t btnCode;

#pragma endregion

#pragma region "Static members"

  static const InputActionType type = InputActionType::MOUSE_BUTTON;

#pragma endregion

#pragma region "Ctors/Dtor"

  ControlButton(MouseButtonCode btn)
      : btnCode(core::detail::toBase(btn)) {}

  ControlButton(u32_t btn)
      : btnCode(btn) {}

#pragma endregion

#pragma region "Override Equalable methods"

  MTHD_OVERRIDE(auto equal(u32_t btn) const -> bool) { return btnCode == btn; }

#pragma endregion
};

template <>
struct ControlButton<InputActionType::MOUSE_WHEEL> : public Equalable<u32_t> {
#pragma region "Public members"

  u32_t action;

#pragma endregion

#pragma region "Static members"

  static const InputActionType type = InputActionType::MOUSE_WHEEL;

#pragma endregion

#pragma region "Ctors/Dtor"

  ControlButton(MouseWheelScrollAction act)
      : action(core::detail::toBase(act)) {}

  ControlButton(u32_t act)
      : action(act) {}

#pragma endregion

#pragma region "Override Equalable methods"

  MTHD_OVERRIDE(auto equal(u32_t act) const -> bool) { return action == act; }

#pragma endregion
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_SCHEME_CONTROLBUTTON_HPP
