#include "GraphicsLayerFactory.h"
#include "components/impl/gpu/sdl/SDLGpuGraphicsLayer.h"

namespace fragmuapte::factory {

std::unique_ptr<GraphicsLayer> createGraphicsLayer(std::string_view graphicsLayerType)
{
    if (graphicsLayerType == "sdl_gpu")
    {
        return std::make_unique<SDLGpuGraphicsLayer>();
    }
    // FIXME throw exception or return some default type
    return nullptr;
}

}  // namespace fragmuapte::factory