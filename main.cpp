// Estas son librerias que usamos para la funcionalidad del programa
#include <iostream> //Mostrar datos en la consola y pedirlos en la misma
#include <stdlib.h> //Funciones cómo rand()
#include <string> //Uso de variables tipo string
// Estos son los archivos .h en donde están guardadas todas las clases
#include "User.h"
#include "Admin.h"
#include "Trainer.h"
#include "Pokemon.h"
#include "Pokedex.h"
// En este archivo se guardan los metodos que guardan los datos base para el programa
#include "PokeStarter.h"
#include "methods.h"

using namespace std; // std::cout >>>> cout

// Estos vectores guardan información para el juego y por eso se crean al principio y fuera del main
vector<User> users; // Usuarios en general
vector<Admin> admins; // Solo admins
vector<Trainer> trainers; // Solo trainers

// Menu que es desplegado a los usuarios de tipo Trainer
int trainerMenu() {
  string str;
  int option;
  option=0;
  while (true) {
    cout << endl << "Welcome to the PokeNet!!!\n" << endl << "What would you like to do?" << endl;
    cout << "1) Try to catch a Pokémon" << endl << "2) Enter the PokeStore" << endl << "3) Exit the program" << endl << ">>> ";
    cin >> str;
    // Number validation
    try {
      if (isNumber(str)) {
        int option=stoi(str);
        // Option validation
        try {
          if (option>=1 && option<=3) {
              return option;
          } else {throw (option);}
        // Error message
        } catch (int myOpt) {
          cout << endl << myOpt << " is not an option, you need to introduce 1 or 2\n" << endl;
        }
      } else {throw (str);}
    // Error message
    } catch (string myOpt) {
      cout << endl << myOpt << " is not an integer\n" << endl;
    }
  }
}

// Menu que es desplegado a los usuarios de tipo Admin
int adminMenu() {
  string str;
  int option;
  option=0;
  while (true) {
    cout << endl << "Welcome to the PokeNet!!!\n" << endl << "What would you like to do?" << endl;
    cout << "1) Delete a trainer" << endl << "2) Register a pokemon" << endl << "3) Exit the program" << endl << ">>> ";
    cin >> str;
    // Number validation
    try {
      if (isNumber(str)) {
        int option=stoi(str);
        // Option validation
        try {
          if (option>=1 && option<=3) {
              return option;
          } else {throw (option);}
        // Error message
        } catch (int myOpt) {
          cout << endl << myOpt << " is not an option, you need to introduce 1 or 2\n" << endl;
        }
      } else {throw (str);}
    // Error message
    } catch (string myOpt) {
      cout << endl << myOpt << " is not an integer\n" << endl;
    }
  }
}

// Ejecucion del pokeCatcher
void pokeCatcher(Trainer& trainer, Pokedex& pokedex) {
  vector<Pokemon> vec;
  int ind, pokeballsLeft, money;
  float capRat, randomFloat;
  string name, option;
  vec=pokedex.getPokemons();
  ind = rand() % vec.size();
  Pokemon wildPokemon = vec[ind];
  wildPokemon.printData();
  capRat = wildPokemon.getCaptureRatio();
  name = wildPokemon.getName();
  money = trainer.getMoney();
  pokeballsLeft = trainer.getPokeballsLeft();
  while (1==1){
    cout << endl << "You have " << pokeballsLeft << " pokeballs left" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1) Use a PokeBall" << endl << "2) Run" << endl << ">>> ";
    cin >> option;
    if (option=="1") {
      if (pokeballsLeft>0) {
        randomFloat = rand() % 100;
        randomFloat = randomFloat/100.0;
        if (randomFloat<=capRat) {
          cout << endl << "You caught " << name << "!" << endl;
          trainer.setMoney(money+500);
          trainer.addPokemon(wildPokemon);
          pokeballsLeft-=1;
          trainer.setPokeballsLeft(pokeballsLeft);
          break;
        }
        else {
          cout << endl << "You failed to catch " << name << "..." << endl;
          pokeballsLeft-=1;
        }
      }
    }
    else if (option=="2") {
      cout << endl << "You ran away from " << name << "..." << endl;
      break;
    }
    else {
      cout << endl << "Invalid option, please introduce 1 or 2\n" << endl;
    }
  }
}

// Ejecucion del pokeRegister
void pokeRegister(Pokedex& pokedex) {
  string name, type1, type2, captureRatioI;
  float captureRatio;
  cout << endl << "Pokémon's Name: ";
  cin >> name;
  cout << endl << "Pokémon's first type: ";
  cin >> type1;
  cout << endl << "Pokémon's second type (if it doesn't have one, type 'none'): ";
  cin >> type2;
  cout << endl << "Pokémon's capture ratio: ";
  cin >> captureRatioI;
  if(isFloat(captureRatioI)) {captureRatio = stof(captureRatioI);}
  else {captureRatio=0.0;}
  Pokemon newPokemon(name, type1, type2, captureRatio);
  cout << endl << name << " registered succesfully" << endl;
  newPokemon.printData();
  pokedex.addPokemon(newPokemon);
}

// Ejecucion del pokeStore
void pokeStore(Trainer& trainer) {
  int pokeballsLeft = trainer.getPokeballsLeft();
  int money = trainer.getMoney(); 
  string str, ask;
  cout << endl << "You have " << pokeballsLeft << " PokeBalls left and $" << money << endl;
  while (1==1){
    cout << "Would you like to buy more PokeBalls?" << endl;
    cout << "1) Yes" << endl << "2) No" << endl << ">>> ";
    cin >> str;
    if (isNumber(str)) {
      if (stoi(str)==1) {
        if (money>=200) {
          while (1==1) {
            cout << endl << "How many PokeBalls would you like to buy? (each one costs 200 PokeDollars)" << endl << ">>> ";
            cin >> ask;
            if (isNumber(ask)) {
              int quantity = stoi(ask);
              if (quantity>0) {
                if (money>=quantity*200) {
                  trainer.setPokeballsLeft(pokeballsLeft+quantity);
                  trainer.setMoney(money-quantity*200);
                  cout << endl << "You have bought " << quantity << " PokeBalls" << endl;
                  cout << "You have $" << trainer.getMoney() << " left" << endl;
                  cout << "You have " << trainer.getPokeballsLeft() << " PokeBalls left" << endl;
                  break;
                } else {cout << endl <<  "Insufficent money" << endl;}
              } else {cout << endl <<  "Please introduce a number greater than 0" << endl;}
            } else {cout << endl <<  "Please introduce a number" << endl;}
          } 
          break;
        } else {cout << endl <<  "Insufficent money" << endl;}
      } 
      else if (stoi(str)==2) {
        cout << endl << "Ok, thank you for shopping with us" << endl;
        break;
      }
      else {
        cout << endl << "Please introduce numbers 1 or 2" << endl;
      }
    }
    else {
      cout << endl << "Please introduce a number" << endl;
    }
  }
}

// Verifica si el usuario está registrado
bool isRegistered(string username, string pas) {
  for(int i=0; i < users.size(); i++){
    if (users[i].getName()==username && users[i].getPassword()==pas) {return true;}
  }
  return false;
}

// Menu de inicio de sesion o registro
int logging(bool& isAd) {
  string opt;
  cout << "Welcome to the PokeNet!" << endl;
  while (true) {
    cout << endl << "What would you like to do?" << endl;
    cout << "1) Log in" << endl << "2) Register" << endl << ">>> ";
    cin >> opt;
    if (opt=="1") {
      string username, password;
      cout << endl << "Username: ";
      cin >> username;
      cout << endl << "Password: ";
      cin >> password;
      if (isRegistered(username, password)) {
        for(int i=0; i < admins.size(); i++){
          if (admins[i].getName()==username) {
            isAd = true;
            return i;
          }
        }
        for(int i=0; i < trainers.size(); i++){
          if (trainers[i].getName()==username) {
            isAd = false;
            return i;
          }
        }
      } else {
        cout << endl << "Your name or password are not registered, please register first" << endl;
      }
    } else if (opt=="2") {
      string username, password, adminS;
      cout << endl << "Username: ";
      cin >> username;
      cout << endl << "Password: ";
      cin >> password;
      cout << endl << "Are you an admin? (y/n): ";
      cin >> adminS;
      if (adminS=="y") {
        isAd=true;
        Admin newUser(username, password, true);
        admins.push_back(newUser);
        users.push_back(newUser);
        cout << endl << "You have been registered, welcome " << username << endl;
        return admins.size()-1;
      } else {
        isAd=false;
        Trainer newUser(username, password, false);
        trainers.push_back(newUser);
        users.push_back(newUser);
        cout << endl << "You have been registered, welcome " << username << endl;
        return trainers.size()-1;
      }
    } else {
      cout << endl << "Please introduce a number 1 or 2" << endl;
    }
  }
}

int main() {
  initliazeUsers();
  bool ciclo = true;
  while (ciclo){
    int option, ind;
    string name, exit, password, nameS;
    bool isAd;
    ind = logging(isAd);
    if (isAd) {
      Pokedex pokedex;
      initializePokedex(pokedex);
      Admin& admin = admins[ind];
      while(true) {
        option = adminMenu();
        switch (option) {
          case 1:
            // Delete trainer
            cout << endl << "Introduce the name of the trainer you want to delete: ";
            cin >> nameS;
            bool registered;
            for(int i=0; i < users.size(); i++){
              if (users[i].getName()==nameS) {
                registered = true;
              } else {
                registered = false;
              }
            }
            if (registered) {
              admin.deleteTrainer(nameS, users, trainers);
              cout << endl << "Trainer " << nameS << " deleted" << endl;
            } else {
              cout << endl << "Trainer not found" << endl;
            }
            break;
          case 2:
            // Register Pokemon
            pokeRegister(pokedex);
            break;
          case 3:
            cout << endl << "See you later!" << endl;
            return 0;
          default:
            cout << endl << "Option not found"<< endl;
            break;
        }
        cout << endl << "Do you want to continue? (type 'y' or 'n')" << endl << ">>> ";
        cin >> exit;
        if(exit=="y") {continue;}
        else {break;}
        option=0;
      }
    } else {
      Trainer& trainer = trainers[ind];
      cout << endl << "Welcome " << trainer.getName() << ", you have " << trainer.getPokeballsLeft() << " pokeballs and " << trainer.getMoney() << " PokeDollars";
      Pokedex pokedex;
      initializePokedex(pokedex);
      while(true) {
        option = trainerMenu();
        switch (option) {
          case 1:
            cout << endl << "A wild pokemon has appeared!!!"<< endl;
            pokeCatcher(trainer, pokedex);
            break;
          case 2:
            cout << endl << "Welcome to the PokeStore!!!" << endl;
            pokeStore(trainer);
            break;
          case 3:
            cout << endl << "See you later!" << endl;
            return 0;
          default:
            cout << endl << "Option not found"<< endl;
            break;
        }
        cout << endl << "Do you want to continue? (type 'y' or 'n')" << endl << ">>> ";
        cin >> exit;
        if(exit=="y") {continue;}
        else {break;}
        option=0;
      }
      cout << endl << "Here is the list of the pokemon you caught" << endl;
      trainer.showPokemon();
      cout << endl << "Logging out...";
    }
  }
  cout << endl;
}