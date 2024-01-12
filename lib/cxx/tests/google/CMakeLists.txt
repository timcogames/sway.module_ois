set(META_OIS_PRJNAME_TESTS "module_ois_tests")
set(META_OIS_EXENAME_TESTS "${META_OIS_PRJNAME_TESTS}")

project(${META_OIS_PRJNAME_TESTS} CXX)
enable_testing()

set(GTEST_ROOT "${GLOB_GTEST_ROOT_DIR}")
set(GTEST_INC_DIR "${GTEST_ROOT}/include")
set(GTEST_SRC_DIR "${GTEST_ROOT}/src")

set(GMOCK_ROOT "${GLOB_GMOCK_ROOT_DIR}")
set(GMOCK_INC_DIR "${GMOCK_ROOT}/include")

include_directories(${GTEST_INC_DIR} ${GMOCK_INC_DIR})

file(GLOB MODULE_OIS_SOURCE_TESTS "${PROJECT_SOURCE_DIR}/*.spec.cpp")

add_executable(${META_OIS_EXENAME_TESTS} ${MODULE_OIS_SOURCE_TESTS} "${GTEST_SRC_DIR}/gtest_main.cc")
target_link_libraries(${META_OIS_EXENAME_TESTS} module_ois module_core pthread ${GLOB_GTEST_LIB_DIR}/libgtest.a ${GLOB_GMOCK_LIB_DIR}/libgmock.a)
enable_cxx17(${META_OIS_EXENAME_TESTS})

add_test(NAME ${META_OIS_EXENAME_TESTS} COMMAND ${META_OIS_EXENAME_TESTS})
