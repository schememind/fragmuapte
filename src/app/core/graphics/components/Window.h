#ifndef FRAGMUAPTE_WINDOW_H
#define FRAGMUAPTE_WINDOW_H


#include <string>

namespace zkl {

enum class ScreenMode
{
    windowed, fullScreen
};

enum class RenderScaleQuality
{
    pixelated, linear
};

enum class CursorState
{
    visible, invisible
};

class Window
{
public:
    virtual void clear() = 0;
    virtual void render() = 0;
    virtual Window &init() = 0;
    virtual Window &setTitle(std::string const &title) = 0;
    virtual Window &setSize(int width, int height) = 0;
    virtual Window &setResolution(int width, int height) = 0;
    virtual Window &setScreenMode(ScreenMode screenMode) = 0;
    virtual Window &setRenderScaleQuality(RenderScaleQuality renderScaleQuality) = 0;
    virtual Window &setCursorState(CursorState cursorState) = 0;
    virtual ~Window() = default;
};

} // zkl


#endif //FRAGMUAPTE_WINDOW_H
