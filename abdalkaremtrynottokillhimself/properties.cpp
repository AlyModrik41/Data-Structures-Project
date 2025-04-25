
#include "properties.h"
#include<string>
properties::properties():price(0),status(false),owner("company"){

}

properties::properties(int price):price(price),status(false),owner("company"){

}

properties::~properties() {
}

void properties::set_price(int price) {
    this->price=price;
}

void properties::set_status(bool status)
{
    this->status=status;
}

void properties::set_owner(string owner) {
    this->owner=owner;
}

void properties::set_location(string location) {
    this->location=location;
}

int properties::get_price() const{
    return price;
}

bool properties::get_status() const {
    return status;
}

string properties::get_owner() const{
    return owner;
}
string properties::get_location() const{
    return location;
}

int properties::next_owner_id = 0;
int properties::next_property_id = 0;

void properties::set_owner_id(int id) { owner_id = id; }
void properties::set_property_id(int id) { property_id = id; }
int properties::get_owner_id() const {
    return owner_id;
}
int properties::get_property_id() const { return property_id; }
