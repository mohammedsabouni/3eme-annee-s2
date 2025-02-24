#ifndef __PILE__ 
#define __PILE__ 
class Pile { 
    private : 
        int dim; 
        int taille; 
        int *adr; 
    public : 
        Pile(int t = 10); //Constructeur qui construit une pile de dimension t (10 par defaut) 
        ~Pile(); //Destructeur 
        void empile(int); //empile n en haut de la pile 
        void depile(); //depile le sommet de la pile 
        bool vide() const; //teste si la pile est vide 
        bool pleine() const; //teste si la pile est pleine 
        int donnetaille() const; //renvoie la taille de la pile 
}; 
#endif