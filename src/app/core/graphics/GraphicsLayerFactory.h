#ifndef FRAGMUAPTE_GRAPHICSLAYERFACTORY_H
#define FRAGMUAPTE_GRAPHICSLAYERFACTORY_H


#include <memory>
#include "components/GraphicsLayer.h"

namespace zkl::factory {

// FIXME replace string parameter with enum
std::unique_ptr<zkl::GraphicsLayer> createGraphicsLayer(std::string_view graphicsLayerType);

}  // zkl::factory


#endif //FRAGMUAPTE_GRAPHICSLAYERFACTORY_H
