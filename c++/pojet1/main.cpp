#include<iostream>
#include"Point.hpp"

int main(){
    Point A, *B;
    //const Point C(2,3,"ABC");
    B = new Point(1.3, "BBB");
    // A.affiche();
    // A.saisie();
    // B->saisie();
    // A.affiche();
    // B->affiche();
    // C.affiche();
    if (B->compare(A))
    {
        std::cout << "egalite" << std::endl;
    }
    else{
        std::cout << "non egeaux" << std::endl;
    }
    
    delete B;
    // std::cout << "*********" << std::endl;

    return 0;
}