# In order to build on Windows, the following CMake variables must be set by the user when running cmake command:
# - SDL2_INCLUDE_PATH - path to a folder containing SDL2 core header files (*.h)
# - SDL2_LIB_PATH - path to a folder containing SDL2 core library files (*.lib)
# - SDL2_IMAGE_INCLUDE_PATH - path to a folder containing SDL2_image header files (*.h)
# - SDL2_IMAGE_LIB_PATH - path to a folder containing SDL2_image library files (*.lib)
# (Example: cmake -DSDL2_INCLUDE_PATH=C:\libs\SDL2_VC\include -DSDL2_LIB_PATH==C:\libs\SDL2_VC\lib\x64 ..)

# In order to run on Windows, all SDL-related *.dll files must be copied to the location of the executable.

cmake_minimum_required(VERSION 3.21)
project(fragmuapte)

set(CMAKE_CXX_STANDARD 20)

add_executable(fragmuapte
               src/main.cpp
               src/app/core/MainLoop.cpp
               src/app/core/MainLoop.h
               src/app/core/backend/time/components/Timer.h
               src/app/core/backend/time/components/impl/sdl/SDLTimer.cpp
               src/app/core/backend/time/components/impl/sdl/SDLTimer.h
               src/app/core/backend/input/components/InputHandler.h
               src/app/core/backend/input/components/impl/sdl/SDLInputHandler.cpp
               src/app/core/backend/input/components/impl/sdl/SDLInputHandler.h
               src/app/core/backend/graphics/components/GraphicsLayer.h
               src/app/core/backend/graphics/components/impl/gpu/sdl/SDLGpuGraphicsLayer.h
               src/app/core/backend/graphics/components/impl/gpu/sdl/SDLGpuGraphicsLayer.cpp
               src/app/core/backend/time/TimerFactory.cpp
               src/app/core/backend/time/TimerFactory.h
               src/app/core/backend/input/InputHandlerFactory.cpp
               src/app/core/backend/input/InputHandlerFactory.h
               src/app/core/backend/graphics/GraphicsLayerFactory.cpp
               src/app/core/backend/graphics/GraphicsLayerFactory.h
               src/app/App.cpp src/app/App.h
               src/app/settings/Settings.cpp
               src/app/settings/Settings.h
               )


if (WIN32)
    set(SDL2_INCLUDE_PATH "" CACHE PATH "Directory containing SDL2 and SDL2main headers")
    set(SDL2_LIB_PATH "" CACHE PATH "Directory containing SDL2 and SDL2main library files")
    set(SDL2_IMAGE_INCLUDE_PATH "" CACHE PATH "Directory containing SDL_image headers")
    set(SDL2_IMAGE_LIB_PATH "" CACHE PATH "Directory containing SDL2_image library file")

    if (NOT "${SDL2_INCLUDE_PATH}" STREQUAL "")
        include_directories(${SDL2_INCLUDE_PATH})
    else()
        message(FATAL_ERROR "Value of CMake variable SDL2_INCLUDE_PATH not specified!")
    endif()

    if (NOT "${SDL2_LIB_PATH}" STREQUAL "")
        find_library(SDL2_MAIN_LIB NAMES SDL2main.lib PATHS ${SDL2_LIB_PATH})
        if (NOT SDL2_MAIN_LIB)
            message(FATAL_ERROR "Library SDL2main not found!")
        endif ()

        find_library(SDL2_LIB NAMES SDL2.lib PATHS ${SDL2_LIB_PATH})
        if (NOT SDL2_LIB)
            message(FATAL_ERROR "Library SDL2 not found!")
        endif ()
    else()
        message(FATAL_ERROR "Value of CMake variable SDL2_LIB_PATH not specified!")
    endif()

    if (NOT "${SDL2_IMAGE_INCLUDE_PATH}" STREQUAL "")
        include_directories(${SDL2_IMAGE_INCLUDE_PATH})
    else()
        message(FATAL_ERROR "Value of CMake variable SDL2_IMAGE_INCLUDE_PATH not specified!")
    endif()

    if (NOT "${SDL2_IMAGE_LIB_PATH}" STREQUAL "")
        find_library(SDL2_IMAGE_LIB NAMES SDL2_image.lib PATHS ${SDL2_LIB_PATH})
        if (NOT SDL2_IMAGE_LIB)
            message(FATAL_ERROR "Library SDL2_image not found!")
        endif ()
    else()
        message(FATAL_ERROR "Value of CMake variable SDL2_IMAGE_LIB_PATH not specified!")
    endif()

    target_link_libraries(fragmuapte ${SDL2_MAIN_LIB} ${SDL2_LIB} ${SDL2_IMAGE_LIB})
else ()
    # Other OS
    target_link_libraries(fragmuapte -lSDL2 -lSDL2_image)
endif ()

# Incrementally copy resources directory to target directory
add_custom_target(copy_resources_dir ALL
                  COMMAND ${CMAKE_COMMAND} -E copy_directory
                  ${PROJECT_SOURCE_DIR}/resources
                  ${PROJECT_BINARY_DIR}/resources
                  COMMENT "Copying resource folder to target folder")

add_dependencies(fragmuapte copy_resources_dir)

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    target_compile_options(fragmuapte PRIVATE -Wall -Wextra -Wpedantic)
endif()
