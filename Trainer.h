#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <string>
#include <vector>
#include "User.h"
using namespace std;

class Trainer : public User {
  vector<Pokemon> pokemonsCaptured;
  int pokeballsLeft, money;
public:
  Trainer (string n, string pas, bool ad) : User(n, pas, ad) {
    pokeballsLeft = 10;
    money = 1000;
  }
  int getMoney(){return money;}
  int getPokeballsLeft(){return pokeballsLeft;}
  void setPokeballsLeft(int p){pokeballsLeft=p;}
  void setMoney(int m){money=m;}
  vector<Pokemon> getPokemons() {return pokemonsCaptured;}
  void addPokemon(Pokemon& p) {pokemonsCaptured.push_back(p);}
  void showPokemon() {
    for(int i=0; i < pokemonsCaptured.size(); i++){
           pokemonsCaptured[i].printData();
    }
  }
};

#endif