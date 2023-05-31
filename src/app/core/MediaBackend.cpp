#include "MediaBackend.h"

namespace fragmuapte {

MediaBackend::MediaBackend(std::unique_ptr<GraphicsLayer> pGraphicsLayer,
                           std::unique_ptr<InputHandler> pInputHandler,
                           std::unique_ptr<Timer> pTimer)
                 :
        graphicsLayer{std::move(pGraphicsLayer)},
        inputHandler(std::move(pInputHandler)),
        timer(std::move(pTimer))
{}

void MediaBackend::validate() const
{
    if (graphicsLayer == nullptr)
    {
        // TODO add to exception message
    }
    if (inputHandler == nullptr)
    {
        // TODO add to exception message
    }
    if (timer == nullptr)
    {
        // TODO add to exception message
    }
    // TODO throw exception if at least one mandatory component is missing
}

int MediaBackend::loadImage(const std::string &path) const
{
    return graphicsLayer->addTextureFromFile(path);
}

int MediaBackend::loadSound(const std::string &path) const
{
    // TODO load sound
    return 0;
}

}  // namespace fragmuapte