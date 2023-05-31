#include <algorithm>
#include "FileIdTracker.h"

namespace fragmuapte {

void FileIdTracker::add(const std::string &path, int id)
{
    mFileToId[path] = id;
}

std::optional<int> FileIdTracker::findExistingId(std::string const &path)
{
    if (auto fileIdPair = mFileToId.find(path); fileIdPair != mFileToId.end())
    {
        return fileIdPair->second;
    }
    return std::nullopt;
}

void FileIdTracker::unassignId(int id)
{
    auto iterator = std::ranges::find_if(
            mFileToId.begin(), mFileToId.end(), [id](auto const &pair) {
                return pair.second == id;
            });
    if (iterator != mFileToId.end())
    {
        mFileToId.erase(iterator);
    }
}

}  // namespace fragmuapte