#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

struct PizzaOrder {
    string size;
    string toppings;
    double totalPrice;
};

double currentCredit = 0;
PizzaOrder recentOrder;

char mainMenu() {
    cout << "" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "                 UCLAN PIZZA                " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "                  Main Menu                 " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "   1. Add Credit                            " << endl;
    cout << "   2. Order pizza                           " << endl;
    cout << "   3. View Recent Order                     " << endl;
    cout << "   4. Exit                                  " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Current Credit: $" << fixed << setprecision(2) << currentCredit << endl;
    cout << "" << endl;

    return ' ';
}

char displayMenu() {
    int menuNo;
    cout << "Enter a number to select the menu: ";
    cin >> menuNo;

    while (cin.fail() || !(menuNo >= 1 && menuNo <= 4)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid menu number (1-4): ";
        cin >> menuNo;
    }

    return static_cast<char>('0' + menuNo);
}

char displaySizesAndToppings() {
    cout << "" << endl;
    cout << "______________________________________" << endl;
    cout << "            PIZZA SIZES               " << endl;

    cout << "  Number    |    Size    |    Price   " << endl;
    cout << "____________|____________|____________" << endl;
    cout << "   1        |   Small    |    5.00    " << endl;
    cout << "   2        |   Medium   |    8.50    " << endl;
    cout << "   3        |   Large    |    10.25   " << endl;
    cout << "            |            |            " << endl;

    cout << "________________________________________   " << endl;
    cout << "                 TOPPINGS                  " << endl;
    cout << "                                           " << endl;
    cout << "   Number   |     Toppings  |    Cost      " << endl;
    cout << " ___________|_______________|___________   " << endl;
    cout << "     1      |    Ham        |    0.80      " << endl;
    cout << "     2      | Mushrooms     |    0.50      " << endl;
    cout << "     3      |  Pepperoni    |    1.00      " << endl;
    cout << "     4      |   Peppers     |    0.80      " << endl;
    cout << "     5      |   Onions      |    0.40      " << endl;
    cout << "     6      |Extra Cheese   |    1.50      " << endl;
    cout << "            |               |              " << endl;
    cout << "" << endl;

    return ' ';
}

char addCredits() {
    double amount;
    cout << "Enter the amount to add: $";
    cin >> amount;

    while (cin.fail() || amount <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid positive amount: $";
        cin >> amount;
    }

    currentCredit += amount;
    cout << "Credit added successfully. Current Credit: $" << fixed << setprecision(2) << currentCredit << endl;

    return ' ';
}

char orderPizza() {
    displaySizesAndToppings();

    int sizeChoice;
    cout << "Enter the number corresponding to the desired size: ";
    cin >> sizeChoice;

    PizzaOrder newOrder;
    switch (sizeChoice) {
    case 1:
        newOrder.size = "Small";
        newOrder.totalPrice = 5.0;
        break;
    case 2:
        newOrder.size = "Medium";
        newOrder.totalPrice = 8.50;
        break;
    case 3:
        newOrder.size = "Large";
        newOrder.totalPrice = 10.25;
        break;
    default:
        cout << "Invalid size selection." << endl;
        return ' ';
    }

    char addTopping;
    do {
        cout << "Do you want to add a topping? (y/n): ";
        cin >> addTopping;
        while (!(addTopping == 'y' || addTopping == 'n')) {
            cout << "Please enter a valid character: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> addTopping;
        }

        if (addTopping == 'y' || addTopping == 'Y') {
            int toppingChoice;
            cout << "Enter the number corresponding to the desired topping: ";
            cin >> toppingChoice;

            switch (toppingChoice) {
            case 1:
                newOrder.toppings += "Ham ";
                newOrder.totalPrice += 0.80;
                break;
            case 2:
                newOrder.toppings += "Mushrooms ";
                newOrder.totalPrice += 0.50;
                break;
            case 3:
                newOrder.toppings += "Pepperoni ";
                newOrder.totalPrice += 1.0;
                break;
            case 4:
                newOrder.toppings += "Peppers ";
                newOrder.totalPrice += 0.80;
                break;
            case 5:
                newOrder.toppings += "Onions ";
                newOrder.totalPrice += 0.40;
                break;
            case 6:
                newOrder.toppings += "Extra Cheese ";
                newOrder.totalPrice += 1.50;
                break;
            default:
                cout << "Invalid topping selection." << endl;
            }
        }
    } while (addTopping == 'y' || addTopping == 'Y');

    if (currentCredit >= newOrder.totalPrice) {
        currentCredit -= newOrder.totalPrice;
        recentOrder = newOrder;

        cout << "Pizza ordered successfully." << endl;

        // Output the available balance and the details of the order
        cout << "Available Balance: $" << fixed << setprecision(2) << currentCredit << endl;
        cout << "Pizza price: $" << fixed << setprecision(2) << recentOrder.totalPrice << endl;
        cout << "----------------------------------------" << endl;
        cout << "Your new Balance = $" << fixed << setprecision(2) << currentCredit << endl;
        cout << "----------------------------------------" << endl;

        char orderAnother;
        cout << "Would you like to order another pizza? (Y/N): ";
        cin >> orderAnother;

        if (orderAnother == 'N' || orderAnother == 'n') {
            cout << "Thank you, goodbye!" << endl;
            return ' ';
        }
    }
    else {
        cout << "You have insufficient credits available. You require $" << fixed << setprecision(2) << newOrder.totalPrice << " credits." << endl;

        char addMoreCredits;
        cout << "Would you like to add more credits? (Y/N): ";
        cin >> addMoreCredits;

        if (addMoreCredits == 'Y' || addMoreCredits == 'y') {
            addCredits();
        }
        else {
            cout << "Thank you, goodbye!" << endl;
            return ' ';
        }
    }

    return ' ';
}

char viewRecentOrder() {
    cout << "" << endl;
    cout << "_____" << endl;
    cout << "            RECENT ORDER DETAILS           " << endl;
    cout << "_____" << endl;
    cout << "Pizza Size:                                " << recentOrder.size << endl;
    cout << "Toppings:                                  " << recentOrder.toppings << endl;
    cout << "Total Price: $                             " << fixed << setprecision(2) << recentOrder.totalPrice << endl;
    cout << "_____" << endl;
    cout << "" << endl;

    return ' ';
}

int main() {
    while (true) {
        mainMenu();
        char choice = displayMenu();

        switch (choice) {
        case '1':
            addCredits();
            break;
        case '2':
            orderPizza();
            break;
        case '3':
            viewRecentOrder();
            break;
        case '4':
            cout << "Exiting UCLAN Pizza. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    }

    return 0;
}
