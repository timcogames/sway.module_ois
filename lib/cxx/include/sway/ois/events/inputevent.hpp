#ifndef SWAY_OIS_INPUTEVENT_HPP
#define SWAY_OIS_INPUTEVENT_HPP

#include <sway/core.hpp>
#include <sway/ois/inputactiontypes.hpp>

#include <string>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

class InputEvent : public core::foundation::Event {
  DECLARE_CLASS_METADATA(InputEvent, core::foundation::Event)

public:
#pragma region "Ctors/Dtor"

  InputEvent(u32_t type, core::foundation::EventData::Ptr_t data)
      : id_(core::misc::newGuid<UUID_NBR_OF_GROUPS>(UUID_MAGIC))
      , type_(type)
      , data_(data) {}

  ~InputEvent() = default;

#pragma endregion

#pragma region "Override Event methods"

  MTHD_OVERRIDE(auto id() const -> std::string) { return id_; }

  MTHD_OVERRIDE(auto type() const -> u32_t) { return type_; }

  MTHD_OVERRIDE(auto data() const -> core::foundation::EventData::Ptr_t) { return data_; }

#pragma endregion

private:
  std::string id_;
  u32_t type_;
  core::foundation::EventData::Ptr_t data_;
};

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_INPUTEVENT_HPP
