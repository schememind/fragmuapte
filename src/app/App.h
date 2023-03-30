#ifndef FRAGMUAPTE_APP_H
#define FRAGMUAPTE_APP_H


#include "settings/Settings.h"
#include "core/MainLoop.h"

namespace fragmuapte {

class App
{
public:
    App &loadSettings();
    void start();
private:
    Settings mSettings;
    MainLoop mMainLoop;
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_APP_H
