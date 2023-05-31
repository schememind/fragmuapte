#ifndef FRAGMUAPTE_FILEIDTRACKER_H
#define FRAGMUAPTE_FILEIDTRACKER_H


#include <map>
#include <string>
#include <optional>

namespace fragmuapte {

class FileIdTracker
{
public:
    void add(std::string const &path, int id);
    std::optional<int> findExistingId(std::string const &path);
    void unassignId(int id);
private:
    std::map<std::string, int, std::less<>> mFileToId{};
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_FILEIDTRACKER_H
