//
// Created by BoOdy on 19/04/2025.
//

#ifndef ADMIN_H
#define ADMIN_H

#include<iostream>
using namespace std;
class admin {
static const string user_name;
static const string password;

public:
  static void add_prop();
  static void update_prop();
  static void delete_prop();
  admin();
  ~admin();
};



#endif //ADMIN_H
