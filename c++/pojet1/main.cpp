#include<iostream>
#include"Point.hpp"

int main(){
    Point A, *B, C(2,3,"ABC");
    B = new Point(1.3, "BBB");
    A.affiche();
    // A.saisie();
    // B->saisie();
    // A.affiche();
    B->affiche();
    C.affiche();
    delete B;
    std::cout << "*********" << std::endl;

    return 0;
}