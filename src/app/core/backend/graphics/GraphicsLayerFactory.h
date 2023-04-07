#ifndef FRAGMUAPTE_GRAPHICSLAYERFACTORY_H
#define FRAGMUAPTE_GRAPHICSLAYERFACTORY_H


#include <memory>
#include "components/GraphicsLayer.h"

namespace fragmuapte::factory {

// FIXME replace string parameter with enum
std::unique_ptr<GraphicsLayer> createGraphicsLayer(std::string_view graphicsLayerType);

}  // namespace fragmuapte::factory


#endif //FRAGMUAPTE_GRAPHICSLAYERFACTORY_H
