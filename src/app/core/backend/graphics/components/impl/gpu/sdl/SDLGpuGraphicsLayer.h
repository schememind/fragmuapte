#ifndef FRAGMUAPTE_SDLGPUGRAPHICSLAYER_H
#define FRAGMUAPTE_SDLGPUGRAPHICSLAYER_H


#include <array>

#if defined(_WIN32)
    #include "SDL.h"
#else
    #include "SDL2/SDL.h"
#endif

#include "../../../GraphicsLayer.h"
#include "../../../../../util/FileIdTracker.h"

namespace fragmuapte {

class SDLGpuGraphicsLayer final : public GraphicsLayer
{
public:
    explicit SDLGpuGraphicsLayer();

    void clear() override;
    void render() override;
    GraphicsLayer &setTitle(std::string const &title) override;
    GraphicsLayer &setSize(int width, int height) override;
    GraphicsLayer &setResolution(int width, int height) override;
    GraphicsLayer &setScreenMode(ScreenMode screenMode) override;
    GraphicsLayer &setRenderScaleQuality(RenderScaleQuality renderScaleQuality) override;
    GraphicsLayer &setCursorState(CursorState cursorState) override;

    int addTextureFromFile(std::string const &path) override;
    void removeTextureById(int textureId) override;
    void submitTextureToRenderer(int textureId,
                                 int srcX, int srcY, int srcW, int srcH,
                                 int dstX, int dstY, int dstW, int dstH,
                                 int pivotX, int pivotY, float angle,
                                 bool isFlipHorizontal, bool isFlipVertical) override;
    
    ~SDLGpuGraphicsLayer() override;

private:
    SDL_Window *mWindow{};
    SDL_Renderer *mRenderer{};

    static std::size_t const MAX_TEXTURES = 5;
    std::array<SDL_Texture*, MAX_TEXTURES> mTextures{};

    FileIdTracker mFileIdTracker{};
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_SDLGPUGRAPHICSLAYER_H
