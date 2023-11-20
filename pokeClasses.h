#include <string>
using namespace std;

class Pokemon {
  char type1, type2;
  public:
  string name;
  float captureRatio;
  bool shiny, legendary, pseudo;
  Pokemon (char type1Cin, char type2Cin, string nameCin, float captureRatioCin, bool legendaryCin, bool pseudoCin) {
    type1 = type1Cin;
    type2 = type2Cin;
    name = nameCin;
    captureRatio = captureRatioCin;
    legendary = legendaryCin;
    pseudo = pseudoCin;
  }
};

class Pokeball {
  public:
  string type;
  float effectiveness;
  Pokeball (string typeCin, float effectivenessCin) {
    type = typeCin;
    effectiveness = effectivenessCin;
  }
};

class Trainer {
  int pokemonStored, pokemonCaptured, especiesCaptured;
  public:
  string name;
  int pokeballsLeft;
  char gender;
  string capturedEspecies[151];
  Trainer(string nameCin, char genderCin) {
      pokemonStored = 0;
      pokemonCaptured = 0;
      especiesCaptured = 0;
      name = nameCin;
      gender = genderCin;
  }
};