#include<iostream>
#include"Point.hpp"
#include<string.h>

void Point::saisie(){
    std::cout << "entrez x , y et nom" << std::endl;
    std::cin>>this->x>>this->y>>this->nom;
}

void Point::affiche(){
    std::cout << this->nom << "("<< this->x << " , "<< this->y << ")" << std::endl;
}

int Point::nbrpt = 0;
Point::Point(){
    x = 0.0;
    y = 0.0;
    nom = new char[20];
    strcpy(nom, "AA");
    Point::nbrpt++;
    std::cout << "constructeur par default" << std::endl;
}

Point::Point(const float & n, const char *  c){
    x = n;
    y = n;
    nom = new char [strlen(c)+1];
    strcpy(nom,c);
    Point::nbrpt++;

}

Point::Point(const float & x_, const float & y_, const char *  nom_){
    x = x_;
    y = y_;
    nom = new char[strlen(nom_)+1];
    strcpy(nom, nom_);
    Point::nbrpt++;

}

Point::~Point(){
    delete nom;
    std::cout << "Destructeur" << std::endl; 
}