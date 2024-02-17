#ifndef SWAY_OIS_EVENTBUS_HPP
#define SWAY_OIS_EVENTBUS_HPP

#include <sway/core.hpp>
#include <sway/ois/events/eventhandler.hpp>

#include <memory>
#include <queue>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class Subscribable {
protected:
  std::vector<EventHandler *> subscriptions_;

public:
  using Subscriber = decltype(subscriptions_)::iterator;

  auto subscribe(EventHandler *handler) -> Subscriber { return subscriptions_.insert(subscriptions_.end(), handler); }

  void unsubscribe(Subscriber subscriber) { subscriptions_.erase(subscriber); }

  void handle(const std::unique_ptr<core::foundation::Event> &event) {
    for (auto &handler : this->subscriptions_) {
      handler->invoke(event);
    }
  }
};

class EventBus : public Subscribable {
public:
  ~EventBus() = default;

  void addToQueue(std::unique_ptr<core::foundation::Event> event) { events_.emplace(std::move(event)); }

  void process() {
    while (!events_.empty()) {
      const auto &event = events_.front();

      this->handle(event);
      events_.pop();
    }
  }

private:
  std::queue<std::unique_ptr<core::foundation::Event>> events_{};
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_EVENTBUS_HPP
