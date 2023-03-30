#ifndef FRAGMUAPTE_SDLGPUGRAPHICSLAYER_H
#define FRAGMUAPTE_SDLGPUGRAPHICSLAYER_H


#include "../../../GraphicsLayer.h"
#include "SDLGpuRenderer.h"
#include "SDLGpuWindow.h"
#include "SDLGpuTextureRepository.h"

namespace fragmuapte {

class SDLGpuGraphicsLayer final : public GraphicsLayer
{
public:
    Window &getWindow() override { return mWindow; }
    TextureRepository &getTextures() override { return mTextureRepository; }
private:
    SDLGpuRenderer mRenderer;
    SDLGpuWindow mWindow{mRenderer};
    SDLGpuTextureRepository mTextureRepository{mRenderer};
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_SDLGPUGRAPHICSLAYER_H
