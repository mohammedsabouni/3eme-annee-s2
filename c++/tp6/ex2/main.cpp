#include<iostream>
#include"Compte.hpp"
#include"Banque.hpp"

int main(){

    Compte A, B;
    A.creer_compte();
    A.consulter_compte();
    // B.creer_compte();
    // B.consulter_compte();
    // A.depot();
    // A.consulter_compte();
    // A.retrait();
    // A.consulter_compte();

    Banque cih;
    cih.add(A);
    cih.getCompte(1);
    cih.deleteCompte(1);
    
    cih.getCompte(1).consulter_compte();
    
    return 0;
}