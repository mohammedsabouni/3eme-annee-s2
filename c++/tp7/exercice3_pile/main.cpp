#include<iostream>
#include"Pile.hpp"

int main(){
    Pile A, B;
    A.empile(1);
    A.empile(2);
    A.afficher();
    B = A;
    B.afficher();
    if (A == B)
    {
        std::cout << "true" << std::endl;
    }
    std::cout<<A[0] << std::endl;
    Pile c = A + B;
    c.afficher();
    std::cout << c ;
     



}