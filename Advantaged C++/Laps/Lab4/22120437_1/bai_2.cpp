#include <iostream>
#include <string>

struct Meal {
    std::string name;
    int price;
};

struct MealCombo {
    std::string comboName;
    Meal meals[4]; 
};

int getMealPrice(const Meal* menu, int menuSize, const std::string& mealName) {
    for (int i = 0; i < menuSize; ++i) {
        if (menu[i].name == mealName) {
            return menu[i].price;
        }
    }
    return 0; 
}


int calculateTotalPrice(const MealCombo& combo) {
    int total = 0;
    for (int i = 0; i < 4; ++i) {
        total += combo.meals[i].price;
    }
    return total;
}

int applyDiscount(int totalPrice, float discountRate) {
    return static_cast<int>(totalPrice * (1 - discountRate));
}

void displayCombo(const MealCombo& combo) {
    std::cout << "********** " << combo.comboName << " **********\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << combo.meals[i].name << ": " << combo.meals[i].price << " JPY\n";
    }
    int totalPrice = calculateTotalPrice(combo);
    std::cout << "-------------------------------\n";
    std::cout << "Total price: " << totalPrice << " JPY\n";
    std::cout << "Discounted price: " << applyDiscount(totalPrice, 0.10) << " JPY\n";
}

int main() {
    // Initialize the menu
    Meal menu[] = {
        {"Burger", 130},
        {"Cheese burger", 150},
        {"Chicken burger", 200},
        {"Drink", 130},
        {"Potato", 120},
        {"Ice cream", 160}
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    // Initialize the combos
    MealCombo combos[] = {
        {"A (Burger, Drink, Potato)", {menu[0], menu[3], menu[4]}}, 
        {"B (Cheese burger, Drink, Potato)", {menu[1], menu[3], menu[4]}}, 
        {"C (Chicken burger, Drink, Potato)", {menu[2], menu[3], menu[4]}}, 
        {"D (Chicken burger, Drink, Potato)", {menu[2], menu[3], menu[4], menu[5]}}
    };
    int combosSize = sizeof(combos) / sizeof(combos[0]);

    int choice;
    std::cout << "Chon 1 trong cac phan an sau:\n";
    if(choice == 4){
        for(int i = 0; i <= 3; i++){
            std::cout << i + 1 << ". " << combos[i].comboName << std::endl;
        }
    }
    else{
        for (int i = 0; i < combosSize; ++i) {
        std::cout << (i + 1) << ": " << combos[i].comboName << "\n";
    }
    }
    std::cin >> choice;

    if (choice < 1 || choice > combosSize) {
        std::cerr << "Chon lai\n";
        return 1;
    }

    // Display the chosen combo
    displayCombo(combos[choice - 1]);

    return 0;
}
