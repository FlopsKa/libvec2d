include(FindSDL)
include_directories(${SDL_INCLUDE_DIR})

include_directories (${libvec2d_SOURCE_DIR}/src)

link_directories (${libvec2d_SOURCE_DIR}/src)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
   # Mac OS X specific code
   add_executable (libvec2dDemo MACOSX_BUNDLE main.cpp Field.cpp SDL_main.m Timer.cpp Ball.cpp)
   target_link_libraries(libvec2dDemo ${SDL_LIBRARY} "-framework Cocoa")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # Linux specific code
	add_executable (libvec2dDemo main.cpp Field.cpp Timer.cpp Ball.cpp)
	target_link_libraries(libvec2dDemo ${SDL_LIBRARY} -lSDL -lSDLmain)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    # Linux specific code
	add_executable (libvec2dDemo main.cpp Field.cpp Timer.cpp Ball.cpp)
	target_link_libraries(libvec2dDemo ${SDL_LIBRARY} -lSDL -lSDLmain -lmingw32)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

target_link_libraries (libvec2dDemo vec2d)