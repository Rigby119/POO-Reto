#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pokemon {
  string nombre, type1, type2;
  float captureRatio;
public:
  Pokemon(string n, string t1, string t2, float c) {
    nombre = n;
    type1 = t1;
    type2 = t2;
    captureRatio = c;
  }
  void printData() {
    cout << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo 1: " << type1 << endl;
    cout << "Tipo 2: " << type2 << endl;
  }
  void setCapRat(float c) {captureRatio = c;}
  float getCaptureRatio() {return captureRatio;}
  string getName() {return nombre;}
};

#endif