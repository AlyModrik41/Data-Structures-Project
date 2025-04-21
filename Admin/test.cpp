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
    multiset<properties,bool(*)(const properties& a,const  properties& b)> properties_set(compare);
    showAdminMenu();
    char n;
    cin>>n;
    switch (n) {
        case 1:admin::add_prop(properties_set);
                break;
        case 2:admin::update_prop();
                break;
        case 3:admin::delete_prop();
                break;
    }
    return 0;
}

