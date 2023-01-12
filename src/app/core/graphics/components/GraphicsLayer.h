#ifndef FRAGMUAPTE_GRAPHICSLAYER_H
#define FRAGMUAPTE_GRAPHICSLAYER_H


#include <memory>
#include "Window.h"
#include "TextureRepository.h"

namespace zkl {

struct GraphicsLayer
{
    [[nodiscard]] virtual zkl::Window &getWindow() = 0;
    [[nodiscard]] virtual zkl::TextureRepository &getTextures() = 0;
    virtual ~GraphicsLayer() = default;
};

} // zkl


#endif //FRAGMUAPTE_GRAPHICSLAYER_H
