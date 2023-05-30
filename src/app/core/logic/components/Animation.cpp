#include "Animation.h"

namespace fragmuapte::logic {

Frame::Frame(int textureId, int x, int y, int width, int height, double duration)
        : mTextureId{textureId}, mX{x}, mY{y}, mWidth{width}, mHeight{height}, mDuration{duration}
{}

Animation::Animation(bool isLoop) : mIsLoop{isLoop}
{}

Frame const& Animation::getCurrentFrame() const
{
    return mFrames.at(mCurrentFrameId);
}

void Animation::addFrame(int textureId, int x, int y, int width, int height, double time)
{
    mFrames.emplace_back(textureId, x, y, width, height, time);
}

bool Animation::attemptUpdate(double deltaTime)
{
    mCurrentFrameElapsedTime += deltaTime;
    if (auto currentFrameDuration = mFrames.at(mCurrentFrameId).mDuration;
            currentFrameDuration > 0 && mCurrentFrameElapsedTime >= currentFrameDuration)
    {
        if (mCurrentFrameId < mFrames.size() - 1)
        {
            mCurrentFrameId++;
            mCurrentFrameElapsedTime = 0.0;
            return true;
        }
        else if (mIsLoop)
        {
            mCurrentFrameId = 0;
            mCurrentFrameElapsedTime = 0.0;
            return true;
        }
        return false;
    }
    return false;
}

void Animation::start()
{
    mCurrentFrameId = 0;
    mCurrentFrameElapsedTime = 0.0;
}

void Animation::pause()
{
    mIsRunning = false;
}

void Animation::unpause()
{
    mIsRunning = true;
}

}  // namespace fragmuapte::logic