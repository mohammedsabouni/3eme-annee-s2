#include<iostream>
#include"Compte.hpp"
#include"Banque.hpp"

void Banque::add(Compte& compte){
    comptes[nbComptes++] = compte;
}

void Banque::deleteCompte(int numero){
    for (int i = 0; i <= nbComptes; i++)
    {
        if (numero == comptes[i].getNum())
        {
            for (int j = i; j < nbComptes; j++)
            {
                comptes[j] = comptes[j+1];
            }
            nbComptes--;
            std::cout << "compte supprime " << std::endl;  
            break;
        }
        
    }
    
}

Compte Banque::getCompte(int numero){
    
    for (int i = 0; i <= nbComptes; i++)
    {
        if (numero == comptes[i].getNum())
        {
            return comptes[i];
        }
        
    }
    std::cout << "pas de compte" << std::endl;
    
    
}
