#ifndef FRAGMUAPTE_TIMER_H
#define FRAGMUAPTE_TIMER_H


namespace zkl {

class Timer
{
public:
    virtual void refresh() = 0;
    [[nodiscard]] double getDelta() const { return mDelta; }
    virtual ~Timer() = default;
protected:
    double mDelta{0.0};
};

} // zkl


#endif //FRAGMUAPTE_TIMER_H
