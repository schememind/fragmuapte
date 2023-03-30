#ifndef FRAGMUAPTE_TIMER_H
#define FRAGMUAPTE_TIMER_H


namespace fragmuapte {

class Timer
{
public:
    virtual void refresh() = 0;
    [[nodiscard]] double getDelta() const { return mDelta; }
    virtual ~Timer() = default;
protected:
    double mDelta{0.0};
};

}  // namespace fragmuapte


#endif //FRAGMUAPTE_TIMER_H
