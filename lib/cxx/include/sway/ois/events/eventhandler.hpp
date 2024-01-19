#ifndef SWAY_OIS_EVENTHANDLER_HPP
#define SWAY_OIS_EVENTHANDLER_HPP

#include <sway/core.hpp>

#include <memory>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class EventHandler {
public:
  virtual ~EventHandler() = default;

  // clang-format off
  PURE_VIRTUAL(auto invoke(const std::unique_ptr<core::foundation::Event> &event) -> bool);  // clang-format on
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_EVENTHANDLER_HPP
