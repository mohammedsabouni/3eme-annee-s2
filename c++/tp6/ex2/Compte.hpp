#ifndef __COMPTE__
    #define __COMPTE__
    #include<iostream>
    class Compte
    {
    private:
        int num;
        char nom[50];
        double solde = 0;
        static int cmpt;
    public:
        void creer_compte();
        inline void consulter_compte();
        void retrait();
        void depot();
        inline int getNum();
    };
    
    inline void Compte::consulter_compte(){
        std::cout << "compte numero : " << num << "\n" << "nom client : " << nom << "\n" << "solde : " << solde << std::endl;
    }
    
    inline int Compte::getNum(){
        return num;
    }
#endif