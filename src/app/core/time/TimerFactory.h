#ifndef FRAGMUAPTE_TIMERFACTORY_H
#define FRAGMUAPTE_TIMERFACTORY_H


#include <memory>
#include "components/Timer.h"

namespace fragmuapte::factory {

// FIXME replace string parameter with enum
std::unique_ptr<Timer> createTimer(std::string_view timerType);

}  // namespace fragmuapte::factory


#endif //FRAGMUAPTE_TIMERFACTORY_H
