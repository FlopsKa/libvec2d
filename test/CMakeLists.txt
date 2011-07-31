include_directories (${libvec2d_SOURCE_DIR}/src)

link_directories (${libvec2d_SOURCE_DIR}/src)

add_executable (pointTest testpoint2d.cpp) 
add_executable (vectorTest testvector2d.cpp) 

target_link_libraries (pointTest vec2d)
target_link_libraries (vectorTest vec2d)