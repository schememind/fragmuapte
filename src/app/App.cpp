#include "core/MainLoop.h"
#include "core/graphics/GraphicsLayerFactory.h"
#include "core/input/InputHandlerFactory.h"
#include "core/time/TimerFactory.h"
#include "App.h"

zkl::App &zkl::App::loadSettings()
{
    mSettings.loadFromUserConfig();
    return *this;
}

void zkl::App::start() const
{
    auto tmpGraphicsLayer = zkl::factory::createGraphicsLayer(mSettings.graphicsLayerType);
    auto tmpInputHandler = zkl::factory::createInputHandler(mSettings.inputHandlerType);
    auto tmpTimer = zkl::factory::createTimer(mSettings.timerType);

    tmpGraphicsLayer->getWindow()
                     .init()
                     .setTitle("Test Window")
                     .setSize(mSettings.windowWidth, mSettings.windowHeight)
                     .setResolution(mSettings.resolutionWidth, mSettings.resolutionHeight)
                     .setRenderScaleQuality(zkl::RenderScaleQuality::pixelated)
                     .setScreenMode(mSettings.isFullScreen ? zkl::ScreenMode::fullScreen : zkl::ScreenMode::windowed)
                     .setCursorState(zkl::CursorState::visible);

    zkl::MainLoop mainLoop{
            std::move(tmpGraphicsLayer),
            std::move(tmpInputHandler),
            std::move(tmpTimer)
    };

    bool isRunning{true};
    while (isRunning)
    {
        isRunning = mainLoop.step();
    }
}
