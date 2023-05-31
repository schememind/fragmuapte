#ifndef FRAGMUAPTE_LOGIC_ONELEVEL_GAMEOBJECT_H
#define FRAGMUAPTE_LOGIC_ONELEVEL_GAMEOBJECT_H


#include <vector>
#include "Animation.h"

namespace fragmuapte::logic {

struct GameObject
{
    // Position
    int xInWorld{0};
    int yInWorld{0};
    double scaleX{1.0};
    double scaleY{1.0};

    // Flip
    bool isFlipHorizontal{false};
    bool isFlipVertical{false};

    // Rotation
    int pivotRelativeX{0};
    int pivotRelativeY{0};
    float angle{0.0};

    // Modification
    int xSpeed{0};
    int ySpeed{0};

    // Rendering
    size_t currentAnimationId{0};
    std::vector<Animation> animations{};
};

}  // namespace fragmuapte::logic


#endif //FRAGMUAPTE_LOGIC_ONELEVEL_GAMEOBJECT_H
