#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

class User {
  string name, password;
  bool admin;
public:
  User(string n, string pas, bool ad) {
    name=n;
    password=pas;
    admin=ad;
  }
  string getName() {return name;}
  string getPassword() {return password;}
  bool isAdmin() {return admin;}
};

#endif