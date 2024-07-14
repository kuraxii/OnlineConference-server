file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h" "test/*.cpp" "test/*.h")
project(Test)

include_directories(./protobufTest)

add_executable(test test.cpp protobufTest/test.pb.cc)
target_link_libraries(test protobuf conference)