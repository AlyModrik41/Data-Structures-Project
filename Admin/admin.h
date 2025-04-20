//
// Created by BoOdy on 19/04/2025.
//

#ifndef ADMIN_H
#define ADMIN_H
#include<set>

#include<iostream>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QObject>       // Optional, since most widgets inherit from QObject
#include <QLineEdit>     // Required for QLineEdit
#include <QLabel>        // If you're using QLabel
#include <QDebug>        // If you're printing with qDebug
#include <QPushButton>
#include "properties.h"
#include <QMessageBox>
#include"properties.h"
struct CompareByPrice {
  bool operator()(const properties& a, const properties& b) const {
    return a.get_price() < b.get_price();
  }
};
using namespace std;
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
