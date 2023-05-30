#include "MainLoop.h"

namespace fragmuapte {

MainLoop::MainLoop(MediaBackend backend) : mMediaBackend{std::move(backend)}
{}

bool MainLoop::isRunning() const
{
    return mIsRunning;
}

void MainLoop::start()
{
    mMediaBackend.validate();
    mContent.load("datafile.dat", &mMediaBackend);
    mIsRunning = true;
}

void MainLoop::nextStep()
{
    mMediaBackend.timer->refresh();
    mMediaBackend.inputHandler->registerUserInput();
    mIsRunning = !mMediaBackend.inputHandler->getUserInput().isExit;    // FIXME temporary solution

    fillContentInput();
    mContent.update(mMediaBackend.timer->getDelta());
    mContent.getInput().reset();
    mContent.prepareRenderingData();

    mMediaBackend.graphicsLayer->clear();
    for (auto const &aggregatedState : mContent)
    {
        mMediaBackend.graphicsLayer->submitTextureToRenderer(
                aggregatedState.getTextureId(),
                aggregatedState.getSourceX(), aggregatedState.getSourceY(),
                aggregatedState.getSourceWidth(), aggregatedState.getSourceHeight(),
                aggregatedState.getDestinationX(), aggregatedState.getDestinationY(),
                aggregatedState.getDestinationWidth(), aggregatedState.getDestinationHeight(),
                aggregatedState.getPivotX(), aggregatedState.getPivotY(), aggregatedState.getAngle(),
                aggregatedState.getFlipHorizontal(), aggregatedState.getFlipVertical());
    }
    mMediaBackend.graphicsLayer->render();
}

void MainLoop::fillContentInput()
{
    mContent.getInput()
        .setIsUpPressed(mMediaBackend.inputHandler->getUserInput().isUpPressed)
        .setIsUpReleased(mMediaBackend.inputHandler->getUserInput().isUpReleased)
        .setIsDownPressed(mMediaBackend.inputHandler->getUserInput().isDownPressed)
        .setIsDownReleased(mMediaBackend.inputHandler->getUserInput().isDownReleased)
        .setIsRightPressed(mMediaBackend.inputHandler->getUserInput().isRightPressed)
        .setIsRightReleased(mMediaBackend.inputHandler->getUserInput().isRightReleased)
        .setIsLeftPressed(mMediaBackend.inputHandler->getUserInput().isLeftPressed)
        .setIsLeftReleased(mMediaBackend.inputHandler->getUserInput().isLeftReleased);
}

}  // namespace fragmuapte