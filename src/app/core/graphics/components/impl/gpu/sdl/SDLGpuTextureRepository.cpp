#include <algorithm>

#if defined(_WIN32)
    #include "SDL_image.h"
#else
    #include "SDL2/SDL_image.h"
#endif

#include "SDLGpuTextureRepository.h"

zkl::SDLGpuTextureRepository::SDLGpuTextureRepository(zkl::SDLGpuRenderer const &renderer)
        : mRenderer(renderer)
{}

zkl::SDLGpuTextureRepository::~SDLGpuTextureRepository()
{
    std::ranges::for_each(mTextures, [](SDL_Texture *texture) {
        SDL_DestroyTexture(texture);
        // TODO log SDL error if something goes wrong with SDL_DestroyTexture
        texture = nullptr;      // FIXME not sure if such approach is correct
    });
}

int zkl::SDLGpuTextureRepository::addFromFile(std::string const &path)
{
    if (auto iterator = std::ranges::find(mTextures, nullptr); iterator != mTextures.end())
    {
        auto id = std::ranges::distance(mTextures.begin(), iterator);
        auto texture = IMG_LoadTexture(mRenderer.renderer, path.c_str());
        if (!texture)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, SDL_GetError());
            // TODO generate default texture
        }
        mTextures.at(id) = texture;
        return static_cast<int>(id);
    }
    // TODO throw exception
    return 0;
}

void zkl::SDLGpuTextureRepository::removeById(int textureId)
{
    if (textureId >= 0 && textureId < mTextures.size())
    {
        SDL_DestroyTexture(mTextures.at(textureId));
        // TODO log SDL error if something goes wrong with SDL_DestroyTexture
        mTextures.at(textureId) = nullptr;     // FIXME not sure if such approach is correct
    }
}

void zkl::SDLGpuTextureRepository::submitToRenderer(int textureId,
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
    SDL_RenderCopyEx(mRenderer.renderer, mTextures.at(textureId),
                     &sourceRect, &destinationRect, angle, &pivotPoint, flip);
}
