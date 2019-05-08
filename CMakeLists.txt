cmake_minimum_required(VERSION 3.9)
set(CMAKE_C_STANDARD 99)

# Projects
set(PROSE_PROJECT_NAME NexetupC)
project(${PROSE_PROJECT_NAME} C)

# Module path (usefull for finding libs)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

# Coverage
include(CodeCoverage)

# CTest
enable_testing()
include(CTest)

# Include every src files
file(GLOB_RECURSE everyFile "src/*.c" "src/*.h")
add_executable(${PROSE_PROJECT_NAME} ${everyFile} src/main.c)

# CMocka lib
set(CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/test/cmocka")
find_library(LIB_CMOCKA libCMocka NAMES CICD.so)

if (NOT LIB_CMOCKA)
    message(FATAL_ERROR "library not found")
endif()

set(GLOBAL_LIBS pthread rt)

# Tests

list(APPEND testsNames mainExampleTestMocked)
list(APPEND testsFlags "-Wl,--wrap=MailboxInit")

list(LENGTH testsNames testsCount)
math(EXPR testsCount "${testsCount} - 1")

foreach(i RANGE ${testsCount})
    list(GET testsNames ${i} testName)
    list(GET testsFlags ${i} testFlags)

    add_executable(${testName} test/${testName}.c)

    target_link_libraries(
        ${testName}
        ${LIB_CMOCKA}
        -fprofile-arcs -ftest-coverage
        ${GLOBAL_LIBS}
    )

    if(testFlags STREQUAL "")
    else()
        target_link_libraries(
            ${testName}
            ${testFlags}
        )
    endif()

    add_test(${testName} ${testName})

endforeach()

target_link_libraries(${PROSE_PROJECT_NAME} ${GLOBAL_LIBS})
setup_target_for_coverage(coverage ctest coverage)