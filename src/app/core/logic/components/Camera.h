#ifndef FRAGMUAPTE_LOGIC_ONELEVEL_CAMERA_H
#define FRAGMUAPTE_LOGIC_ONELEVEL_CAMERA_H


namespace fragmuapte::logic {

struct Camera
{
    int xInWorld{0};
    int yInWorld{0};
    int width{0};
    int height{0};
    double zoom{1.0};
    double angle{0.0};
};

}  // namespace fragmuapte::logic {


#endif //FRAGMUAPTE_LOGIC_ONELEVEL_CAMERA_H
