#ifndef SWAY_OIS_INPUTEVENT_HPP
#define SWAY_OIS_INPUTEVENT_HPP

#include <sway/core.hpp>
#include <sway/ois/inputactiontypes.hpp>

#include <string>

namespace sway::ois {

class InputEvent : public core::Event {
  DECLARE_CLASS_METADATA(InputEvent, core::Event)

public:
#pragma region "Ctors/Dtor"

  InputEvent(u32_t type, core::EventDataTypedefs::Ptr_t data)
      : id_(core::newGuid<core::constans::UUID_MAGIC_SIZE>(core::constans::UUID_MAGIC))
      , type_(type)
      , data_(data) {}

  ~InputEvent() = default;

#pragma endregion

#pragma region "Override Event methods"

  MTHD_OVERRIDE(auto getId() const -> std::string) { return id_; }

  MTHD_OVERRIDE(auto getType() const -> u32_t) { return type_; }

  MTHD_OVERRIDE(auto getData() const -> core::EventDataTypedefs::Ptr_t) { return data_; }

#pragma endregion

private:
  std::string id_;
  u32_t type_;
  core::EventDataTypedefs::Ptr_t data_;
};

}  // namespace sway::ois

#endif  // SWAY_OIS_INPUTEVENT_HPP
