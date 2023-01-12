#include "MainLoop.h"

zkl::MainLoop::MainLoop(std::unique_ptr<zkl::GraphicsLayer> graphicsLayer,
                        std::unique_ptr<zkl::InputHandler> inputHandler,
                        std::unique_ptr<zkl::Timer> timer)
                        :
                        mGraphicsLayer(std::move(graphicsLayer)),
                        mInputHandler(std::move(inputHandler)),
                        mTimer(std::move(timer))
{}

bool zkl::MainLoop::step() const
{
    mTimer->refresh();
    mInputHandler->registerUserInput();
    bool isRunning = !mInputHandler->getUserInput().isExit;    // FIXME temporary solution
    mGraphicsLayer->getWindow().clear();
    // TODO submit getTextures for rendering mGraphicsLayer->getTextures().submitToRenderer(...)
    mGraphicsLayer->getWindow().render();
    return isRunning;
}
