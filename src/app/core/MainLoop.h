#ifndef FRAGMUAPTE_MAINLOOP_H
#define FRAGMUAPTE_MAINLOOP_H


#include "MediaBackend.h"
#include "logic/Content.h"

namespace fragmuapte {

class MainLoop
{
public:
    explicit MainLoop(MediaBackend backend);
    [[nodiscard]] bool isRunning() const;
    void start();
    void nextStep();    // FIXME return meaningful signal
private:
    MediaBackend mMediaBackend;
    logic::Content mContent;
    bool mIsRunning{false};
    void fillContentInput();
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_MAINLOOP_H
