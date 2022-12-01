# Проверяем версию CMake
cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

include("${CMAKE_CURRENT_SOURCE_DIR}/submodules/sway.module_core/cmakehelpers/custom_enable_cxx17.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/submodules/sway.module_core/cmakehelpers/custom_add_subdirectory.cmake")

# Мета-информация о проекте
set(META_OISX11_PRJNAME "module_ois_x11")
set(META_OISX11_LIBNAME "lib${META_OISX11_PRJNAME}")
set(META_OISX11_VERSION_MAJOR 0)
set(META_OISX11_VERSION_MINOR 5)
set(META_OISX11_VERSION_PATCH 14)
set(META_OISX11_VERSION ${META_OISX11_VERSION_MAJOR}.${META_OISX11_VERSION_MINOR}.${META_OISX11_VERSION_PATCH})

# Опции сборки
option(MODULE_OISX11_SHARED_LIB "Build shared library" OFF)
option(MODULE_OISX11_ENABLE_EXAMPLES "Build examples" OFF)

project(${META_OISX11_PRJNAME} VERSION ${META_OISX11_VERSION} LANGUAGES CXX)

# Подмодули
custom_add_subdirectory("libmodule_core" submodules/sway.module_core)

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
set(MODULE_OISX11_DIR ${CMAKE_CURRENT_LIST_DIR})

# Добавляем пути для поиска хедеров
include_directories("${SYSTEM_INCLUDE_DIRS}")
include_directories("${MODULE_OISX11_DIR}/lib/include")
include_directories("${MODULE_OISX11_DIR}/submodules/sway.module_core/lib/include")
include_directories("${MODULE_OISX11_DIR}/submodules/sway.module_math/lib/include")

# Получаем пути ко всем хедерам и исходникам библиотеки
file(GLOB_RECURSE MODULE_OISX11_HEADERS "${MODULE_OISX11_DIR}/lib/include/*.*")
file(GLOB_RECURSE MODULE_OISX11_SOURCES "${MODULE_OISX11_DIR}/lib/src/*.*")

find_package(X11 REQUIRED)

if(MODULE_OISX11_SHARED_LIB)
	# Добавляем в проект цель для сборки статической библиотеки
	add_library(${META_OISX11_LIBNAME} SHARED ${MODULE_OISX11_SOURCES})
	set_target_properties(${META_OISX11_LIBNAME} PROPERTIES OUTPUT_NAME ${META_OISX11_PRJNAME})
	set_target_properties(${META_OISX11_LIBNAME} PROPERTIES PREFIX "")
	set_target_properties(${META_OISX11_LIBNAME} PROPERTIES SUFFIX ".so.${META_OISX11_VERSION}")
else()
	# Добавляем в проект цель для сборки динамической библиотеки
	add_library(${META_OISX11_LIBNAME} STATIC ${MODULE_OISX11_SOURCES})
	set_target_properties(${META_OISX11_LIBNAME} PROPERTIES OUTPUT_NAME ${META_OISX11_PRJNAME})
	set_target_properties(${META_OISX11_LIBNAME} PROPERTIES PREFIX "")
	set_target_properties(${META_OISX11_LIBNAME} PROPERTIES SUFFIX ".a.${META_OISX11_VERSION}")
endif()

custom_enable_cxx17(${META_OISX11_LIBNAME})
# target_link_libraries(${META_OISX11_LIBNAME} X11)

# Добавляем построение примеров
if (MODULE_OISX11_ENABLE_EXAMPLES)
  message(STATUS "Examples have been enabled")
  add_subdirectory("examples/01")
endif ()
