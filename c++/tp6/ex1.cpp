#include<iostream>

struct Point
{
    double x;
    double y;
    char nom;

    void init();
    void print();
    void translate(double x,double y);
};

int main(){
    Point A, *B;
    B = new Point;
    A.init();
    B->init();
    
    A.print();
    B->print();

    A.translate(1, 2);
    B->translate(1, 2);

    A.print();
    B->print();

    return 0;
    
}

void Point::init(){
    std::cout << "entrez x , y et nom" << std::endl;
    std::cin >> this -> x >> this -> y >> this -> nom;
}

void Point::print(){
    std::cout << this -> nom << "("<< this -> x << " , "<< this -> y << ")" << std::endl;
}

void Point::translate(double x, double y){
    this -> x += x;
    this -> y += y;
}