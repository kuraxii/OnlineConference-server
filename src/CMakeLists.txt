include_directories(./test/ ../thrid_party/include/ )
link_directories(./thrid_party/lib/)


file(GLOB_RECURSE SOURCES "./*.cpp" "./*.cc")
add_library(conference ${SOURCES})