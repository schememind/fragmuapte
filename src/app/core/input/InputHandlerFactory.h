#ifndef FRAGMUAPTE_INPUTHANDLERFACTORY_H
#define FRAGMUAPTE_INPUTHANDLERFACTORY_H


#include <memory>
#include "components/InputHandler.h"

namespace fragmuapte::factory {

// FIXME replace string parameter with enum
std::unique_ptr<InputHandler> createInputHandler(std::string_view inputHandlerType);

}  // namespace fragmuapte::factory


#endif //FRAGMUAPTE_INPUTHANDLERFACTORY_H
