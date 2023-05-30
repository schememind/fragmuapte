#ifndef FRAGMUAPTE_LOGIC_ONELEVEL_RESOURCELOADER_H
#define FRAGMUAPTE_LOGIC_ONELEVEL_RESOURCELOADER_H


#include <string>

namespace fragmuapte::logic {

struct ResourceLoader
{
    virtual int loadImage(std::string const &path) = 0;
    virtual int loadSound(std::string const &path) = 0;
    virtual ~ResourceLoader() = default;
};

}  // namespace fragmuapte::logic {


#endif //FRAGMUAPTE_LOGIC_ONELEVEL_RESOURCELOADER_H
