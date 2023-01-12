#ifndef FRAGMUAPTE_SDLGPUGRAPHICSLAYER_H
#define FRAGMUAPTE_SDLGPUGRAPHICSLAYER_H


#include "../../../GraphicsLayer.h"
#include "SDLGpuRenderer.h"
#include "SDLGpuWindow.h"
#include "SDLGpuTextureRepository.h"

namespace zkl {

class SDLGpuGraphicsLayer final : public zkl::GraphicsLayer
{
public:
    zkl::Window &getWindow() override { return mWindow; }
    zkl::TextureRepository &getTextures() override { return mTextureRepository; }
private:
    zkl::SDLGpuRenderer mRenderer;
    zkl::SDLGpuWindow mWindow{mRenderer};
    zkl::SDLGpuTextureRepository mTextureRepository{mRenderer};
};

} // zkl


#endif //FRAGMUAPTE_SDLGPUGRAPHICSLAYER_H
