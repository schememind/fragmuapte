#ifndef FRAGMUAPTE_INPUTHANDLER_H
#define FRAGMUAPTE_INPUTHANDLER_H


namespace zkl {

struct UserInput
{
    bool isExit{false};
    bool isUpPressed{false};
    bool isUpReleased{false};
    bool isDownPressed{false};
    bool isDownReleased{false};
    bool isRightPressed{false};
    bool isRightReleased{false};
    bool isLeftPressed{false};
    bool isLeftReleased{false};

    void reset()
    {
        isExit = false;
        isUpPressed = false;
        isUpReleased = false;
        isDownPressed = false;
        isDownReleased = false;
        isRightPressed = false;
        isRightReleased = false;
        isLeftPressed = false;
        isLeftReleased = false;
    }
};

class InputHandler
{
public:
    virtual void registerUserInput() = 0;
    [[nodiscard]] UserInput const &getUserInput() const { return mUserInput; }
    virtual ~InputHandler() = default;
protected:
    zkl::UserInput mUserInput;
};

} // zkl

#endif //FRAGMUAPTE_INPUTHANDLER_H
