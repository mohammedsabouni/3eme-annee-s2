#ifndef __Point__
    #define __Point__
    #include <iostream>
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
            Point & operator= (const Point &);
            void saisie();
            void affiche() const;
            bool compare(const Point &) const;
            Point & operator+ (const Point &);
            Point & operator* (const float & );
            friend Point & operator* (const float &, const Point &);
            friend std::istream & operator>> (std::istream &, Point &); 
            friend std::ostream & operator<< (std::ostream &,const Point &);
    };
       
#endif

