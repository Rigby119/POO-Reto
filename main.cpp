#include <iostream>
#include <stdlib.h>
#include "pokeClasses.h"
#include <string>
using namespace std;

// Number validation function
bool isNumber( string str ) {
   for(int i=0; i<str.length(); i++) {
      if(!isdigit(str[i])) {
         return false;
      }
   }
   return true;
}

int menu() {
  string str;
  int option;
  option=0;
  while (true) {
    cout << "Welcome to the PokeNet!!!\n" << endl << "What would you like to do?" << endl;
    cout << "1) Try to catch a Pokémon" << endl << "2) Register a new species" << endl;
    cout << "3) Exit the program" << endl << ">>> ";
    cin >> str;
    // Number validation
    try {
      if (isNumber(str)) {
        int option=stoi(str);
        // Option validation
        try {
          if (option<=3 && option>=1) {
              return option;
          } else {throw (option);}
        // Error message
        } catch (int myOpt) {
          cout << endl << myOpt << " is not an option, you need to introduce a number between 1 and 3\n" << endl;
        }
      } else {throw (str);}
    // Error message
    } catch (string myOpt) {
      cout << endl << myOpt << " is not a number\n" << endl;
    }
  }
}

void pokeCatcher() {
  cout << endl << "Simulation started";
  cout << endl << "Simulation ended";
}

void pokeRegister() {
  string name, type1, type2;
  float captureRatio;
  char legendary, pseudo;
  cout << endl << "Registration started" << endl;
  cout << "Pokémon's Name: ";
  cin >> name;
  cout << "Pokémon's first type: ";
  cin >> type1;
  cout << "Pokémon's second type (if it doesn't have one, type 'none'): ";
  cin >> type2;
  cout << "What is the capture ratio of the Pokémon?" << endl << ">>> ";
  cin >> captureRatio;
  cout << "Is legendary? (type 'y' or 'n'): ";
  cin >> legendary;
  cout << "Is pseudo? (type 'y' or 'n'): ";
  cin >> pseudo;
  cout << endl << "Registration ended" << endl;
}

int main() {
  int option;
  option = menu();
  switch (option) {
    case 1:
    cout << endl << "Starting the simulation...";
    pokeCatcher();
    break;
    case 2:
    cout << endl << "Starting the registration...";
    pokeRegister();
    break;
    case 3:
    cout << endl << "Goodbye";
    break;
    default:
    cout << endl << "Option not found";
    break;
  }
  Pokeball superBall("Super Ball", 1.5);
  cout << superBall.effectiveness;
}