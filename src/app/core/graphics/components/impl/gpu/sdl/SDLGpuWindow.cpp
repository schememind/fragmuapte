#include "SDLGpuWindow.h"

namespace fragmuapte {

SDLGpuWindow::SDLGpuWindow(SDLGpuRenderer &renderer) : mRenderer(renderer)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        SDL_Quit();
        // TODO throw exception
    }

    // Create getWindow
    mWindow = SDL_CreateWindow(
            "Default caption",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            800, 600,
            0
    );
    if (!mWindow)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        SDL_Quit();
        // TODO throw exception
    }

    // Create renderer
    mRenderer.renderer = SDL_CreateRenderer(
            mWindow,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (!mRenderer.renderer)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
        // TODO throw exception
    }

    // Set virtual size of the renderer and getWindow
    if (int scale = SDL_RenderSetLogicalSize(mRenderer.renderer, 800, 600); scale < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
        // TODO throw exception
    }
}

void SDLGpuWindow::clear()
{
    SDL_SetRenderDrawColor(mRenderer.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mRenderer.renderer);
}

void SDLGpuWindow::render()
{
    SDL_RenderPresent(mRenderer.renderer);
}

Window& SDLGpuWindow::setTitle(std::string const &title)
{
    SDL_SetWindowTitle(mWindow, title.c_str());
    return *this;
}

Window& SDLGpuWindow::setSize(int width, int height)
{
    SDL_SetWindowSize(mWindow, width, height);
    return *this;
}

Window& SDLGpuWindow::setResolution(int width, int height)
{
    if (int result = SDL_RenderSetLogicalSize(mRenderer.renderer, width, height); result < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        // TODO throw exception
    }
    return *this;
}

Window& SDLGpuWindow::setScreenMode(ScreenMode screenMode)
{
    int tmpScreenMode = 0;
    if (screenMode == ScreenMode::fullScreen)
    {
        tmpScreenMode = SDL_WINDOW_FULLSCREEN;
    }
    else if (screenMode == ScreenMode::windowed)
    {
        tmpScreenMode = 0;
    }
    if (int result = SDL_SetWindowFullscreen(mWindow, tmpScreenMode); result < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        // TODO throw exception
    }
    return *this;
}

Window& SDLGpuWindow::setRenderScaleQuality(RenderScaleQuality renderScaleQuality)
{
    std::string tmpRenderScaleQuality = "0";
    if (renderScaleQuality == RenderScaleQuality::pixelated)
    {
        tmpRenderScaleQuality = "0";
    }
    else if (renderScaleQuality == RenderScaleQuality::linear)
    {
        tmpRenderScaleQuality = "1";
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, tmpRenderScaleQuality.c_str());
    return *this;
}

Window& SDLGpuWindow::setCursorState(CursorState cursorState)
{
    int tmpCursorState = 0;
    if (cursorState == CursorState::visible)
    {
        tmpCursorState = 1;
    }
    else if (cursorState == CursorState::invisible)
    {
        tmpCursorState = 0;
    }
    if (int result = SDL_ShowCursor(tmpCursorState); result < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        // TODO throw exception
    }
    return *this;
}

SDLGpuWindow::~SDLGpuWindow()
{
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer.renderer);
}

}  // namespace fragmuapte