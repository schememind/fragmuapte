#include "InputHandlerFactory.h"
#include "components/impl/sdl/SDLInputHandler.h"

namespace fragmuapte::factory {

std::unique_ptr<InputHandler> createInputHandler(std::string_view inputHandlerType)
{
    if (inputHandlerType == "sdl")
    {
        return std::make_unique<SDLInputHandler>();
    }
    // FIXME throw exception or return some default type
    return nullptr;
}

}  // namespace fragmuapte::factory