#ifndef FRAGMUAPTE_LOGIC_ONELEVEL_ANIMATION_H
#define FRAGMUAPTE_LOGIC_ONELEVEL_ANIMATION_H


#include <vector>

namespace fragmuapte::logic {

class Frame
{
public:
    Frame(int textureId, int x, int y, int width, int height, double duration);
    [[nodiscard]] int getTextureId() const { return mTextureId; }
    [[nodiscard]] int getX() const { return mX; }
    [[nodiscard]] int getY() const { return mY; }
    [[nodiscard]] int getWidth() const { return mWidth; }
    [[nodiscard]] int getHeight() const { return mHeight; }
    friend class Animation;
private:
    const int mTextureId;
    const int mX;
    const int mY;
    const int mWidth;
    const int mHeight;
    const double mDuration;
};

class Animation
{
public:
    explicit Animation(bool isLoop);
    [[nodiscard]] Frame const &getCurrentFrame() const;
    void addFrame(int textureId, int x, int y, int width, int height, double time);
    bool attemptUpdate(double deltaTime);
    void start();
    void pause();
    void unpause();
private:
    size_t mCurrentFrameId{0};
    double mCurrentFrameElapsedTime{0.0};
    bool mIsRunning{false};
    bool mIsLoop{false};
    std::vector<Frame> mFrames{};
};

}  // namespace fragmuapte::logic


#endif //FRAGMUAPTE_LOGIC_ONELEVEL_ANIMATION_H
