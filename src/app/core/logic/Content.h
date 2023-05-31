#ifndef FRAGMUAPTE_LOGIC_ONELEVEL_CONTENT_H
#define FRAGMUAPTE_LOGIC_ONELEVEL_CONTENT_H


#include <string_view>
#include <vector>
#include "components/Camera.h"
#include "components/GameObject.h"
#include "AggregatedState.h"
#include "ResourceLoader.h"
#include "Input.h"

namespace fragmuapte::logic {

class Content
{
public:
    void load(std::string_view file, ResourceLoader const &resourceLoader);
    void update(double deltaTime);
    void prepareRenderingData();

    Input& getInput() { return mInput; }

    // Expose iteration over aggregated states of game objects
    [[nodiscard]] std::vector<AggregatedState>::const_iterator begin() const { return mAggregatedStates.begin(); }
    [[nodiscard]] std::vector<AggregatedState>::const_iterator end() const { return mAggregatedStates.end(); }
    [[nodiscard]] std::vector<AggregatedState>::const_iterator cbegin() const { return mAggregatedStates.cbegin(); }
    [[nodiscard]] std::vector<AggregatedState>::const_iterator cend() const { return mAggregatedStates.cend(); }
private:
    Camera mCamera;
    std::vector<GameObject> mGameObjects;
    std::vector<AggregatedState> mAggregatedStates;
    Input mInput;
};

}  // namespace fragmuapte::logic


#endif //FRAGMUAPTE_LOGIC_ONELEVEL_CONTENT_H
