#include "TimerFactory.h"
#include "components/impl/sdl/SDLTimer.h"

namespace fragmuapte::factory {

std::unique_ptr<Timer> createTimer(std::string_view timerType)
{
    if (timerType == "sdl")
    {
        return std::make_unique<SDLTimer>();
    }
    // FIXME throw exception or return some default type
    return nullptr;
}

}  // namespace fragmuapte::factory