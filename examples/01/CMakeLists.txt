# Мета-информация о проекте
set(META_PRJNAME_EXAMPLES "module_ois_examples_01")
set(META_LIBNAME_EXAMPLES "${META_PRJNAME_EXAMPLES}")

project(${META_PRJNAME_EXAMPLES} CXX)

set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SYSTEM_X11_INCLUDE_DIRS "/opt/X11/include")
set(SYSTEM_X11_LIBRARY_DIRS "/opt/X11/lib")

include_directories("${SYSTEM_X11_INCLUDE_DIRS}")
include_directories("${MODULE_OIS_DIR}/submodules/sway.module_ois-x11/lib/cxx/include")

# Получаем пути ко всем исходникам с тестами
file(GLOB MODULE_OIS_SOURCE_EXAMPLES ${PROJECT_SOURCE_DIR}/*.cpp)

find_package(X11 REQUIRED)

link_directories("${SYSTEM_X11_LIBRARY_DIRS}")

add_executable(${META_LIBNAME_EXAMPLES} ${MODULE_OIS_SOURCE_EXAMPLES})
target_link_libraries(${META_LIBNAME_EXAMPLES} -lX11 -lpthread module_ois module_core)
