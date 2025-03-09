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
            Point(const Point &);//constructeur de recopie
            ~Point();//destructeur on peut avoir un seule
            Point & operator = (const Point &);
            void saisie();
            void affiche() const;
            bool compare(const Point &) const;
               
    };
       
#endif

