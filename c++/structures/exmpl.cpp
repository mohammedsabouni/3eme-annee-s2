#include<iostream>


class Point
{
    private:
        float x;
        float y;
        char nom;

    public:
        void saisie();
        void affiche();
};

int main(){
    Point A, *B;
    B = new Point;
    A.saisie();
    B->saisie();
    A.affiche();
    B->affiche();

    delete B;
    return 0;
    
}

void Point::saisie(){
    std::cout << "entrez x , y et nom" << std::endl;
    std::cin >> this -> x >> this -> y >> this -> nom;
}

void Point::affiche(){
    std::cout << this -> nom << "("<< this -> x << " , "<< this -> y << ")" << std::endl;
}