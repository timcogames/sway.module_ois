#include <sway/core.hpp>
#include <sway/ois.hpp>

#include <iostream>
#include <memory>  // std::shared_ptr, std::make_shared

using namespace sway;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  auto *inputDeviceManager = new ois::InputDeviceManager(nullptr, 0);
  inputDeviceManager->registerDevice<ois::Keyboard>();

  do {
    std::cout << '\n' << "Press a key to continue...";
  } while (std::cin.get() != '\n');
  return 0;
}
