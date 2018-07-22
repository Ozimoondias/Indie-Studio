cmake_minimum_required(VERSION 3.5.1)
project(indie_studio)

if (WIN32)
   set (SRCS src/src/Map.cpp src/src/Map2.cpp src/src/main2.cpp src/src/Player.cpp src/src/Keyboard.cpp src/src/Camera.cpp src/src/Core.cpp src/src/Light.cpp src/src/Play.cpp src/src/Enemy.cpp src/src/Attack.cpp src/src/Deco.cpp)

   set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY})


      INCLUDE_DIRECTORIES(
      Install/irrlicht-1.8.4/include
      src/include/test.hpp)

      set (HEADERS src/include irrKlang-1.5.0/include
				irrKlang-1.5.0/bin/win32-visualStudio
				irrKlang-1.5.0/lib/Win32-visualStudio)
      include_directories(${HEADERS})

      LINK_DIRECTORIES(Install/irrlicht-1.8.4/lib/Win32-visualstudio
        irrKlang-1.5.0/bin/win32-visualStudio
	irrKlang-1.5.0/lib/Win32-visualStudio)

	add_executable(indie_studio ${SRCS})

      target_link_libraries(
      		indie_studio
		IrrKlang)
		
endif()

if (UNIX)
   set (SRCS src/src/Map.cpp src/src/Map2.cpp src/src/main2.cpp src/src/Player.cpp src/src/Keyboard.cpp src/src/Camera.cpp src/src/Core.cpp src/src/Light.cpp src/src/Play.cpp src/src/Enemy.cpp src/src/Attack.cpp src/src/Deco.cpp)
   set (LIBFLAGS )
   set (CXXFLAGS )

   set (HEADERS src/include irrKlang-1.5.0/include)

   link_directories(${CMAKE_SOURCE_DIR}/irrKlang-1.5.0/bin/linux-gcc)
   
   include_directories(${HEADERS})
   
   add_executable(indie_studio ${SRCS})

    add_custom_target(install_all
    COMMAND ./clean_cmake.sh)

   target_link_libraries(
		indie_studio
		IrrKlang
        	Irrlicht
        	GL
        	Xxf86vm
        	Xext
        	X11
		pthread
        	Xcursor
	)
endif()
