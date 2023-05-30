#ifndef FRAGMUAPTE_INPUT_H
#define FRAGMUAPTE_INPUT_H


namespace fragmuapte::logic {

class Input
{
public:
    Input &setIsUpPressed(bool value) { isUpPressed = value; return *this; }
    Input &setIsUpReleased(bool value) { isUpReleased = value; return *this; }
    Input &setIsDownPressed(bool value) { isDownPressed = value; return *this; }
    Input &setIsDownReleased(bool value) { isDownReleased = value; return *this; }
    Input &setIsRightPressed(bool value) { isRightPressed = value; return *this; }
    Input &setIsRightReleased(bool value) { isRightReleased = value; return *this; }
    Input &setIsLeftPressed(bool value) { isLeftPressed = value; return *this; }
    Input &setIsLeftReleased(bool value) { isLeftReleased = value; return *this; }
    void reset();
    friend class Content;
private:
    bool isUpPressed{false};
    bool isUpReleased{false};
    bool isDownPressed{false};
    bool isDownReleased{false};
    bool isRightPressed{false};
    bool isRightReleased{false};
    bool isLeftPressed{false};
    bool isLeftReleased{false};
};

}  // namespace fragmuapte::logic {


#endif //FRAGMUAPTE_INPUT_H
