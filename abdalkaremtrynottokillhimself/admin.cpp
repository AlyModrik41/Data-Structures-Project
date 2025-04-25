//
// Created by Abd Elkarem on 4/25/2025.
//

#include "admin.h"

#include "admin.h"
#include "properties.h"
#include <iostream>
#include<vector>
const string admin::username = "admin";
const string admin::password = "password";
admin::admin() {

}

admin::~admin() {
}


vector<properties> admin::get_owner_properties(    int owner_id, const multiset<properties, bool(*)(const properties&, const properties&)>& property_set)
{
    vector<properties> owner_props;
    for (const auto& prop : property_set) {
        if (prop.get_owner_id() == owner_id) {
            owner_props.push_back(prop);
        }
    }
    return owner_props;
}


void admin::add_prop(multiset<properties,bool(*)(const properties& a,const  properties& b)>&property_set) {
    int price;
    string location,owner;
    properties p;
    p.set_owner_id(properties::next_owner_id);
    p.set_property_id(properties::next_property_id);
    properties::next_owner_id++;
    properties::next_property_id++;

    p.set_status(true);
    while (true) {
        cout << "Enter property price: "<<endl;
        cin >> price;
        cout << "Enter property location: "<<endl;
        cin>>location;
        cout << "Enter owner's name: "<<endl;
        cin>>owner;
        if (owner==""||price<=0||location=="") {
            cout<<"please fill all inputs"<<endl;
        }else {
            break;
        }
    }
    cout << "\n✅ Property added successfully!\n";
    p.set_price(price);
    p.set_location(location);
    p.set_owner(owner);
    property_set.insert(p);
}


void admin::update_prop(multiset<properties, bool(*)(const properties&, const properties&)>& property_set)
{
  int owner_id;
cout << "enter owner id: "<<endl;
cin>>owner_id;
 vector<properties> owner_props = admin::get_owner_properties(owner_id, property_set);
  if (owner_props.empty())
 {
        cout << "No properties found for owner ID " << owner_id << endl;
        return;
    }
    cout << "Properties for owner ID " << owner_id << endl;
    for (size_t i = 0; i < owner_props.size(); i++)
    {
        cout << "[" << i << "] Location: " << owner_props[i].get_location()
             << " Price: " << owner_props[i].get_price() << endl;
    }

     int choice;
    cout << "Enter the index of the property to update: ";
    cin >> choice;
    if (choice < 0 || choice >= owner_props.size()) {
        cout << "Invalid index." << endl;
        return;
    }
    properties selected_prop = owner_props[choice];
    cout << "Choose field to update:\n"
         << "1. Price\n"
         << "2. Location\n"
         << "3. Status\n"
         << "Enter your choice: ";
    int field_choice;
    cin >> field_choice;
    if (field_choice < 1 || field_choice > 3) {
        cout << "Invalid choice." << endl;
        return;
    }
     switch (field_choice)
    {
        case 1: {
            int new_price;
            cout << "Enter new price: ";
            cin >> new_price;
            if (new_price <= 0)
            {
                cout << "Price must be positive." << endl;
                return;
            }
            selected_prop.set_price(new_price);
            break;
        }
        case 2: {
            string new_location;
            cout << "Enter new location: ";
            cin.ignore();
            getline(cin, new_location);
            if (new_location.empty()) {
                cout << "Location cannot be empty." << endl;
                return;
            }
            selected_prop.set_location(new_location);
            break;
        }
        case 3: {
            bool new_status;
            cout << "Enter new status (1 for available, 0 for sold): ";
            cin >> new_status;
            selected_prop.set_status(new_status);
            break;
        }
    }
     bool updated = false;
    auto it = property_set.begin();
    while (it != property_set.end())
    {
        if (it->get_owner_id() == owner_id &&
            it->get_property_id() == selected_prop.get_property_id()) {
            it = property_set.erase(it);
            property_set.insert(selected_prop);
            updated = true;
            break;
        } else {
            ++it;
        }
    }
    if (updated) {
        cout << "Property updated successfully!" << endl;
    } else {
        cout << "Update failed (property not found)." << endl;
    }

}

void admin::delete_prop(multiset<properties, bool(*)(const properties&, const properties&)>& property_set)
{
   int whantedownerid ;
   cout << "Enter owner ID to delete a property:";
   cin>>whantedownerid;
   vector<properties> ownerprop =  get_owner_properties(whantedownerid, property_set);
   if ( ownerprop.empty())
   {
        cout << " No properties found for owner ID " <<  whantedownerid << endl;
        return;
    }
    cout << "Properties for owner ID " << whantedownerid << endl;
    for (size_t i = 0; i < ownerprop.size(); i++) {
        cout << "[" << i << "] Location: " << ownerprop[i].get_location()
             << "Price: " << ownerprop[i].get_price() << endl;
    }
    int choice;
    cout << "Enter the index of the property to delete:" <<endl;
    cin >> choice;
    if (choice < 0 || choice >= ownerprop.size()) {
        cout << " Invalid index"<<endl;
        return;
    }
       bool deleted = false;
    auto it = property_set.begin();
    while (it != property_set.end())
      {
        if (it->get_owner_id() ==  whantedownerid && it->get_property_id() == ownerprop[choice].get_property_id())
          {
           it = property_set.erase(it);
            deleted = true;
             break;
          }
          else
        {
          ++it;
        }

      }
      if (deleted) {
        cout << " Property deleted successfully!"<<endl;
    } else
     {
        cout << "Deletion failed (property not found)"<<endl;
    }
}
