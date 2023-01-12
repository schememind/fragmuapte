# The following system (not user!) environment variables are required when building on Windows:
# - SDL2_INCLUDE_PATH - path to a folder containing all SDL2 header files
# - SDL2_LIB_PATH - path to a folder containing all SDL2 library files

cmake_minimum_required(VERSION 3.21)
project(fragmuapte)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    # Windows: include headers
    if (DEFINED ENV{SDL2_INCLUDE_PATH})
        include_directories("$ENV{SDL2_INCLUDE_PATH}")
    else ()
        message(FATAL_ERROR "Missing environment variable: SDL2_INCLUDE_PATH! Please create this environment variable and set its value as path to a folder containing all SDL2 header files.")
    endif ()

    # Windows: find libraries
    if (DEFINED ENV{SDL2_LIB_PATH})
        find_library(SDL2_MAIN_LIB NAMES SDL2main.lib PATHS ENV SDL2_LIB_PATH)
        if (NOT SDL2_MAIN_LIB)
            message(FATAL_ERROR "Library SDL2main not found!")
        endif ()

        find_library(SDL2_LIB NAMES SDL2.lib PATHS ENV SDL2_LIB_PATH)
        if (NOT SDL2_LIB)
            message(FATAL_ERROR "Library SDL2 not found!")
        endif ()

        find_library(SDL2_IMAGE_LIB NAMES SDL2_image.lib PATHS ENV SDL2_LIB_PATH)
        if (NOT SDL2_IMAGE_LIB)
            message(FATAL_ERROR "Library SDL2_image not found!")
        endif ()
    else ()
        message(FATAL_ERROR "Missing environment variable: SDL2_LIB_PATH! Please create this environment variable and set its value as path to a folder containing all SDL2 library files.")
    endif ()
else ()
    # TODO other OS
endif ()

add_executable(fragmuapte
               src/main.cpp
               src/app/core/MainLoop.cpp
               src/app/core/MainLoop.h
               src/app/core/time/components/Timer.h
               src/app/core/time/components/impl/sdl/SDLTimer.cpp
               src/app/core/time/components/impl/sdl/SDLTimer.h
               src/app/core/input/components/InputHandler.h
               src/app/core/input/components/impl/sdl/SDLInputHandler.cpp
               src/app/core/input/components/impl/sdl/SDLInputHandler.h
               src/app/core/graphics/components/GraphicsLayer.h
               src/app/core/graphics/components/Window.h
               src/app/core/graphics/components/TextureRepository.h
               src/app/core/graphics/components/impl/gpu/sdl/SDLGpuWindow.cpp
               src/app/core/graphics/components/impl/gpu/sdl/SDLGpuWindow.h
               src/app/core/graphics/components/impl/gpu/sdl/SDLGpuTextureRepository.cpp
               src/app/core/graphics/components/impl/gpu/sdl/SDLGpuTextureRepository.h
               src/app/core/graphics/components/impl/gpu/sdl/SDLGpuRenderer.h
               src/app/core/graphics/components/impl/gpu/sdl/SDLGpuGraphicsLayer.h
               src/app/core/time/TimerFactory.cpp
               src/app/core/time/TimerFactory.h
               src/app/core/input/InputHandlerFactory.cpp
               src/app/core/input/InputHandlerFactory.h
               src/app/core/graphics/GraphicsLayerFactory.cpp
               src/app/core/graphics/GraphicsLayerFactory.h
               src/app/App.cpp src/app/App.h
               src/app/settings/Settings.cpp
               src/app/settings/Settings.h
               )

# Incrementally copy resources directory to target directory
add_custom_target(copy_resources_dir ALL
                  COMMAND ${CMAKE_COMMAND} -E copy_directory
                  ${PROJECT_SOURCE_DIR}/resources
                  ${PROJECT_BINARY_DIR}/resources
                  COMMENT "Copying resource folder to target folder")

add_dependencies(fragmuapte copy_resources_dir)

target_link_libraries(fragmuapte ${SDL2_MAIN_LIB} ${SDL2_LIB} ${SDL2_IMAGE_LIB})

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    target_compile_options(fragmuapte PRIVATE -Wall -Wextra -Wpedantic)
endif()
