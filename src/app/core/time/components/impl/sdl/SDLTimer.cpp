#include "SDLTimer.h"

namespace fragmuapte {

SDLTimer::SDLTimer()
{
    if (int result = SDL_Init(SDL_INIT_TIMER); result < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, SDL_GetError());
        // TODO throw exception
    }
}

void SDLTimer::refresh()
{
    mPrevTime = mCurrTime;
    // TODO investigate SDL_GetPerformanceCounter and SDL_GetPerformanceFrequency
    mCurrTime = SDL_GetTicks();
    mDelta = (mCurrTime - mPrevTime) / 1000.0;
}

}  // namespace fragmuapte