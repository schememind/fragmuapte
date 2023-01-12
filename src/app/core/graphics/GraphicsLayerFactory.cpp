#include "GraphicsLayerFactory.h"
#include "components/impl/gpu/sdl/SDLGpuGraphicsLayer.h"

std::unique_ptr<zkl::GraphicsLayer> zkl::factory::createGraphicsLayer(std::string_view graphicsLayerType)
{
    if (graphicsLayerType == "sdl_gpu")
    {
        return std::make_unique<zkl::SDLGpuGraphicsLayer>();
    }
    // FIXME throw exception or return some default type
    return nullptr;
}