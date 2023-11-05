cmake_minimum_required(VERSION 3.15)

project(isasim CXX)


# Turn on automatic invocation of the MOC, UIC & RCC
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

#file(GLOB SRCS_COMMON src/*.cpp)
#file(GLOB HDRS src/*.h)

include_directories(include)

set(IMPL_FILES ${IMPL_FILES}
    src/simulator.cpp
)
set(TEST_FILES ${TEST_FILES}
    test/task1_tests.cpp
    test/task2_tests.cpp
    test/task3_tests.cpp
    test/task4_tests.cpp
)

#add_executable(isasim simulator.cpp simulator.h ${SRCS_COMMON} ${HDRS})
add_executable(isasim src/main.cpp ${IMPL_FILES})
add_subdirectory(src/lib/Catch2)

set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

include(CTest)
include(Catch)
enable_testing()

add_executable(tests ${TEST_FILES} ${IMPL_FILES})

target_link_libraries(tests PRIVATE Catch2 Catch2WithMain)
catch_discover_tests(tests)


