#ifndef Point
 
    class Point
    {
        private:
            float x;
            float y;
            char * nom;
            static int nbrpt;
        public:
            Point();//constructeur par defaut explicite
            Point(const float &, const char * );
            Point(const float &, const float &, const char * );
            ~Point();//destructeur on peut avoir un seule
            void saisie();
            void affiche();
               
    };
       
#endif

