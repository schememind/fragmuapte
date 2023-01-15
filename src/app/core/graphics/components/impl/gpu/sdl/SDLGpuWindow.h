#ifndef FRAGMUAPTE_SDLGPUWINDOW_H
#define FRAGMUAPTE_SDLGPUWINDOW_H


#if defined(_WIN32)
    #include "SDL.h"
#else
    #include "SDL2/SDL.h"
#endif

#include "SDLGpuRenderer.h"
#include "../../../Window.h"

namespace zkl {

class SDLGpuWindow final : public zkl::Window
{
public:
    explicit SDLGpuWindow(zkl::SDLGpuRenderer &renderer);
    void clear() override;
    void render() override;
    Window &init() override;
    Window &setTitle(std::string const &title) override;
    Window &setSize(int width, int height) override;
    Window &setResolution(int width, int height) override;
    Window &setScreenMode(ScreenMode screenMode) override;
    Window &setRenderScaleQuality(RenderScaleQuality renderScaleQuality) override;
    Window &setCursorState(CursorState cursorState) override;
    ~SDLGpuWindow() override;
private:
    SDL_Window *mWindow{};
    zkl::SDLGpuRenderer &mRenderer;
};

} // zkl


#endif //FRAGMUAPTE_SDLGPUWINDOW_H
