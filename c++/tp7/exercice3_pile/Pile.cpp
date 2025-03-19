#include<iostream>
#include"Pile.hpp"

Pile::Pile(int t){
    dim = t;
    adr = new int[dim];
    taille = 0;
}

Pile::~Pile(){
    delete []adr;
}

void Pile::empile(int x){
    if (this->pleine())
    {
        std::cout << "La pile est pleine" << std::endl;
    }
    else {
        *(adr+taille) = x;
        taille++;
    }
    
    
}

void Pile::depile(){
    if (this->vide())
    {
        std::cout << "la Pile est deja vide" << std::endl;
    }
    else{
        taille--;
    }
    
}

bool Pile::vide() const {
    if (taille != 0)
    {
        return false;
    }
    else return true;
    
}

bool Pile::pleine() const {
    if (taille != dim)
    {
        return false;
    }
    else return true;
    
}

int Pile::donnetaille() const {
    return taille;
}