#ifndef FRAGMUAPTE_SDLGPUWINDOW_H
#define FRAGMUAPTE_SDLGPUWINDOW_H


#if defined(_WIN32)
    #include "SDL.h"
#else
    #include "SDL2/SDL.h"
#endif

#include "SDLGpuRenderer.h"
#include "../../../Window.h"

namespace fragmuapte {

class SDLGpuWindow final : public Window
{
public:
    explicit SDLGpuWindow(SDLGpuRenderer &renderer);
    void clear() override;
    void render() override;
    Window &setTitle(std::string const &title) override;
    Window &setSize(int width, int height) override;
    Window &setResolution(int width, int height) override;
    Window &setScreenMode(ScreenMode screenMode) override;
    Window &setRenderScaleQuality(RenderScaleQuality renderScaleQuality) override;
    Window &setCursorState(CursorState cursorState) override;
    ~SDLGpuWindow() override;
private:
    SDL_Window *mWindow{};
    SDLGpuRenderer &mRenderer;
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_SDLGPUWINDOW_H
