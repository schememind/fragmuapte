#ifndef FRAGMUAPTE_APP_H
#define FRAGMUAPTE_APP_H


#include "settings/Settings.h"

namespace zkl {

class App
{
public:
    zkl::App &loadSettings();
    void start() const;
private:
    zkl::Settings mSettings{};
    // FIXME move MainLoop as a member variable to here for better readability
};

} // zkl


#endif //FRAGMUAPTE_APP_H
