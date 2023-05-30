#ifndef FRAGMUAPTE_APP_H
#define FRAGMUAPTE_APP_H


#include "settings/Settings.h"

namespace fragmuapte {

class App
{
public:
    App &loadSettings();
    void start() const;
private:
    Settings mSettings;
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_APP_H
