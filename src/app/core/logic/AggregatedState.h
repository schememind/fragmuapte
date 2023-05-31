#ifndef FRAGMUAPTE_LOGIC_ONELEVEL_RENDERDATA_H
#define FRAGMUAPTE_LOGIC_ONELEVEL_RENDERDATA_H


namespace fragmuapte::logic {

class AggregatedState
{
public:
    [[nodiscard]] int getTextureId() const { return mTextureId; }
    [[nodiscard]] int getSourceX() const { return mSrcX; }
    [[nodiscard]] int getSourceY() const { return mSrcY; }
    [[nodiscard]] int getSourceWidth() const { return mSrcWidth; }
    [[nodiscard]] int getSourceHeight() const { return mSrcHeight; }
    [[nodiscard]] int getDestinationX() const { return mDstX; }
    [[nodiscard]] int getDestinationY() const { return mDstY; }
    [[nodiscard]] int getDestinationWidth() const { return mDstWidth; }
    [[nodiscard]] int getDestinationHeight() const { return mDstHeight; }
    [[nodiscard]] int getPivotX() const { return mPivotX; }
    [[nodiscard]] int getPivotY() const { return mPivotY; }
    [[nodiscard]] float getAngle() const { return mAngle; }
    [[nodiscard]] bool getFlipHorizontal() const { return mIsFlipHorizontal; }
    [[nodiscard]] bool getFlipVertical() const { return mIsFlipVertical; }
    friend class Content;
private:
    int mTextureId{0};
    int mSrcX{0};
    int mSrcY{0};
    int mSrcWidth{0};
    int mSrcHeight{0};
    int mDstX{0};
    int mDstY{0};
    int mDstWidth{0};
    int mDstHeight{0};
    int mPivotX{0};
    int mPivotY{0};
    float mAngle{0.0};
    bool mIsFlipHorizontal{false};
    bool mIsFlipVertical{false};
};

}  // namespace fragmuapte::logic


#endif //FRAGMUAPTE_LOGIC_ONELEVEL_RENDERDATA_H
