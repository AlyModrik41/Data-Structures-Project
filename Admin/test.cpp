#include<set>
#include "admin.h"
#include "properties.h"

bool compare(const properties& a,const properties& b) {
    return a.get_price() < b.get_price();
}
void showAdminMenu() {
    std::cout << "========================================\n";
    std::cout << "         🏠 Property Admin Panel         \n";
    std::cout << "========================================\n";
    std::cout << "Please choose an action from the list below:\n\n";

    std::cout << "  [1] ➕ Add New Property\n";
    std::cout << "  [2] ✏️  Edit Existing Property\n";
    std::cout << "  [3] ❌ Delete Property\n";
    std::cout << "  [4] 📋 Show All Properties\n";
    std::cout << "  [0] 🚪 Logout / Exit\n";
}
int main(int argc, char *argv[]) {
    //multi set that saves the properties sorted using pointer function
    multiset<properties,bool(*)(const properties& a,const  properties& b)> property_set(compare);
    char n;
    while (true) {
        showAdminMenu();
        cin>>n;
        if (!(n>='0'&&n<='3')) {
            cout<<"Invalid input please try again"<<endl;
        }else{
            switch (n) {
                case '1':admin::add_prop(property_set);
                break;
                case '2':admin::update_prop();
                break;
                case '3':admin::delete_prop();
                break;
            }
            break;
        }
    }
    for (properties p :property_set) {
        std::cout << "========================================\n";
        std::cout << "Price   : " << p.get_price() << "$\n";
        std::cout << "Location: " << p.get_location() << "\n";
        std::cout << "Owner   : " << p.get_owner() << "\n";
        std::cout << "========================================\n";
    }
    return 0;
}

