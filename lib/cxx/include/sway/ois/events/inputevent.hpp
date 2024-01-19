#ifndef SWAY_OIS_INPUTEVENT_HPP
#define SWAY_OIS_INPUTEVENT_HPP

#include <sway/core.hpp>
#include <sway/ois/inputactiontypes.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputEvent : public core::foundation::Event {
public:
  DECLARE_CLASS_METADATA(InputEvent, core::foundation::Event)

  InputEvent(u32_t type, core::foundation::EventData *data)
      : id_(core::misc::newGuid<UUID_NBR_OF_GROUPS>(UUID_MAGIC))
      , type_(type)
      , data_(data) {}

  ~InputEvent() = default;

  // clang-format off
  MTHD_OVERRIDE(auto id() const -> std::string) {  // clang-format on
    return id_;
  }

  // clang-format off
  MTHD_OVERRIDE(auto type() const -> u32_t) {  // clang-format on
    return type_;
  }

  // clang-format off
  MTHD_OVERRIDE(auto data() const -> core::foundation::EventData *) {  // clang-format on
    return data_;
  }

private:
  std::string id_;
  u32_t type_;
  core::foundation::EventData *data_;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTEVENT_HPP
