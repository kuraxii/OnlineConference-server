file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h" "test/*.cpp" "test/*.h")
project(Test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(./protobufTest)

add_executable(test test.cpp protobufTest/test.pb.cc)
target_link_libraries(test ${GTEST_LIBRARIES} pthread)
target_link_libraries(test protobuf conference curl)