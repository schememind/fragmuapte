#ifndef FRAGMUAPTE_SDLTIMER_H
#define FRAGMUAPTE_SDLTIMER_H


#include "SDL.h"
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
