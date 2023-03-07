#ifndef FRAGMUAPTE_SDLGPUTEXTUREREPOSITORY_H
#define FRAGMUAPTE_SDLGPUTEXTUREREPOSITORY_H


#include <array>

#if defined(_WIN32)
    #include "SDL.h"
#else
    #include "SDL2/SDL.h"
#endif

#include "SDLGpuRenderer.h"
#include "../../../TextureRepository.h"

namespace zkl {

class SDLGpuTextureRepository final : public zkl::TextureRepository
{
public:
    explicit SDLGpuTextureRepository(zkl::SDLGpuRenderer const &renderer);
    ~SDLGpuTextureRepository() override;

    int addTextureFromFile(std::string const &path) override;
    void removeTextureById(int textureId) override;
    void submitTextureToRenderer(int textureId,
                                 int srcX, int srcY, int srcW, int srcH,
                                 int dstX, int dstY, int dstW, int dstH,
                                 int pivotX, int pivotY, float angle,
                                 bool isFlipHorizontal, bool isFlipVertical) override;
private:
    static std::size_t const MAX_TEXTURES = 5;

    zkl::SDLGpuRenderer const &mRenderer;
    std::array<SDL_Texture*, MAX_TEXTURES> mTextures{};
};

} // zkl


#endif //FRAGMUAPTE_SDLGPUTEXTUREREPOSITORY_H
