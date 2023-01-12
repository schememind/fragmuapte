#include "TimerFactory.h"
#include "components/impl/sdl/SDLTimer.h"

std::unique_ptr<zkl::Timer> zkl::factory::createTimer(std::string_view timerType)
{
    if (timerType == "sdl")
    {
        return std::make_unique<zkl::SDLTimer>();
    }
    // FIXME throw exception or return some default type
    return nullptr;
}