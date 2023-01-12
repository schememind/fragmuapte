#ifndef FRAGMUAPTE_INPUTHANDLERFACTORY_H
#define FRAGMUAPTE_INPUTHANDLERFACTORY_H


#include <memory>
#include "components/InputHandler.h"

namespace zkl::factory {

// FIXME replace string parameter with enum
std::unique_ptr<zkl::InputHandler> createInputHandler(std::string_view inputHandlerType);

} // zkl


#endif //FRAGMUAPTE_INPUTHANDLERFACTORY_H
