#include "MainLoop.h"

namespace fragmuapte {

MainLoop& MainLoop::setGraphicsLayer(std::unique_ptr<GraphicsLayer> graphicsLayer)
{
    mGraphicsLayer = std::move(graphicsLayer);
    return *this;
}

MainLoop& MainLoop::setInputHandler(std::unique_ptr<InputHandler> inputHandler)
{
    mInputHandler = std::move(inputHandler);
    return *this;
}

MainLoop& MainLoop::setTimer(std::unique_ptr<Timer> timer)
{
    mTimer = std::move(timer);
    return *this;
}

bool MainLoop::isRunning() const
{
    return mIsRunning;
}

void MainLoop::start()
{
    if (mGraphicsLayer == nullptr)
    {
        // TODO add to exception message
    }
    if (mInputHandler == nullptr)
    {
        // TODO add to exception message
    }
    if (mTimer == nullptr)
    {
        // TODO add to exception message
    }
    // TODO throw exception if at least one mandatory component is missing
    mIsRunning = true;
}

void MainLoop::nextStep()
{
    mTimer->refresh();
    mInputHandler->registerUserInput();
    mIsRunning = !mInputHandler->getUserInput().isExit;    // FIXME temporary solution
    mGraphicsLayer->clear();
    // TODO submit getTextures for rendering mGraphicsLayer->submitTextureToRenderer(...)
    mGraphicsLayer->render();
}

}  // namespace fragmuapte