#ifndef FRAGMUAPTE_TEXTUREREPOSITORY_H
#define FRAGMUAPTE_TEXTUREREPOSITORY_H


#include <string>

namespace zkl {

class TextureRepository
{
public:
    virtual int addTextureFromFile(std::string const &path) = 0;
    virtual void removeTextureById(int textureId) = 0;
    virtual void submitTextureToRenderer(int textureId,
                                         int srcX, int srcY, int srcW, int srcH,
                                         int dstX, int dstY, int dstW, int dstH,
                                         int pivotX, int pivotY, float angle,
                                         bool isFlipHorizontal, bool isFlipVertical) = 0;
    virtual ~TextureRepository() = default;
};

} // zkl


#endif //FRAGMUAPTE_TEXTUREREPOSITORY_H
