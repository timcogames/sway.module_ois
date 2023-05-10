# Проверяем версию CMake
cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

include("${CMAKE_CURRENT_SOURCE_DIR}/submodules/sway.module_core/cmakehelpers/custom_enable_cxx17.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/submodules/sway.module_core/cmakehelpers/custom_add_subdirectory.cmake")

# Мета-информация о проекте
set(META_OIS_PRJNAME "module_ois")
set(META_OIS_LIBNAME "lib${META_OIS_PRJNAME}")
set(META_OIS_VERSION_MAJOR 0)
set(META_OIS_VERSION_MINOR 5)
set(META_OIS_VERSION_PATCH 14)
set(META_OIS_VERSION ${META_OIS_VERSION_MAJOR}.${META_OIS_VERSION_MINOR}.${META_OIS_VERSION_PATCH})

# Опции сборки
option(MODULE_OIS_SHARED_LIB "Build shared library" OFF)
option(MODULE_OIS_ENABLE_EXAMPLES "Build examples" OFF)
option(GLOBAL_EMSCRIPTEN_PLATFORM "Using emscripten compiler" OFF)
option(GLOBAL_EMSCRIPTEN_USE_BINDING "Using emscripten binding" OFF)
option(CUSTOM_EMSCRIPTEN_ROOT_DIR "Emscripten root directory" OFF)

project(${META_OIS_PRJNAME} VERSION ${META_OIS_VERSION} LANGUAGES CXX)

set(CMAKE_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk")

if (GLOBAL_EMSCRIPTEN_PLATFORM AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "${CUSTOM_EMSCRIPTEN_ROOT_DIR}/cmake/Modules/Platform/Emscripten.cmake")
  include(${CMAKE_TOOLCHAIN_FILE})
endif ()

# Подмодули
if (NOT TARGET libmodule_core)
  custom_add_subdirectory("libmodule_core" submodules/sway.module_core)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Определяем каталог вывода по умолчанию
if(CMAKE_BUILD_TYPE MATCHES Debug)
	set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/dbg")
	set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/dbg")
else()
	set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")
	set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")
endif()

set(SYSTEM_INCLUDE_DIRS "/opt/X11/include")
set(SYSTEM_LIBRARY_DIRS "/opt/X11/lib")
set(MODULE_OIS_DIR ${CMAKE_CURRENT_LIST_DIR})

# Добавляем пути для поиска хедеров
include_directories("${SYSTEM_INCLUDE_DIRS}")
include_directories("${MODULE_OIS_DIR}/lib/include")
include_directories("${MODULE_OIS_DIR}/submodules/sway.module_core/lib/include")
include_directories("${MODULE_OIS_DIR}/submodules/sway.module_math/lib/include")

# Получаем пути ко всем хедерам и исходникам библиотеки
file(GLOB_RECURSE MODULE_OIS_HEADERS "${MODULE_OIS_DIR}/lib/include/*.*")
if (GLOBAL_EMSCRIPTEN_PLATFORM)
	file(GLOB_RECURSE MODULE_OIS_SOURCES "${MODULE_OIS_DIR}/lib/src/web/*.*")
else ()
  file(GLOB_RECURSE MODULE_OIS_SOURCES "${MODULE_OIS_DIR}/lib/src/mac/*.*")
endif ()

find_package(X11 REQUIRED)

if(MODULE_OIS_SHARED_LIB)
	# Добавляем в проект цель для сборки статической библиотеки
	add_library(${META_OIS_LIBNAME} SHARED ${MODULE_OIS_SOURCES})
	set_target_properties(${META_OIS_LIBNAME} PROPERTIES OUTPUT_NAME ${META_OIS_PRJNAME})
	set_target_properties(${META_OIS_LIBNAME} PROPERTIES PREFIX "")
	set_target_properties(${META_OIS_LIBNAME} PROPERTIES SUFFIX ".so.${META_OIS_VERSION}")
else()
	# Добавляем в проект цель для сборки динамической библиотеки
	add_library(${META_OIS_LIBNAME} STATIC ${MODULE_OIS_SOURCES})
	set_target_properties(${META_OIS_LIBNAME} PROPERTIES OUTPUT_NAME ${META_OIS_PRJNAME})
	set_target_properties(${META_OIS_LIBNAME} PROPERTIES PREFIX "")
	set_target_properties(${META_OIS_LIBNAME} PROPERTIES SUFFIX ".a.${META_OIS_VERSION}")
endif()

custom_enable_cxx17(${META_OIS_LIBNAME})
# target_link_libraries(${META_OIS_LIBNAME} X11)

# Добавляем построение примеров
if (MODULE_OIS_ENABLE_EXAMPLES)
  message(STATUS "Examples have been enabled")
  add_subdirectory("examples/01")
endif ()
