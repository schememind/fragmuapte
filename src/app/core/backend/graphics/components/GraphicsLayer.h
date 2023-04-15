#ifndef FRAGMUAPTE_GRAPHICSLAYER_H
#define FRAGMUAPTE_GRAPHICSLAYER_H


#include <string>

namespace fragmuapte {

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

struct GraphicsLayer
{
    virtual void clear() = 0;
    virtual void render() = 0;
    virtual GraphicsLayer &setTitle(std::string const &title) = 0;
    virtual GraphicsLayer &setSize(int width, int height) = 0;
    virtual GraphicsLayer &setResolution(int width, int height) = 0;
    virtual GraphicsLayer &setScreenMode(ScreenMode screenMode) = 0;
    virtual GraphicsLayer &setRenderScaleQuality(RenderScaleQuality renderScaleQuality) = 0;
    virtual GraphicsLayer &setCursorState(CursorState cursorState) = 0;

    virtual int addTextureFromFile(std::string const &path) = 0;
    virtual void removeTextureById(int textureId) = 0;
    virtual void submitTextureToRenderer(int textureId,
                                         int srcX, int srcY, int srcW, int srcH,
                                         int dstX, int dstY, int dstW, int dstH,
                                         int pivotX, int pivotY, float angle,
                                         bool isFlipHorizontal, bool isFlipVertical) = 0;

    virtual ~GraphicsLayer() = default;
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_GRAPHICSLAYER_H
