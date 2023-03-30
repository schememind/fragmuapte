#include "SDLInputHandler.h"

namespace fragmuapte {

SDLInputHandler::SDLInputHandler()
{
    if (int result = SDL_Init(SDL_INIT_EVENTS); result < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, SDL_GetError());
        // TODO throw exception
    }
}

void SDLInputHandler::registerUserInput()
{
    mUserInput.reset();
    while (SDL_PollEvent(&mEvent))
    {
        if (mEvent.type == SDL_QUIT)
        {
            mUserInput.isExit = true;
        }
        if (mEvent.type == SDL_KEYDOWN && mEvent.key.repeat == 0)
        {
            if (mEvent.key.keysym.scancode == SDL_SCANCODE_UP)
            {
                mUserInput.isUpPressed = true;
            }
            if (mEvent.key.keysym.scancode == SDL_SCANCODE_DOWN)
            {
                mUserInput.isDownPressed = true;
            }
            if (mEvent.key.keysym.scancode == SDL_SCANCODE_LEFT)
            {
                mUserInput.isLeftPressed = true;
            }
            if (mEvent.key.keysym.scancode == SDL_SCANCODE_RIGHT)
            {
                mUserInput.isRightPressed = true;
            }
        }
        if (mEvent.type == SDL_KEYUP && mEvent.key.repeat == 0)
        {
            if (mEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                mUserInput.isExit = true;
            }
            if (mEvent.key.keysym.scancode == SDL_SCANCODE_UP)
            {
                mUserInput.isUpReleased = true;
            }
            if (mEvent.key.keysym.scancode == SDL_SCANCODE_DOWN)
            {
                mUserInput.isDownReleased = true;
            }
            if (mEvent.key.keysym.scancode == SDL_SCANCODE_LEFT)
            {
                mUserInput.isLeftReleased = true;
            }
            if (mEvent.key.keysym.scancode == SDL_SCANCODE_RIGHT)
            {
                mUserInput.isRightReleased = true;
            }
        }
    }
}

}  // namespace fragmuapte