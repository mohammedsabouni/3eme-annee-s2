#ifndef __CHAINE__
#define __CHAINE__
#include<iostream>
class Chaine
{
private:
    char *s;
public:
    Chaine();
    Chaine(const Chaine &);
    ~Chaine();
    void Afficher()const;
    int Longueur()const;
    void Inserer(char ,int );
    bool Appartien(char)const;
    void Inverser();
    void Supprimer(char);
};



#endif