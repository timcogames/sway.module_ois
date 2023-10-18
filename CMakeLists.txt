cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

set(MODULE_OIS_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MODULE_OIS_CMAKE_DIR ${MODULE_OIS_ROOT_DIR}/submodules/sway.module_core/cmakehelpers)
set(MODULE_OIS_LIB_DIR ${MODULE_OIS_ROOT_DIR}/lib)
set(MODULE_OIS_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

#_________________________________________________________________________________
#                                                            Include CMake modules
include("${MODULE_OIS_CMAKE_DIR}/options.cmake")
include("${MODULE_OIS_CMAKE_DIR}/set_output_dir.cmake")
include("${MODULE_OIS_CMAKE_DIR}/add_submodule.cmake")
include("${MODULE_OIS_CMAKE_DIR}/project_metadata.cmake")
include("${MODULE_OIS_CMAKE_DIR}/emscripten/setup.cmake")
include("${MODULE_OIS_CMAKE_DIR}/emscripten/compiler.cmake")
include("${MODULE_OIS_CMAKE_DIR}/emscripten/compiler_flags/set_modularize.cmake")
include("${MODULE_OIS_CMAKE_DIR}/emscripten/compiler_flags/set_environment.cmake")
include("${MODULE_OIS_CMAKE_DIR}/emscripten/compiler_flags/set_optimization.cmake")
include("${MODULE_OIS_CMAKE_DIR}/emscripten/compiler_flags/set_config.cmake")
include("${MODULE_OIS_CMAKE_DIR}/emscripten/compiler_flags/set_exports.cmake")
include("${MODULE_OIS_CMAKE_DIR}/detect_library_extension.cmake")
include("${MODULE_OIS_CMAKE_DIR}/create_library.cmake")
include("${MODULE_OIS_CMAKE_DIR}/enable_cxx17.cmake")
include("${MODULE_OIS_CMAKE_DIR}/enable_coverage.cmake")

#_________________________________________________________________________________
#                                                                    Build options
option(MODULE_OIS_SHARED_LIB "Build shared library" OFF)
option(MODULE_OIS_ENABLE_TESTS "Build tests" OFF)
option(MODULE_OIS_ENABLE_EXAMPLES "Build examples" OFF)

#_________________________________________________________________________________
#                                                                       Submodules
add_submodule("core" submodules/sway.module_core)

#_________________________________________________________________________________
#                                                              [Emscripten]: Setup
if(GLOB_EMSCRIPTEN_PLATFORM)
  emscripten_setup()
endif()

#_________________________________________________________________________________
#                                                                          Project
project_metadata("ois" 0.6.0)
project(${MODULE_OIS_PROJ_NAME} VERSION ${MODULE_OIS_VERSION} LANGUAGES CXX)

if(GLOB_EMSCRIPTEN_PLATFORM)
  set(CMAKE_CXX_COMPILER "${EMSCRIPTEN_COMPILER}")
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--whole-archive")
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-unicode-whitespace \
  #   -Wno-unused-local-typedef -Wno-invalid-noreturn -Wno-unused-command-line-argument")
endif()

#_________________________________________________________________________________
#                                                           Executable output path
set_output_dir(${MODULE_OIS_BIN_DIR})

set(SYSTEM_INCLUDE_DIRS "/opt/X11/include")
set(SYSTEM_LIBRARY_DIRS "/opt/X11/lib")
set(MODULE_OIS_DIR ${CMAKE_CURRENT_LIST_DIR})

#_________________________________________________________________________________
#                                                          Include project headers
include_directories("${SYSTEM_INCLUDE_DIRS}")
include_directories("${MODULE_OIS_DIR}/lib/cpp/include")
include_directories("${MODULE_OIS_DIR}/submodules/sway.module_core/lib/cpp/include")
include_directories("${MODULE_OIS_DIR}/submodules/sway.module_math/lib/cpp/include")

# Получаем пути ко всем хедерам и исходникам библиотеки
file(GLOB_RECURSE MODULE_OIS_HEADERS "${MODULE_OIS_DIR}/lib/cpp/include/*.*")
if(GLOB_EMSCRIPTEN_PLATFORM)
  file(GLOB_RECURSE MODULE_OIS_SOURCES "${MODULE_OIS_DIR}/lib/cpp/src/inputdevicemanager.cpp"
                                       "${MODULE_OIS_DIR}/lib/cpp/src/web/*.*")
else()
  file(GLOB_RECURSE MODULE_OIS_SOURCES "${MODULE_OIS_DIR}/lib/cpp/src/mac/*.*")
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
  create_bitcode_library(${MODULE_OIS_TARGET} ${MODULE_OIS_PROJ_NAME} "${MODULE_OIS_ROOT_DIR}/lib/cpp/src/*.*")
  enable_cxx17(${MODULE_OIS_TARGET})

  set(LIB_NAME_LIST ${MODULE_OIS_LIB_NAME})

  emscripten_set_compiler_javascript(MODULE_OIS_COMPILER_WEBJS_CONFIG
    ${MODULE_OIS_BIN_DIR} LIB_NAME_LIST ${MODULE_OIS_VERSION})
  emscripten_set_config(${MODULE_OIS_PROJ_NAME} MODULE_OIS_COMPILER_WEBJS_CONFIG)
  emscripten_set_exports(MODULE_OIS_COMPILER_WEBJS_CONFIG ${MODULE_OIS_LIB_DIR}/exports.json)
  emscripten_set_runtime_exports(MODULE_OIS_COMPILER_WEBJS_CONFIG ${MODULE_OIS_LIB_DIR}/runtime_exports.json 1)

  add_custom_command(TARGET ${MODULE_OIS_TARGET} POST_BUILD
    COMMAND ${MODULE_OIS_COMPILER_WEBJS_CONFIG}
    # COMMAND rm "${MODULE_CORE_BIN_DIR}/${MODULE_CORE_LIB_NAME}.bc"
  )
endif()

#_________________________________________________________________________________
#                                                                            Tests
if(MODULE_OIS_ENABLE_TESTS)
  message(STATUS "Tests have been enabled")
endif()

#_________________________________________________________________________________
#                                                                         Examples
if(MODULE_OIS_ENABLE_EXAMPLES)
  message(STATUS "Examples have been enabled")
  add_subdirectory("examples/01")
endif()
