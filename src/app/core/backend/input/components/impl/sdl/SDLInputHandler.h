#ifndef FRAGMUAPTE_SDLINPUTHANDLER_H
#define FRAGMUAPTE_SDLINPUTHANDLER_H


#if defined(_WIN32)
    #include "SDL.h"
#else
    #include "SDL2/SDL.h"
#endif

#include "../../InputHandler.h"

namespace fragmuapte {

class SDLInputHandler final : public InputHandler
{
public:
    SDLInputHandler();
    void registerUserInput() override;
private:
    SDL_Event mEvent = {};
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_SDLINPUTHANDLER_H
