#include "Chaine.hpp"
#include <cstring>

Chaine::Chaine(const char * c)
{
    s = new char [200];
    strcpy(s,c);
}
Chaine::Chaine()
{
    s = new char [200];
    strcpy(s,"default");
}

Chaine::Chaine(const Chaine & c){
    s = new char [200];
    strcpy(s, c.s);
}

Chaine::~Chaine()
{
    // std::cout<< "deleted" << std::endl;
    delete s;
}

void Chaine::Afficher()const{
    std::cout<< "Chaine : "<<std::endl;
    std::cout<< s << std::endl;
}

int Chaine::Longueur()const{
    return strlen(this -> s);
}

void Chaine::Inserer(char c, int pos){
    Chaine tmp = Chaine(*this);
    *(this->s+pos) = c;
    strcpy(this->s+pos+1, tmp.s+pos);
    
}

bool Chaine::Appartien(char c)const{
    char *p = strchr(s, c );
    if (p == NULL)
    {
        return false;
    }
    return true;
    
}

void Chaine::Inverser(){
    char tmp ;
    for (char* p = s, *p2 = s+(strlen(s)-1); p < p2; p++, p2--)
    {
        tmp = *p;
        *p = *p2;
        *p2 = tmp;
    }
    
}

void Chaine::Supprimer(char c){
    char* p = strchr(s,c);
    while (p != NULL)
    {
        strcpy(p, p+1);
        p = strchr(p,c);
    }  
}
