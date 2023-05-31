#ifndef FRAGMUAPTE_MEDIABACKEND_H
#define FRAGMUAPTE_MEDIABACKEND_H


#include <memory>
#include "backend/graphics/components/GraphicsLayer.h"
#include "backend/time/components/Timer.h"
#include "backend/input/components/InputHandler.h"
#include "logic/ResourceLoader.h"

namespace fragmuapte {

class MediaBackend final : public logic::ResourceLoader
{
public:
    MediaBackend(std::unique_ptr<GraphicsLayer> pGraphicsLayer,
                 std::unique_ptr<InputHandler> pInputHandler,
                 std::unique_ptr<Timer> pTimer);
    void validate() const;
    [[nodiscard]] int loadImage(std::string const &path) const override;
    [[nodiscard]] int loadSound(std::string const &path) const override;
    friend class MainLoop;
private:
    std::unique_ptr<GraphicsLayer> graphicsLayer;
    std::unique_ptr<InputHandler> inputHandler;
    std::unique_ptr<Timer> timer;
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_MEDIABACKEND_H
