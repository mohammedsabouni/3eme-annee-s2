#include<iostream>
#include"Compte.hpp"
#include<cstring>

int Compte::cmpt = 1;
void Compte::creer_compte(){
    std::cout << "saisir le nom" << std::endl; 
    num = Compte::cmpt++;
    std::cin.getline(nom,50);
}

void Compte::retrait(){
    unsigned int montant = 0;
    std::cout << "saisir le montant a retraiter : " << std::endl;
    std::cin >> montant ;
    if (montant > solde)
    {
        std::cout << "solde insuffisant " << std::endl;
    }
    else{
        solde -= montant;
    }
}

void Compte::depot(){
    unsigned int montant = 0;
    std::cout << "saisir le montant a deposer : " << std::endl;
    std::cin >> montant ;
    solde += montant;
}