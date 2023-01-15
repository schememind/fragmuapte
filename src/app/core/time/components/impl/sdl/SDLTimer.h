#ifndef FRAGMUAPTE_SDLTIMER_H
#define FRAGMUAPTE_SDLTIMER_H


#if defined(_WIN32)
    #include "SDL.h"
#else
    #include "SDL2/SDL.h"
#endif

#include "../../Timer.h"

namespace zkl {

class SDLTimer final : public zkl::Timer
{
public:
    SDLTimer();
    void refresh() override;
private:
    Uint32 mPrevTime = 0;
    Uint32 mCurrTime = 0;
};

} // zkl


#endif //FRAGMUAPTE_SDLTIMER_H
