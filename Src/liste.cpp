#include "liste.hpp"

#include <iostream>
#include <cassert>

Liste::Liste() {
  /* votre code ici */
  first = nullptr;
  nbElements = 0;
}

Liste::Liste(const Liste& autre): first(nullptr) {
  /* votre code ici */
  Cellule* node = autre.first;
    while (node != nullptr)
    {
        ajouter_en_queue(node->getValue());
        node = node->next;
    }
}

Liste& Liste::operator=(const Liste& autre) {
  /* votre code ici */
  vider();
  Cellule * temp = autre.first;
  while (temp != nullptr) {
    ajouter_en_queue(temp->getValue());
    temp = temp->next;
  }
  return *this;
}

Liste::~Liste() {
  /* votre code ici */
  vider();
}

void Liste::ajouter_en_tete(int valeur) {
  /* votre code ici */
  Cellule * temp = new Cellule(valeur);
  temp->next = first;
  first = temp;
  nbElements++;
}

void Liste::ajouter_en_queue(int valeur) {
  /* votre code ici */
  if (first != nullptr){
    Cellule* last = new Cellule(valeur);
    queue()->next = last;
    nbElements++;
  } else ajouter_en_tete(valeur);
}

void Liste::supprimer_en_tete() {
  /* votre code ici */
  if (first != nullptr){
    Cellule * tmp = first;  
    first = first->next;
    nbElements--;
    delete tmp;
  }
}

Cellule* Liste::tete() {
  /* votre code ici */
  return first ;
}
/**
const Cellule* Liste::tete() const {
   votre code ici 
  return first ;
}
*/
Cellule* Liste::queue() {
  /* votre code ici */
  Cellule * last = first;
  while (last->next != nullptr) {
    last = last->next;
  }
  return last;
}

const Cellule* Liste::queue() const {
  /* votre code ici */
  Cellule * last = first;
  while (last->next != nullptr) {
    last = last->next;
  }
  return last;
}

int Liste::taille() const {
  /* votre code ici */
  return nbElements;
}

Cellule* Liste::recherche(int valeur) {
  /* votre code ici */
  Cellule * temp = first;
  bool found = false;
  while ((temp != nullptr) && !found) {
      if (temp->getValue() == valeur) found = true;
      else {
          temp = temp->next;
      }
  }
  if (found) return temp;
  else return nullptr;
}

const Cellule* Liste::recherche(int valeur) const {
  /* votre code ici */
  Cellule * temp = first;
  bool found = false;
  while ((temp != nullptr) && !found) {
      if (temp->getValue() == valeur) found = true;
      else {
          temp = temp->next;
      }
  }
  if (found) return temp;
  else return nullptr;
}

void Liste::afficher() const {
  /* votre code ici */
  Cellule * temp = first;
  std::cout <<'[';
  while (temp != nullptr) {
    std::cout <<' ';
    std::cout << temp->getValue();
    std::cout <<' ';
    temp = temp->next;
  }
  std::cout <<']';
  std::cout << std::endl;
}

bool Liste::estVide () const {
    return first == nullptr;
}

void Liste::vider () {
  while (!estVide())
    supprimer_en_tete();
}


int Liste::getNbElements() const {
  return nbElements;
} 
