#ifndef FRAGMUAPTE_GRAPHICSLAYER_H
#define FRAGMUAPTE_GRAPHICSLAYER_H


#include "Window.h"
#include "TextureRepository.h"

namespace fragmuapte {

struct GraphicsLayer
{
    [[nodiscard]] virtual Window &getWindow() = 0;
    [[nodiscard]] virtual TextureRepository &getTextures() = 0;
    virtual ~GraphicsLayer() = default;
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_GRAPHICSLAYER_H
