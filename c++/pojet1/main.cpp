#include<iostream>
#include"Point.hpp"

int main(){
    Point A, *B;
    B = new Point;
    A.saisie();
    B->saisie();
    A.affiche();
    B->affiche();

    return 0;
}