#include<iostream>
#include"Chaine.hpp"

int main(){
    Chaine bnjr = Chaine("bonjour");
    bnjr.Afficher();
    std::cout << bnjr.Longueur() << std::endl;
    bnjr.Inserer('m',2);
    bnjr.Inserer('m',4);
    bnjr.Afficher();
    std::cout << bnjr.Appartien('z')<< std::endl;
    bnjr.Inverser();
    bnjr.Afficher();
    bnjr.Supprimer('m');
    bnjr.Afficher();
}