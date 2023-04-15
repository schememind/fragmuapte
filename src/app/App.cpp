#include "core/backend/graphics/GraphicsLayerFactory.h"
#include "core/backend/input/InputHandlerFactory.h"
#include "core/backend/time/TimerFactory.h"
#include "App.h"

namespace fragmuapte {

App& App::loadSettings()
{
    mSettings.loadFromUserConfig();
    return *this;
}

void App::start()
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

    mMainLoop
        .setGraphicsLayer(std::move(tmpGraphicsLayer))
        .setInputHandler(std::move(tmpInputHandler))
        .setTimer(std::move(tmpTimer))
        .start();

    while (mMainLoop.isRunning())
    {
        mMainLoop.nextStep();
    }
}

}  // namespace fragmuapte