#include "core/backend/graphics/GraphicsLayerFactory.h"
#include "core/backend/input/InputHandlerFactory.h"
#include "core/backend/time/TimerFactory.h"
#include "core/MainLoop.h"
#include "App.h"

namespace fragmuapte {

App& App::loadSettings()
{
    mSettings.loadFromUserConfig();
    return *this;
}

void App::start() const
{
    auto tmpGraphicsLayer = factory::createGraphicsLayer(mSettings.graphicsLayerType);
    auto tmpInputHandler = factory::createInputHandler(mSettings.inputHandlerType);
    auto tmpTimer = factory::createTimer(mSettings.timerType);

    tmpGraphicsLayer
        ->setTitle("Test Window")
        .setSize(mSettings.windowWidth, mSettings.windowHeight)
        .setResolution(mSettings.resolutionWidth, mSettings.resolutionHeight)
        .setRenderScaleQuality(RenderScaleQuality::pixelated)
        .setScreenMode(mSettings.isFullScreen ? ScreenMode::fullScreen : ScreenMode::windowed)
        .setCursorState(CursorState::visible);

    MainLoop mainLoop({std::move(tmpGraphicsLayer),
                       std::move(tmpInputHandler),
                       std::move(tmpTimer)});
    mainLoop.start();

    while (mainLoop.isRunning())
    {
        mainLoop.nextStep();
    }
}

}  // namespace fragmuapte