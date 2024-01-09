#---------------------------------------------------------------------------------
# CMake version
#---------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

#---------------------------------------------------------------------------------
# Project directories
#---------------------------------------------------------------------------------

set(MODULE_OIS_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MODULE_OIS_CMAKE_DIR ${MODULE_OIS_ROOT_DIR}/submodules/sway.module_core/cmake_modules)
set(MODULE_OIS_LIB_DIR ${MODULE_OIS_ROOT_DIR}/lib)
set(MODULE_OIS_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

#---------------------------------------------------------------------------------
# Include CMake modules
#---------------------------------------------------------------------------------

include("${MODULE_OIS_CMAKE_DIR}/options.cmake")
include("${MODULE_OIS_CMAKE_DIR}/set_output_dir.cmake")
include("${MODULE_OIS_CMAKE_DIR}/add_submodule.cmake")
include("${MODULE_OIS_CMAKE_DIR}/project_metadata.cmake")
include("${MODULE_OIS_CMAKE_DIR}/modules/logger.cmake")
include("${MODULE_OIS_CMAKE_DIR}/modules/create_object.cmake")
include("${MODULE_OIS_CMAKE_DIR}/modules/create_interface.cmake")
include("${MODULE_OIS_CMAKE_DIR}/modules/compiler/clang/create_library.cmake")
include("${MODULE_OIS_CMAKE_DIR}/modules/compiler/emscripten/setup.cmake")
include("${MODULE_OIS_CMAKE_DIR}/modules/compiler/emscripten/create_library.cmake")
include("${MODULE_OIS_CMAKE_DIR}/modules/compiler/emscripten/gen_target_name.cmake")
include("${MODULE_OIS_CMAKE_DIR}/modules/compiler/emscripten/set_optimization.cmake")
include("${MODULE_OIS_CMAKE_DIR}/modules/compiler/emscripten/set_environment.cmake")
include("${MODULE_OIS_CMAKE_DIR}/modules/compiler/emscripten/set_compilation.cmake")
include("${MODULE_OIS_CMAKE_DIR}/modules/compiler/emscripten/set_modularize.cmake")
include("${MODULE_OIS_CMAKE_DIR}/enable_cxx17.cmake")
include("${MODULE_OIS_CMAKE_DIR}/enable_coverage.cmake")

#---------------------------------------------------------------------------------
# Build options
#---------------------------------------------------------------------------------

option(MODULE_OIS_SHARED_LIB "Build shared library" OFF)
option(MODULE_OIS_ENABLE_TESTS "Build tests" OFF)
option(MODULE_OIS_ENABLE_EXAMPLES "Build examples" OFF)

#---------------------------------------------------------------------------------
# [Emscripten]: Setup
#---------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  emscripten_setup()
endif()

#---------------------------------------------------------------------------------
# Project
#---------------------------------------------------------------------------------

project_metadata("ois" 0.6.0)
project(${MODULE_OIS_PROJ_NAME} VERSION ${MODULE_OIS_VERSION} LANGUAGES CXX)

if(GLOB_EMSCRIPTEN_PLATFORM)
  set(CMAKE_CXX_COMPILER "${EMSCRIPTEN_COMPILER}")
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--whole-archive")
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-unicode-whitespace \
  #   -Wno-unused-local-typedef -Wno-invalid-noreturn -Wno-unused-command-line-argument")
endif()

#---------------------------------------------------------------------------------
# Submodules
#---------------------------------------------------------------------------------

add_submodule("module_core" submodules/sway.module_core)

#---------------------------------------------------------------------------------
# Executable output path
#---------------------------------------------------------------------------------

set_output_dir(${MODULE_OIS_BIN_DIR})

set(SYSTEM_INCLUDE_DIRS "/opt/X11/include")
set(SYSTEM_LIBRARY_DIRS "/opt/X11/lib")
set(MODULE_OIS_DIR ${CMAKE_CURRENT_LIST_DIR})

#---------------------------------------------------------------------------------
# Include project headers
#---------------------------------------------------------------------------------

include_directories("${SYSTEM_INCLUDE_DIRS}")
include_directories("${MODULE_OIS_DIR}/lib/cxx/include")
include_directories("${MODULE_OIS_DIR}/submodules/sway.module_core/lib/cxx/include")
include_directories("${MODULE_OIS_DIR}/submodules/sway.module_math/lib/cxx/include")

# Получаем пути ко всем хедерам и исходникам библиотеки
file(GLOB_RECURSE MODULE_OIS_HEADERS "${MODULE_OIS_DIR}/lib/cxx/include/*.*")
if(GLOB_EMSCRIPTEN_PLATFORM)
  file(GLOB_RECURSE MODULE_OIS_SOURCES "${MODULE_OIS_DIR}/lib/cxx/src/inputdevicemanager.cpp"
                                       "${MODULE_OIS_DIR}/lib/cxx/src/web/*.*")
else()
  file(GLOB_RECURSE MODULE_OIS_SOURCES "${MODULE_OIS_DIR}/lib/cxx/src/mac/*.*")
endif()

if(GLOB_EMSCRIPTEN_PLATFORM)
  # Empty
else()
  find_package(X11 REQUIRED)
endif()

# if(MODULE_OIS_SHARED_LIB)
#   # Добавляем в проект цель для сборки статической библиотеки
#   add_library(${MODULE_OIS_TARGET} SHARED ${MODULE_OIS_SOURCES})
#   set_target_properties(${MODULE_OIS_TARGET} PROPERTIES OUTPUT_NAME ${MODULE_OIS_TARGET})
#   set_target_properties(${MODULE_OIS_TARGET} PROPERTIES PREFIX "")
#   set_target_properties(${MODULE_OIS_TARGET} PROPERTIES SUFFIX ".so")
# else()
#   # Добавляем в проект цель для сборки динамической библиотеки
#   add_library(${MODULE_OIS_TARGET} STATIC ${MODULE_OIS_SOURCES})
#   set_target_properties(${MODULE_OIS_TARGET} PROPERTIES OUTPUT_NAME ${MODULE_OIS_TARGET})
#   set_target_properties(${MODULE_OIS_TARGET} PROPERTIES PREFIX "")
#   set_target_properties(${MODULE_OIS_TARGET} PROPERTIES SUFFIX ".a")
# endif()

# enable_cxx17(${MODULE_OIS_TARGET})
# # target_link_libraries(${META_OIS_LIBNAME} X11)

if(GLOB_EMSCRIPTEN_PLATFORM)
  create_object(${MODULE_OIS_TARGET} "${MODULE_OIS_ROOT_DIR}/lib/cxx/src/*.*" TRUE)
  enable_cxx17(${MODULE_OIS_TARGET})

  create_emscripten_library(${MODULE_OIS_TARGET} ${MODULE_OIS_ENVIRONMENT} ${MODULE_OIS_COMPILATION} OUTPUT_TARGET_NAME_LIST)
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
endif()

#---------------------------------------------------------------------------------
# Tests
#---------------------------------------------------------------------------------

if(MODULE_OIS_ENABLE_TESTS)
  message(STATUS "Tests have been enabled")
endif()

#---------------------------------------------------------------------------------
# Examples
#---------------------------------------------------------------------------------

if(MODULE_OIS_ENABLE_EXAMPLES)
  message(STATUS "Examples have been enabled")
  add_subdirectory("examples/01")
endif()
