#include "Input.h"

namespace fragmuapte::logic {

void Input::reset()
{
    isUpPressed = false;
    isUpReleased = false;
    isDownPressed = false;
    isDownReleased = false;
    isRightPressed = false;
    isRightReleased = false;
    isLeftPressed = false;
    isLeftReleased = false;
}

}  // namespace fragmuapte::logic