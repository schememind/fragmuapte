#ifndef FRAGMUAPTE_APP_H
#define FRAGMUAPTE_APP_H


#include "settings/Settings.h"
#include "core/MainLoop.h"

namespace zkl {

class App
{
public:
    zkl::App &loadSettings();
    void start();
private:
    zkl::Settings mSettings;
    zkl::MainLoop mMainLoop;
};

} // zkl


#endif //FRAGMUAPTE_APP_H
