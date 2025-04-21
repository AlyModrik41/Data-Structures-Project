//
// Created by BoOdy on 19/04/2025.
//

#ifndef ADMIN_H
#define ADMIN_H
#include<set>

#include<iostream>
#include <QApplication>
#include <QObject>       // Optional, since most widgets inherit from QObject
#include <QDebug>        // If you're printing with qDebug
#include "properties.h"
struct CompareByPrice {
  bool operator()(const properties& a, const properties& b) const {
    return a.get_price() < b.get_price();
  }
};

class admin {
  static const string username;
  static const string password;

public:
  static void add_prop(multiset<properties, CompareByPrice> *,QWidget*);
  static void update_prop();
  static void delete_prop();
  admin();
  ~admin();
};




#endif //ADMIN_H
