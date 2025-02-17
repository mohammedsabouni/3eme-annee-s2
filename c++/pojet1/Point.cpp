#include<iostream>
#include"Point.hpp"

int Point::cmpt = 0;

void Point::saisie(){
    std::cout << "entrez x , y et nom" << std::endl;
    std::cin>>this->x>>this->y>>this->nom;//this est un pointeur vers l objet qui va appeler (objet implicite)
    Point::cmpt++;
}


//methode de classe 
void Point::affiche_nbre(){
    std::cout<<"Nombre de points = " << Point::cmpt << std::endl;
}