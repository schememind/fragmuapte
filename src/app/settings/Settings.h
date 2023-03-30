#ifndef FRAGMUAPTE_SETTINGS_H
#define FRAGMUAPTE_SETTINGS_H


#include <string_view>

namespace fragmuapte {

struct Settings
{
    void loadFromUserConfig();

    // TODO create mapping logic when factory parameters are switched to enum types
    std::string_view graphicsLayerType = "sdl_gpu";
    std::string_view inputHandlerType = "sdl";
    std::string_view timerType = "sdl";
    int windowWidth = 800;
    int windowHeight = 600;
    int resolutionWidth = 800;
    int resolutionHeight = 600;
    bool isFullScreen = false;
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_SETTINGS_H
