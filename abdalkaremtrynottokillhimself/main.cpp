#include "admin.h"
#include "properties.h"
#include <iostream>
#include <set>
#include <limits>
using namespace std;

bool compareByPrice(const properties& a, const properties& b) {
    return a.get_price() < b.get_price();
}

void printAllProperties(const multiset<properties, bool(*)(const properties&, const properties&)>& props) {
    cout << "\n=== ALL PROPERTIES ===" << endl;
    for (const auto& p : props) {
        cout << "Owner ID: " << p.get_owner_id()
             << " | Prop ID: " << p.get_property_id()
             << " | Location: " << p.get_location()
             << " | Price: " << p.get_price()
             << " | Owner: " << p.get_owner()
             << " | Status: " << (p.get_status() ? "Available" : "Sold")
             << endl;
    }
    cout << "=====================\n" << endl;
}

int main() {
    multiset<properties, bool(*)(const properties&, const properties&)>
        propertiesSet(compareByPrice);

    int choice;
    do {
        cout << "\nReal Estate Management System\n";
        cout << "1. Add Property\n";
        cout << "2. Update Property\n";
        cout << "3. Delete Property\n";
        cout << "4. List All Properties\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                admin::add_prop(propertiesSet);
                break;
            case 2:
                admin::update_prop(propertiesSet);
                break;
            case 3:
                admin::delete_prop(propertiesSet);
                break;
            case 4:
                printAllProperties(propertiesSet);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (choice != 5);

    return 0;
}