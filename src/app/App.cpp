#include "core/graphics/GraphicsLayerFactory.h"
#include "core/input/InputHandlerFactory.h"
#include "core/time/TimerFactory.h"
#include "App.h"

zkl::App &zkl::App::loadSettings()
{
    mSettings.loadFromUserConfig();
    return *this;
}

void zkl::App::start()
{
    auto tmpGraphicsLayer = zkl::factory::createGraphicsLayer(mSettings.graphicsLayerType);
    auto tmpInputHandler = zkl::factory::createInputHandler(mSettings.inputHandlerType);
    auto tmpTimer = zkl::factory::createTimer(mSettings.timerType);

    tmpGraphicsLayer
        ->getWindow()
            .setTitle("Test Window")
            .setSize(mSettings.windowWidth, mSettings.windowHeight)
            .setResolution(mSettings.resolutionWidth, mSettings.resolutionHeight)
            .setRenderScaleQuality(zkl::RenderScaleQuality::pixelated)
            .setScreenMode(mSettings.isFullScreen ? zkl::ScreenMode::fullScreen : zkl::ScreenMode::windowed)
            .setCursorState(zkl::CursorState::visible);

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
