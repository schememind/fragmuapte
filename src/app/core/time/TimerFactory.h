#ifndef FRAGMUAPTE_TIMERFACTORY_H
#define FRAGMUAPTE_TIMERFACTORY_H


#include <memory>
#include "components/Timer.h"

namespace zkl::factory {

// FIXME replace string parameter with enum
std::unique_ptr<zkl::Timer> createTimer(std::string_view timerType);

} // zkl


#endif //FRAGMUAPTE_TIMERFACTORY_H
