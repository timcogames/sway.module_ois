#ifndef SWAY_OISMACROS_HPP
#define SWAY_OISMACROS_HPP

#include <sway/core.hpp>

#undef D_MODULE_OIS_INTERFACE_EXPORT_API
#ifdef D_MODULE_OIS_INTERFACE_EXPORT
#  if defined(EMSCRIPTEN_PLATFORM)
#    include <emscripten.h>
#    define D_MODULE_OIS_INTERFACE_EXPORT_API EMSCRIPTEN_KEEPALIVE
#  else
#    define D_MODULE_OIS_INTERFACE_EXPORT_API PUBLIC_ATTRIB
#  endif
#else
#  define D_MODULE_OIS_INTERFACE_EXPORT_API
#endif

#endif  // SWAY_OISMACROS_HPP
