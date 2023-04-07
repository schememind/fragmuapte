#ifndef FRAGMUAPTE_MAINLOOP_H
#define FRAGMUAPTE_MAINLOOP_H


#include <memory>
#include "backend/graphics/components/GraphicsLayer.h"
#include "backend/time/components/Timer.h"
#include "backend/input/components/InputHandler.h"

namespace fragmuapte {

class MainLoop
{
public:
    MainLoop &setGraphicsLayer(std::unique_ptr<GraphicsLayer> graphicsLayer);
    MainLoop &setInputHandler(std::unique_ptr<InputHandler> inputHandler);
    MainLoop &setTimer(std::unique_ptr<Timer> timer);
    [[nodiscard]] bool isRunning() const;
    void start();
    void nextStep();    // FIXME return meaningful signal
private:
    std::unique_ptr<GraphicsLayer> mGraphicsLayer;
    std::unique_ptr<InputHandler> mInputHandler;
    std::unique_ptr<Timer> mTimer;
    bool mIsRunning{false};
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_MAINLOOP_H
