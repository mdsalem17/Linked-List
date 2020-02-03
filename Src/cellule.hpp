#ifndef LIFAP6_LISTE_CELLULE_HPP
#define LIFAP6_LISTE_CELLULE_HPP

class Cellule {
  private: 
    int value;
  
  public:

    Cellule* next;

    Cellule(int v = 0);
  
    int getValue();

    void setValue(int v);
  
} ;

#endif
