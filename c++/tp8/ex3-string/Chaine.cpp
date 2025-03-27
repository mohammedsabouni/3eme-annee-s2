#include "Chaine.hpp"
#include <cstring>

Chaine::Chaine(const char * c)
{
    int i = 0;
    int cmpt = 0;
    while (*(c+i)!= '\0')
    {
        cmpt++;
        i++;
    }
    
    s = new char [cmpt+1];
    for (int i = 0; i < cmpt+1; i++)
    {
        *(s+i) = *(c+i);
    };
    
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
    int i = 0;
    while (*(s+i)!= '\0')
    {
        i++;
    };
    return i;
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
