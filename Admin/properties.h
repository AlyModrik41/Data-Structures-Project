
#ifndef PROPERTIES_H
#define PROPERTIES_H
#include <iostream>
using namespace std;


class properties {
	int price = 0, area = 0, rooms = 0;
	bool status = false, furniture = false;
	string owner = "";
	string location = "";
public:
	properties();
	properties(int);
	properties(int, int, int, bool, string, string);
	~properties();
	void set_price(int);
	void set_status(bool);
	void set_owner(string);
	void set_location(string);
	void set_area(int);
	void set_rooms(int);
	void set_furniture(bool);

	int get_price() const;
	bool get_status() const;
	string get_owner() const;
	string get_location() const;
	bool get_furniture();
	int get_area();
	int get_rooms();
};

#endif //PROPERTIES_H