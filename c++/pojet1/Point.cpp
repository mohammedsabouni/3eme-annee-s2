#include<iostream>
#include"Point.hpp"

int Point::cmpt = 0;

void Point::saisie(){
    std::cout << "entrez x , y et nom" << std::endl;
    std::cin>>this->x>>this->y>>this->nom;
    Point::cmpt++;
}

void Point::affiche(){
    std::cout << this->nom << "("<< this->x << " , "<< this->y << ")" << std::endl;
    std::cout << "nombre de points : "<< Point::cmpt << std::endl;
}