#include "MainLoop.h"

zkl::MainLoop &zkl::MainLoop::setGraphicsLayer(std::unique_ptr<zkl::GraphicsLayer> graphicsLayer)
{
    mGraphicsLayer = std::move(graphicsLayer);
    return *this;
}

zkl::MainLoop &zkl::MainLoop::setInputHandler(std::unique_ptr<zkl::InputHandler> inputHandler)
{
    mInputHandler = std::move(inputHandler);
    return *this;
}

zkl::MainLoop &zkl::MainLoop::setTimer(std::unique_ptr<zkl::Timer> timer)
{
    mTimer = std::move(timer);
    return *this;
}

bool zkl::MainLoop::isRunning() const
{
    return mIsRunning;
}

void zkl::MainLoop::start()
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

void zkl::MainLoop::nextStep()
{
    mTimer->refresh();
    mInputHandler->registerUserInput();
    mIsRunning = !mInputHandler->getUserInput().isExit;    // FIXME temporary solution
    mGraphicsLayer->getWindow().clear();
    // TODO submit getTextures for rendering mGraphicsLayer->getTextures().submitTextureToRenderer(...)
    mGraphicsLayer->getWindow().render();
}
