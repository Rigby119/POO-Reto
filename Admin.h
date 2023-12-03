#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Trainer.h"

class Admin : public User {
  public:
  Admin(string n, string pas, bool ad) : User(n, pas, ad) {}
  void deleteTrainer(string nameS, vector<User>& users, vector<Trainer>& trainers) {
    for(int i=0; i < users.size(); i++){
      if (users[i].getName()==nameS) {
        users.erase(users.begin()+i);
      }
    }
    for(int i=0; i < trainers.size(); i++){
      if (trainers[i].getName()==nameS) {
          trainers.erase(trainers.begin()+i);
      }
    }
  }
};

#endif