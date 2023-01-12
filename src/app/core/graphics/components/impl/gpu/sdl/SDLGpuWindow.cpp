#include "SDLGpuWindow.h"

zkl::SDLGpuWindow::SDLGpuWindow(zkl::SDLGpuRenderer &renderer) : mRenderer(renderer) {}

void zkl::SDLGpuWindow::clear()
{
    SDL_SetRenderDrawColor(mRenderer.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mRenderer.renderer);
}

void zkl::SDLGpuWindow::render()
{
    SDL_RenderPresent(mRenderer.renderer);
}

zkl::Window &zkl::SDLGpuWindow::init()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, SDL_GetError());
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
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, SDL_GetError());
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
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, SDL_GetError());
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
        // TODO throw exception
    }

    // Set virtual size of the renderer and getWindow
    if (int scale = SDL_RenderSetLogicalSize(mRenderer.renderer, 800, 600); scale < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, SDL_GetError());
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
        // TODO throw exception
    }

    return *this;
}

zkl::Window &zkl::SDLGpuWindow::setTitle(std::string const &title)
{
    SDL_SetWindowTitle(mWindow, title.c_str());
    return *this;
}

zkl::Window &zkl::SDLGpuWindow::setSize(int width, int height)
{
    SDL_SetWindowSize(mWindow, width, height);
    return *this;
}

zkl::Window &zkl::SDLGpuWindow::setResolution(int width, int height)
{
    if (int result = SDL_RenderSetLogicalSize(mRenderer.renderer, width, height); result < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, SDL_GetError());
        // TODO throw exception
    }
    return *this;
}

zkl::Window &zkl::SDLGpuWindow::setScreenMode(zkl::ScreenMode screenMode)
{
    int tmpScreenMode = 0;
    if (screenMode == zkl::ScreenMode::fullScreen)
    {
        tmpScreenMode = SDL_WINDOW_FULLSCREEN;
    }
    else if (screenMode == zkl::ScreenMode::windowed)
    {
        tmpScreenMode = 0;
    }
    if (int result = SDL_SetWindowFullscreen(mWindow, tmpScreenMode); result < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, SDL_GetError());
        // TODO throw exception
    }
    return *this;
}

zkl::Window &zkl::SDLGpuWindow::setRenderScaleQuality(zkl::RenderScaleQuality renderScaleQuality)
{
    std::string tmpRenderScaleQuality = "0";
    if (renderScaleQuality == zkl::RenderScaleQuality::pixelated)
    {
        tmpRenderScaleQuality = "0";
    }
    else if (renderScaleQuality == zkl::RenderScaleQuality::linear)
    {
        tmpRenderScaleQuality = "1";
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, tmpRenderScaleQuality.c_str());
    return *this;
}

zkl::Window &zkl::SDLGpuWindow::setCursorState(zkl::CursorState cursorState)
{
    int tmpCursorState = 0;
    if (cursorState == zkl::CursorState::visible)
    {
        tmpCursorState = 1;
    }
    else if (cursorState == zkl::CursorState::invisible)
    {
        tmpCursorState = 0;
    }
    if (int result = SDL_ShowCursor(tmpCursorState); result < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, SDL_GetError());
        // TODO throw exception
    }
    return *this;
}

zkl::SDLGpuWindow::~SDLGpuWindow()
{
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer.renderer);
}
