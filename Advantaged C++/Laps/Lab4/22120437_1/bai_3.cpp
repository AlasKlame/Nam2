#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Meal {
    std::string name;
    int price;
};

struct MealCombo {
    std::string comboName;
    std::vector<Meal> meals;
};

int getMealPrice(const std::vector<Meal>& menu, const std::string& mealName) {
    for (const auto& meal : menu) {
        if (meal.name == mealName) {
            return meal.price;
        }
    }
    return 0; 
}

int calculateTotalPrice(const MealCombo& combo) {
    int total = 0;
    for (const auto& meal : combo.meals) {
        total += meal.price;
    }
    return total;
}

int applyDiscount(int totalPrice, float discountRate) {
    return static_cast<int>(totalPrice * (1 - discountRate));
}

void displayCombo(const MealCombo& combo) {
    std::cout << "********** " << combo.comboName << " **********\n";
    for (const auto& meal : combo.meals) {
        std::cout << meal.name << ": " << meal.price << " JPY\n";
    }
    int totalPrice = calculateTotalPrice(combo);
    std::cout << "-------------------------------\n";
    std::cout << "Total price: " << totalPrice << " JPY\n";
    std::cout << "Discounted price: " << applyDiscount(totalPrice, 0.10) << " JPY\n";
}

int main() {
    // Initialize the menu
    std::vector<Meal> menu = {
        {"Burger", 130},
        {"Cheese burger", 150},
        {"Chicken burger", 200},
        {"Drink", 130},
        {"Potato", 120},
        {"Ice cream", 160}
    };

    std::vector<MealCombo> combos = {
        {"A (Burger, Drink, Potato)", {menu[0], menu[3], menu[4]}}, 
        {"B (Cheese burger, Drink, Potato) ", {menu[1], menu[3], menu[4]}}, 
        {"C (Chicken burger, Drink, Potato)", {menu[2], menu[3], menu[4]}},
        {"D (Chicken burger, Drink, Potato, Ice cream)", {menu[2], menu[3], menu[4], menu[5]}} };

    int choice;
    std::cout << "Chon mot trong cac phan an sau:\n";
    for (size_t i = 0; i < combos.size(); ++i) {
        std::cout << (i + 1) << ": " << combos[i].comboName << "\n";
    }
    std::cin >> choice;

    if (choice < 1 || choice > static_cast<int>(combos.size())) {
        std::cerr << "Chon lai\n";
        return 1;
    }

    displayCombo(combos[choice - 1]);

    return 0;
}
