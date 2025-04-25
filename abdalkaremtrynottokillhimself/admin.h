//
// Created by Abd Elkarem on 4/25/2025.
//


#ifndef ADMIN_H
#define ADMIN_H
#include<set>
#include<iostream>
#include "properties.h"
#include<vector>
using namespace std;
class admin {
    static const string username;
    static const string password;

public:
    static void add_prop(multiset<properties,bool(*)(const properties& a,const  properties& b)>&);
    static void update_prop(multiset<properties, bool(*)(const properties&, const properties&)>& property_set);
    static void delete_prop(multiset<properties,bool(*)(const properties& a,const  properties& b)>&);
    admin();
    ~admin();
    static vector<properties> get_owner_properties(int owner_id, const multiset<properties, bool(*)(const properties&, const properties&)>& property_set);
};




#endif //ADMIN_H

