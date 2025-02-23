#ifndef __BANQUE__
    #define __BANQUE__
    #include "Compte.hpp"
    class Banque
    {
    private:
        int nbComptes = 0;
        Compte comptes[10];
    public:
        void add(Compte& compte);
        void deleteCompte(int numero);
        Compte getCompte(int numero);
    };
    
    
    
#endif