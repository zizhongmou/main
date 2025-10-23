#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int DrinkChoice, TempChoice, milk, sugar, ice, qty;
    double price, total;

    cout << "******** DRINK MENU ********" << endl;
    cout << "1. Tea       (Hot = RM1.80  | Cold = RM2.10)" << endl;
    cout << "2. Coffee    (Hot = RM2.50  | Cold = RM2.80)" << endl;
    cout << "3. Chocolate (Hot = RM3.00  | Cold = RM3.60)" << endl;
    cout << "" << endl;

    cout << "Pick Your Drink (1-3): ";
    cin >> DrinkChoice;

   
    if (DrinkChoice < 1 || DrinkChoice > 3) {
        cout << "Invalid drink choice! Please restart the program and select 1-3." << endl;
        return 0;  // exit program
    }

    cout << "Pick Temperature: Hot(1) | Cold(2): ";
    cin >> TempChoice;

    
    if (TempChoice != 1 && TempChoice != 2) {
        cout << "Invalid temperature choice! Please enter 1 for Hot or 2 for Cold." << endl;
        return 0;  // exit program
    }

    
    switch (DrinkChoice) {
        case 1: // Tea
            if (TempChoice == 1) price = 1.80;
            else price = 2.10;
            break;
        case 2: // Coffee
            if (TempChoice == 1) price = 2.50;
            else price = 2.80;
            break;
        case 3: // Chocolate
            if (TempChoice == 1) price = 3.00;
            else price = 3.60;
            break;
    }

    
    cout << "How many scoops of milk? (RM0.80 each): ";
    cin >> milk;
    cout << "How many scoops of sugar? (RM0.50 each): ";
    cin >> sugar;
    cout << "How many scoops of ice? (RM0.20 each): ";
    cin >> ice;

    cout << "Enter quantity of purchase: ";
    cin >> qty;

    
    total = (price + (milk * 0.80) + (sugar * 0.50) + (ice * 0.20)) * qty;

    cout << fixed << setprecision(2);
    cout << "\n------------------------------" << endl;
    cout << "Total Payment is: RM " << total << endl;
    cout << "------------------------------" << endl;

    return 0;
}