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
    MainLoop(std::unique_ptr<zkl::GraphicsLayer> graphicsLayer,
             std::unique_ptr<zkl::InputHandler> inputHandler,
             std::unique_ptr<zkl::Timer> timer);
    [[nodiscard]] bool step() const;    // FIXME return meaningful signal instead of bool
private:
    std::unique_ptr<zkl::GraphicsLayer> mGraphicsLayer;
    std::unique_ptr<zkl::InputHandler> mInputHandler;
    std::unique_ptr<zkl::Timer> mTimer;
};

} // zkl


#endif //FRAGMUAPTE_MAINLOOP_H
