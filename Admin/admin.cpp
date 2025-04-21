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
    // properties p;
    // p.set_price(1);
    // p.set_status(true);
    // p.set_owner(owner_input->text().toStdString());
    // p.set_location(location_input->text().toStdString());
    // property_set->insert(p);
}


void admin::update_prop() {
}

void admin::delete_prop() {
}
