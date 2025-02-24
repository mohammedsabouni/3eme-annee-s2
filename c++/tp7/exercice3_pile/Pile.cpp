#include<iostream>
#include"Pile.hpp"

Pile::Pile(int t){
    dim = t;
    adr = new int[t];
    taille = 0;
}

Pile::~Pile(){
    delete adr;
}

void Pile::empile(int x){
    if (this->pleine())
    {
        std::cout << "La pile est pleine" << std::endl;
    }
    else if (this->vide())
    {
        *(adr + (dim-1)) = x;
        taille++;
    }
    else{
        for (int* p1 = adr+(dim-taille); p1 < adr+dim; p1++)
        {
            *(p1-1) = *(p1);
        }
        *(adr + (dim-1)) = x;
        taille++;
    }
    
    
}

void Pile::depile(){
    if (this->vide())
    {
        std::cout << "la Pile est deja vide" << std::endl;
    }
    else{
        for(int* p1 = adr+(dim-1); p1 >= adr+(dim-taille); p1--){
            *(p1) = *(p1-1);
        }
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