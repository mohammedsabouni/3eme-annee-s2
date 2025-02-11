#include<iostream>
#include"Point.hpp"

void Point::saisie(){
    std::cout << "entrez x , y et nom" << std::endl;
    std::cin>>this->x>>this->y>>this->nom;
}

void Point::affiche(){
    std::cout << this->nom << "("<< this->x << " , "<< this->y << ")" << std::endl;
}