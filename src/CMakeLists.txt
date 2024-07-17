include_directories(./test/ ../thrid_party/include/ )
link_directories(./thrid_party/lib/)


file(GLOB_RECURSE SOURCES "*.cpp" "http/*.cpp buffer/*.cpp")
add_library(conference ${SOURCES})