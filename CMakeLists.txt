# Проверяем версию CMake
cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

# Мета-информация о проекте
set(META_PROJECT_NAME module_ois_x11)
set(META_LIB_NAME lib${META_PROJECT_NAME})
set(META_VERSION_MAJOR 0)
set(META_VERSION_MINOR 5)
set(META_VERSION_PATCH 13)
set(META_VERSION ${META_VERSION_MAJOR}.${META_VERSION_MINOR}.${META_VERSION_PATCH})

# Опции сборки
option(BUILD_SHARED "Build shared library" OFF)

project(${META_PROJECT_NAME} C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Определяем каталог вывода по умолчанию
if(CMAKE_BUILD_TYPE MATCHES Debug)
	set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/dbg)
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/dbg)
else()
	set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
endif()

set(MODULE_OIS_X11_DIR ${CMAKE_CURRENT_LIST_DIR})

# Добавляем пути для поиска хедеров
include_directories(${MODULE_OIS_X11_DIR}/include)
include_directories(${MODULE_OIS_X11_DIR}/modules/sway.module_core/include)
include_directories(${MODULE_OIS_X11_DIR}/modules/sway.module_math/include)

# Получаем пути ко всем хедерам и исходникам библиотеки
file(GLOB_RECURSE MODULE_OIS_X11_HEADERS ${MODULE_OIS_X11_DIR}/include/*.*)
file(GLOB_RECURSE MODULE_OIS_X11_SOURCE ${MODULE_OIS_X11_DIR}/src/*.*)

find_package(X11 REQUIRED)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_NO_SYSTEM_PATHS TRUE)
set(BOOST_COMPONENTS unit_test_framework)

if(Boost_NO_SYSTEM_PATHS)
	set(BOOST_ROOT "/usr/local")
	set(BOOST_INCLUDE_DIR "${BOOST_ROOT}/include")
	set(BOOST_LIBRARY_DIR "${BOOST_ROOT}/lib")
endif(Boost_NO_SYSTEM_PATHS)

find_package(Boost 1.69.0 REQUIRED COMPONENTS ${BOOST_COMPONENTS})
if(NOT Boost_FOUND)
	message(FATAL_ERROR "Fatal error: Boost (version >= 1.69.0) required.")
else()
	message(STATUS "Boost includes: ${BOOST_INCLUDE_DIR}")
	message(STATUS "Boost libs: ${BOOST_LIBRARY_DIR}")

	include_directories(${BOOST_INCLUDE_DIR})
endif()

if(BUILD_SHARED)
	# Добавляем в проект цель для сборки статической библиотеки
	add_library(${META_LIB_NAME} SHARED ${MODULE_OIS_X11_SOURCE})
	set_target_properties(${META_LIB_NAME} PROPERTIES OUTPUT_NAME ${META_PROJECT_NAME})
	set_target_properties(${META_LIB_NAME} PROPERTIES PREFIX "")
	set_target_properties(${META_LIB_NAME} PROPERTIES SUFFIX ".so.${META_VERSION}")
else()
	# Добавляем в проект цель для сборки динамической библиотеки
	add_library(${META_LIB_NAME} STATIC ${MODULE_OIS_X11_SOURCE})
	set_target_properties(${META_LIB_NAME} PROPERTIES OUTPUT_NAME ${META_PROJECT_NAME})
	set_target_properties(${META_LIB_NAME} PROPERTIES PREFIX "")
	set_target_properties(${META_LIB_NAME} PROPERTIES SUFFIX ".a.${META_VERSION}")
endif()

target_link_libraries(${META_LIB_NAME} X11 ${BOOST_LIBRARIES})
