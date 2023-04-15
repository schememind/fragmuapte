#include <algorithm>

#if defined(_WIN32)
    #include "SDL_image.h"
#else
    #include "SDL2/SDL_image.h"
#endif

#include "SDLGpuGraphicsLayer.h"

namespace fragmuapte {

SDLGpuGraphicsLayer::SDLGpuGraphicsLayer()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        SDL_Quit();
        // TODO throw exception
    }

    // Create window with default properties
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
    mRenderer = SDL_CreateRenderer(
            mWindow,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (!mRenderer)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
        // TODO throw exception
    }

    // Set virtual size of the renderer and window
    if (int scale = SDL_RenderSetLogicalSize(mRenderer, 800, 600); scale < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
        // TODO throw exception
    }
}

void SDLGpuGraphicsLayer::clear()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mRenderer);
}

void SDLGpuGraphicsLayer::render()
{
    SDL_RenderPresent(mRenderer);
}

GraphicsLayer& SDLGpuGraphicsLayer::setTitle(std::string const &title)
{
    SDL_SetWindowTitle(mWindow, title.c_str());
    return *this;
}

GraphicsLayer& SDLGpuGraphicsLayer::setSize(int width, int height)
{
    SDL_SetWindowSize(mWindow, width, height);
    return *this;
}

GraphicsLayer& SDLGpuGraphicsLayer::setResolution(int width, int height)
{
    if (int result = SDL_RenderSetLogicalSize(mRenderer, width, height); result < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        // TODO throw exception
    }
    return *this;
}

GraphicsLayer& SDLGpuGraphicsLayer::setScreenMode(ScreenMode screenMode)
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

GraphicsLayer& SDLGpuGraphicsLayer::setRenderScaleQuality(RenderScaleQuality renderScaleQuality)
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

GraphicsLayer& SDLGpuGraphicsLayer::setCursorState(CursorState cursorState)
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

int SDLGpuGraphicsLayer::addTextureFromFile(std::string const &path)
{
    if (auto iterator = std::ranges::find(mTextures, nullptr); iterator != mTextures.end())
    {
        auto id = std::ranges::distance(mTextures.begin(), iterator);
        auto texture = IMG_LoadTexture(mRenderer, path.c_str());
        if (!texture)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
            // TODO generate default texture
        }
        mTextures.at(id) = texture;
        return static_cast<int>(id);
    }
    // TODO throw exception
    return 0;
}

void SDLGpuGraphicsLayer::removeTextureById(int textureId)
{
    if (textureId >= 0 && textureId < mTextures.size())
    {
        SDL_DestroyTexture(mTextures.at(textureId));
        // TODO log SDL error if something goes wrong with SDL_DestroyTexture
        mTextures.at(textureId) = nullptr;     // FIXME not sure if such approach is correct
    }
}

void SDLGpuGraphicsLayer::submitTextureToRenderer(int textureId,
                                                  int srcX, int srcY, int srcW, int srcH,
                                                  int dstX, int dstY, int dstW, int dstH,
                                                  int pivotX, int pivotY, float angle,
                                                  bool isFlipHorizontal, bool isFlipVertical)
{
    if (textureId < 0 || textureId > mTextures.size() || mTextures.at(textureId) == nullptr) return;
    SDL_Rect sourceRect { .x = srcX, .y = srcY, .w = srcW, .h = srcH };
    SDL_Rect destinationRect { .x = dstX, .y = dstY, .w = dstW, .h = dstH };
    SDL_Point pivotPoint { .x = pivotX, .y = pivotY };
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (isFlipHorizontal) flip = static_cast<SDL_RendererFlip>(flip | SDL_FLIP_HORIZONTAL);
    if (isFlipVertical) flip = static_cast<SDL_RendererFlip>(flip | SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(mRenderer, mTextures.at(textureId),
                     &sourceRect, &destinationRect, angle, &pivotPoint, flip);
}

SDLGpuGraphicsLayer::~SDLGpuGraphicsLayer()
{
    std::ranges::for_each(mTextures, [](SDL_Texture *texture) {
        SDL_DestroyTexture(texture);
        // TODO log SDL error if something goes wrong with SDL_DestroyTexture
        texture = nullptr;      // FIXME not sure if such approach is correct
    });
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);
}

}  // namespace fragmuapte