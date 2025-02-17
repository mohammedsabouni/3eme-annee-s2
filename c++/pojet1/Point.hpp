#ifndef __POINT__
    #define __POINT__
 
    class Point
    {
        private:
            float x;
            float y;
            char nom;
            static int cmpt;
        public:
            void saisie();
            // methode inline (insertion) max 2 lignes de code liees a la compilation
            inline void affiche();
            static void affiche_nbre();
               
    };

    inline void Point::affiche(){
        std::cout << this->nom << "("<< this->x << " , "<< this->y << ")" << std::endl;
        
    }
       
#endif

// une methode de classe est toute methode qui utilise que les attributs de classes 
// une methode d objet (d instance) est une methode qui utilise au oins un  attribut d objet