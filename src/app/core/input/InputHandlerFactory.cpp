#include "InputHandlerFactory.h"
#include "components/impl/sdl/SDLInputHandler.h"

std::unique_ptr<zkl::InputHandler> zkl::factory::createInputHandler(std::string_view inputHandlerType)
{
    if (inputHandlerType == "sdl")
    {
        return std::make_unique<zkl::SDLInputHandler>();
    }
    // FIXME throw exception or return some default type
    return nullptr;
}