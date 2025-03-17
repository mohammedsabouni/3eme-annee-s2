#include"Vecteur3d.hpp"

Vecteur3d::Vecteur3d(){
    x = 0;
    y = 0;
    z = 0;
}

Vecteur3d::Vecteur3d(float x_, float y_, float z_){
    x = x_;
    y = y_;
    z = z_;
}

bool Vecteur3d::coincide(Vecteur3d & v) const{
    if (x == v.getX() && y == v.getY() && z == v.getZ()){
        return true;
    }
    return false;
}

Vecteur3d Vecteur3d::oppose(){
    Vecteur3d op(-x, -y, -z);

    return op;
}

Vecteur3d & Vecteur3d::opposeRef(){
    Vecteur3d static op(-x, -y, -z);

    return op;
}

Vecteur3d * Vecteur3d::opposePtr(){
    Vecteur3d *op = new Vecteur3d(-x, -y, -z);

    return op;
}

Vecteur3d & Vecteur3d::maxX(Vecteur3d & v){
    if (x >= v.x)
    {
        return *this;
    }
    return v;
    
}
Vecteur3d * Vecteur3d::maxXptr(Vecteur3d & v){
    if (x >= v.x)
    {
        return this;
    }
    return &v;
}