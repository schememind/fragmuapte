#ifndef FRAGMUAPTE_SDLINPUTHANDLER_H
#define FRAGMUAPTE_SDLINPUTHANDLER_H


#include "SDL.h"
#include "../../InputHandler.h"

namespace zkl {

class SDLInputHandler final : public zkl::InputHandler
{
public:
    SDLInputHandler();
    void registerUserInput() override;
private:
    SDL_Event mEvent = {};
};

} // zkl


#endif //FRAGMUAPTE_SDLINPUTHANDLER_H
