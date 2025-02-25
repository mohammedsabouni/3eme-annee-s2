#ifndef __COMPTE__
    #define __COMPTE__
    #include<iostream>

    class Compte
    {
        private:
            static int compteur;
            int numClient;
            char* nomClient;
            float soldeClient;
        public:
            Compte();
            Compte(char *);
            ~Compte();
            inline void consulterCompte() const;
            void retrait();
            void depos();
        };
    
        inline void Compte::consulterCompte() const{
            std::cout << "compte numero : " << numClient << "\n" << "nom client : " << nomClient << "\n" << "solde : " << soldeClient << std::endl;
        }
    
#endif