#include<iostream>
#include"Pile.hpp"

Pile::Pile(int t){
    dim = t;
    adr = new int[dim];
    taille = 0;
}

Pile::Pile(Pile& p){
    dim = p.dim;
    taille = p.taille;
    adr = new int[dim];
    for (int i = 0; i < taille; i++)
    {
        *(adr+i) = *(p.adr+i);
    }
    
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

Pile& Pile::operator=(const Pile& P){
    dim = P.dim;
    taille = P.taille;
    delete [] adr;
    adr = new int[dim];
    for (int i = 0; i < taille; i++)
    {
        *(adr+i) = *(P.adr + i);
    }

    return *(this);
}

bool Pile::operator==(const Pile& P)const{
    if(taille == P.taille){
        for (int i = 0; i < taille; i++)
        {
            if(*(adr) != *(P.adr))
            {
                return false;
            }
        }
        return true;
    }
    else return false;
    
}

void Pile::afficher()const
{
    std::cout << "dim : " << dim << std::endl;
    std::cout << "taille : " << taille << std::endl;
    for (int i = 0; i < taille; i++)
    {
        std::cout << *(adr+i) << " |\t";
    }
    std::cout << std::endl;
}

int Pile::operator[](int p)const{
    if(p > taille || p < 0){
        std::cout<<" cet element n existe pas" << std::endl;
    }
    else{
        return *(adr+p);
    }
}

Pile& Pile::operator+(Pile& p)const{
    if (taille != p.taille)
    {
        std::cout << "tailles differentes" << std::endl;
    }
    else
    {
        static Pile res(p);
        for (int i = 0; i < taille; i++)
        {
            *(res.adr+i) += *(adr+i);
        }
        return res;
        
    }    
}

std::ostream& operator<<(std::ostream& COUT,const Pile& p){
    for (int i = 0; i < p.taille; i++)
    {
        COUT << *(p.adr + i) << " |\t";
    }
    COUT << std::endl;
    return COUT;
    
}




