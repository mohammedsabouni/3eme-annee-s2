#include <iostream>
#include "Vecteur3d.hpp"

int main(){
    Vecteur3d v1(1.2, 2.0, 3.0);
    Vecteur3d v2(1.2, 2.0, 3.0);
    if(v2.coincide(v1)){
        std::cout << "true" << std::endl;
    }
    
    Vecteur3d * v3 = v2.opposePtr();
}