#---------------------------------------------------------------------------------
# Project directories
#---------------------------------------------------------------------------------

set(SYSTEM_INC_DIR "/opt/X11/include")
set(SYSTEM_LIB_DIR "/opt/X11/lib")

#---------------------------------------------------------------------------------
# [Emscripten]: Setup
#---------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  emscripten_setup()
endif()

#---------------------------------------------------------------------------------
# Include project headers
#---------------------------------------------------------------------------------

include_directories("${SYSTEM_INC_DIR}")
include_directories("${MODULE_OIS_LIST_DIR}/lib/cxx/include")
include_directories("${MODULE_OIS_LIST_DIR}/submodules/sway.module_core/lib/cxx/include")
include_directories("${MODULE_OIS_LIST_DIR}/submodules/sway.module_math/lib/cxx/include")

#---------------------------------------------------------------------------------
# Find the project headers, sources
#---------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  file(GLOB_RECURSE MODULE_OIS_SOURCES "${MODULE_OIS_LIST_DIR}/lib/cxx/src/inputdevicemanager.cpp"
                                       "${MODULE_OIS_LIST_DIR}/lib/cxx/src/web/*.*")
else()
  file(GLOB_RECURSE MODULE_OIS_SOURCES "${MODULE_OIS_LIST_DIR}/lib/cxx/src/mac/*.*")
endif()

#---------------------------------------------------------------------------------
# Find packages
#---------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  # Empty
else()
  find_package(X11 REQUIRED)
endif()

#---------------------------------------------------------------------------------
# Create object
#---------------------------------------------------------------------------------

create_object_library(${MODULE_OIS_OBJ_TARGET} "${MODULE_OIS_ROOT_DIR}/lib/cxx/src/*.*" TRUE)
enable_cxx17(${MODULE_OIS_OBJ_TARGET})

#---------------------------------------------------------------------------------
# Build libraries
#---------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  create_emscripten_library(${MODULE_OIS_LIB_TARGET} ${MODULE_OIS_ENVIRONMENT} ${MODULE_OIS_COMPILATION} OUTPUT_TARGET_NAME_LIST)
  foreach(target IN LISTS OUTPUT_TARGET_NAME_LIST)
    target_link_options(${target} PUBLIC 
      "SHELL:-s STRICT=1"
      "SHELL:-s MODULARIZE=1"
      "SHELL:-s ALLOW_TABLE_GROWTH=1"
      "SHELL:-s EXPORT_NAME=\"create_ois_module\""
      "SHELL:-s EXPORTED_RUNTIME_METHODS=@${MODULE_OIS_LIB_DIR}/runtime-exports.json")

    if(NOT GLOB_EMSCRIPTEN_USE_BINDINGS)
      target_link_options(${target} PUBLIC "SHELL:-s EXPORTED_FUNCTIONS=@${MODULE_OIS_LIB_DIR}/exports.json")
    endif()

    printf_link_options(${target})
  endforeach()
else()
  create_clang_library(${MODULE_OIS_LIB_TARGET} "${MODULE_OIS_ROOT_DIR}/lib/cxx/src/*.*")
endif()
