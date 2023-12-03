#ifndef POKEDEX_H
#define POKEDEX_H

#include <iostream>
#include <string>
#include <vector>
#include "Trainer.h"

using namespace std;

class Pokedex {
  vector<Pokemon> pokemons;
public:
  Pokedex () {}
  vector<Pokemon> getPokemons() {return pokemons;}
  void addPokemon(Pokemon& p) {pokemons.push_back(p);}
  void showPokemon() {
    for(int i=0; i < pokemons.size(); i++){
         pokemons[i].printData();
    }
  }
};

#endif