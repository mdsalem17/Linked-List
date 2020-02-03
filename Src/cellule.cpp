#include "cellule.hpp"
    Cellule::Cellule(int v){
        value = v;
        next = nullptr;
    }
  
    int Cellule::getValue(){
      return value;
    }

    void Cellule::setValue(int v){
      value = v;
    }

