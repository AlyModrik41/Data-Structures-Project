//
// Created by BoOdy on 19/04/2025.
//

#include "admin.h"
#include "properties.h"


admin::admin() {

}

admin::~admin() {
}

void admin::add_prop(multiset<properties,bool(*)(const properties& a,const  properties& b)>&property_set) {
    int price;
    string location,owner;
    properties p;
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
<<<<<<< HEAD
    std::cout << "\n✅ Property added successfully!\n";
=======
    cout << "\n✅ Property added successfully!\n";
>>>>>>> c66f8c4f5822efc321fcb45a977e35a2e861a840
    p.set_price(price);
    p.set_location(location);
    p.set_owner(owner);
    property_set.insert(p);
}


void admin::update_prop() {
}

void admin::delete_prop() {
}
