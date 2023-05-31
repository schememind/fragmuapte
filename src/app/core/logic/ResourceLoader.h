#ifndef FRAGMUAPTE_LOGIC_ONELEVEL_RESOURCELOADER_H
#define FRAGMUAPTE_LOGIC_ONELEVEL_RESOURCELOADER_H


#include <string>

namespace fragmuapte::logic {

struct ResourceLoader
{
    [[nodiscard]] virtual int loadImage(std::string const &path) const = 0;
    [[nodiscard]] virtual int loadSound(std::string const &path) const = 0;
    virtual ~ResourceLoader() = default;
};

}  // namespace fragmuapte::logic


#endif //FRAGMUAPTE_LOGIC_ONELEVEL_RESOURCELOADER_H
