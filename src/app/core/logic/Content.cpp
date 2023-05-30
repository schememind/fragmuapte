#include <algorithm>

#include "Content.h"

namespace fragmuapte::logic {

void Content::load(std::string_view file, ResourceLoader *resourceLoader)
{
    // TODO load from file

    mCamera.xInWorld = 300;
    mCamera.yInWorld = 400;
    mCamera.width = 800;
    mCamera.height = 600;

    int textureId1 = resourceLoader->loadImage("resources/images/sprite_001.png");
    Animation anim1(false);
    anim1.addFrame(textureId1, 0, 0, 60, 100, 0);

    GameObject gameObject1;
    gameObject1.xInWorld = 400;
    gameObject1.yInWorld = 500;
    gameObject1.isFlipVertical = false;
    gameObject1.isFlipHorizontal = false;
    gameObject1.animations.emplace_back(anim1);

    mGameObjects.emplace_back(gameObject1);

    // With every game object create initial aggregated state
    mAggregatedStates.emplace_back();
}

void Content::update(double deltaTime)
{
    // TODO: Implement state pattern
    if (mInput.isRightPressed)
    {
        mGameObjects.at(0).isFlipHorizontal = false;
        mGameObjects.at(0).xSpeed = 400;
    }
    if (mInput.isLeftPressed)
    {
        mGameObjects.at(0).isFlipHorizontal = true;
        mGameObjects.at(0).xSpeed = -400;
    }
    if ((mInput.isRightReleased && mGameObjects.at(0).xSpeed != -400)
        || (mInput.isLeftReleased && mGameObjects.at(0).xSpeed != 400))
    {
        mGameObjects.at(0).xSpeed = 0;
    }
    if (mInput.isUpPressed)
    {
        mGameObjects.at(0).ySpeed = -400;
    }
    if (mInput.isDownPressed)
    {
        mGameObjects.at(0).ySpeed = 400;
    }
    if ((mInput.isUpReleased && mGameObjects.at(0).ySpeed != 400)
        || (mInput.isDownReleased && mGameObjects.at(0).ySpeed != -400))
    {
        mGameObjects.at(0).ySpeed = 0;
    }

    std::ranges::for_each(mGameObjects, [deltaTime](auto &gameObject) {
        gameObject.xInWorld += (int)(gameObject.xSpeed * deltaTime);
        gameObject.yInWorld += (int)(gameObject.ySpeed * deltaTime);
    });
}

void Content::prepareRenderingData()
{
    for (auto const &gameObject : mGameObjects)
    {
        auto index = &gameObject - &mGameObjects[0];
        if (index >= mAggregatedStates.size()) break;
        AggregatedState& aggregatedState = mAggregatedStates.at(index);

        Frame const& currentFrame = gameObject.animations.at(gameObject.currentAnimationId).getCurrentFrame();
        aggregatedState.mTextureId = currentFrame.getTextureId();
        aggregatedState.mSrcX = currentFrame.getX();
        aggregatedState.mSrcY = currentFrame.getY();
        aggregatedState.mSrcWidth = currentFrame.getWidth();
        aggregatedState.mSrcHeight = currentFrame.getHeight();
        aggregatedState.mDstX = gameObject.xInWorld - mCamera.xInWorld;  // TODO camera zoom
        aggregatedState.mDstY = gameObject.yInWorld - mCamera.yInWorld;  // TODO camera zoom
        aggregatedState.mDstWidth = (int)(currentFrame.getWidth() * gameObject.scaleX);  // TODO camera zoom
        aggregatedState.mDstHeight = (int)(currentFrame.getHeight() * gameObject.scaleY);  // TODO camera zoom
        aggregatedState.mPivotX = aggregatedState.mDstX + gameObject.pivotRelativeX;
        aggregatedState.mPivotY = aggregatedState.mDstY + gameObject.pivotRelativeY;
        aggregatedState.mAngle = gameObject.angle;
        aggregatedState.mIsFlipHorizontal = gameObject.isFlipHorizontal;
        aggregatedState.mIsFlipVertical = gameObject.isFlipVertical;
    }
}

}  // namespace fragmuapte::logic