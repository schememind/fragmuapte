#ifndef FRAGMUAPTE_SDLTIMER_H
#define FRAGMUAPTE_SDLTIMER_H


#if defined(_WIN32)
    #include "SDL.h"
#else
    #include "SDL2/SDL.h"
#endif

#include "../../Timer.h"

namespace fragmuapte {

class SDLTimer final : public Timer
{
public:
    SDLTimer();
    void refresh() override;
private:
    Uint32 mPrevTime = 0;
    Uint32 mCurrTime = 0;
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_SDLTIMER_H
