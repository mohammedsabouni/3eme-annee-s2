#include<iostream>
#include"Compte.hpp"
#include<cstring>

int Compte::compteur = 0;
Compte::Compte(){
    numClient = ++Compte::compteur;
    nomClient = new char[20];
    strcpy(nomClient,"Default");
    soldeClient = 0;
}

Compte::Compte(char * nomClient_){
    numClient = ++Compte::compteur;
    nomClient = new char[strlen(nomClient_)+1];
    strcpy(nomClient, nomClient_);
    soldeClient = 0;
}
    
Compte::~Compte(){
    delete nomClient;
}

void Compte::retrait(){
    unsigned int montant = 0;
    std::cout << "saisir le montant a retraiter : " << std::endl;
    std::cin >> montant ;
    if (montant > soldeClient)
    {
        std::cout << "solde insuffisant " << std::endl;
    }
    else{
        soldeClient -= montant;
    }
}

void Compte::depos(){
    unsigned int montant = 0;
    std::cout << "saisir le montant a deposer : " << std::endl;
    std::cin >> montant ;
    soldeClient += montant;
}