#ifndef __VECTEUR3D__
#define __VECTEUR3D__

#include <iostream>

class Vecteur3d
{
private:
    float x, y, z;
public:
    Vecteur3d();
    Vecteur3d(float x_ = 0.0, float y_ = 0.0, float z_ = 0.0);
    inline float getX();
    inline float getY();
    inline float getZ(); 
    bool coincide(Vecteur3d & )const;
    bool coincide(Vecteur3d * )const;
    Vecteur3d oppose();
    Vecteur3d & opposeRef();
    Vecteur3d * opposePtr();
    Vecteur3d & maxX(Vecteur3d &);
    Vecteur3d * maxXptr(Vecteur3d &);
};

inline float Vecteur3d::getX(){
    return this -> x;
}

inline float Vecteur3d::getY(){
    return this -> y;
}

inline float Vecteur3d::getZ(){
    return this -> z;
}


#endif