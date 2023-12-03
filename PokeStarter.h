#include "Pokedex.h"
#include "Pokemon.h"

void initializePokedex(Pokedex& pokedex) {
  Pokemon bulbasaur("Bulbasaur", "Plant", "Poison", 0.0);
  Pokemon charmander("Charmander", "Fire", "none", 0.0);
  Pokemon squirtle("Squirtle", "Water", "none", 0.0);
  Pokemon pikachu("Pikachu", "Electric", "none", 0.0);
  Pokemon eevee("Eevee", "Normal", "none", 0.0);
  
  vector<Pokemon> pokemonsInit;
  pokemonsInit.push_back(bulbasaur);
  pokemonsInit.push_back(charmander);
  pokemonsInit.push_back(squirtle);
  pokemonsInit.push_back(pikachu);
  pokemonsInit.push_back(eevee);
  
  for(int i=0; i < pokemonsInit.size(); i++){
    float randomFloat = rand() % 51 + 50;
    randomFloat = randomFloat/100.0;
    pokemonsInit[i].setCapRat(randomFloat);
    pokedex.addPokemon(pokemonsInit[i]);
  }
}

//
void initliazeUsers() {
  Admin user1("Pedro", "gato1", true);
  Trainer user2("Maria", "gato2", false);
  admins.push_back(user1);
  trainers.push_back(user2);
  users.push_back(user1);
  users.push_back(user2);
}