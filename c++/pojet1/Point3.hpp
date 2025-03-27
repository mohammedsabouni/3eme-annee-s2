#ifndef __Point3__
    #define __Point3__
#include"Point.hpp"

class Point3:public Point
{
    private:
        float z;
    public:
        Point3();
        ~Point3();
};
#endif

