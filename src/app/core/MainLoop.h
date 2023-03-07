#ifndef FRAGMUAPTE_MAINLOOP_H
#define FRAGMUAPTE_MAINLOOP_H


#include <memory>
#include "graphics/components/GraphicsLayer.h"
#include "time/components/Timer.h"
#include "input/components/InputHandler.h"

namespace zkl {

class MainLoop
{
public:
    MainLoop &setGraphicsLayer(std::unique_ptr<zkl::GraphicsLayer> graphicsLayer);
    MainLoop &setInputHandler(std::unique_ptr<zkl::InputHandler> inputHandler);
    MainLoop &setTimer(std::unique_ptr<zkl::Timer> timer);
    [[nodiscard]] bool isRunning() const;
    void start();
    void nextStep();    // FIXME return meaningful signal
private:
    std::unique_ptr<zkl::GraphicsLayer> mGraphicsLayer;
    std::unique_ptr<zkl::InputHandler> mInputHandler;
    std::unique_ptr<zkl::Timer> mTimer;
    bool mIsRunning{false};
};

} // zkl


#endif //FRAGMUAPTE_MAINLOOP_H
