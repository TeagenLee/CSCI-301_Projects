// Tests and demenstrates the shopping class working and using both the item and bag classes to do so.
// dj5172pl Teagen Lee
// 9/22/2025
// Dr. Jie Hu Meichsner

#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ShoppingCart cart;

    cout << "Welcome to XXX SHOPPING CENTER." << endl;
    cout << "Enter the item you selected as the following order:" << endl;
    cout << "name unitPrice quantity" << endl;
    cout << "(Name can not contain any space. Otherwise errors happen!)" << endl;

    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        item newItem;
        cin >> newItem;
        cart.add(newItem);
        cout << "Want to continue y/n-->";
        cin >> cont;
    }

    auto printCart = [&](const ShoppingCart& c) {
        cout << "Here is your order:" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << left << setw(15) << "Name"
        << right << setw(12) << "Unit_Price"
        << setw(12) << "Quantity" << endl;


        for (auto& it : cart.toVector()) {
            cout << left << setw(15) << it.getName()
            << right << setw(12) << fixed << setprecision(2) << it.getUnitPrice()
            << setw(12) << it.getQuantity() << endl;
}

        cout << "The total charge is $" << fixed << setprecision(2)
             << c.getTotalPrice() << endl;
        cout << "-------------------------------------------------" << endl;
    };

    printCart(cart);

    cout << "Want to modify your order? y/n-->";
    cin >> cont;
    while (cont == 'y' || cont == 'Y') {
        cout << "What do you want? Enter 1: add 2: remove 3: change quantity" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) { // add
            cout << "Enter the item to add as the following order:" << endl;
            cout << "name unitPrice quantity" << endl;
            item addItem;
            cin >> addItem;
            if (cart.add(addItem))
                cout << "The item has been added." << endl;
            else
                cout << "Cart is full. Could not add item." << endl;
        }
        else if (choice == 2) { // remove
            cout << "Enter the item to remove as the following order:" << endl;
            cout << "name unitPrice quantity" << endl;
            item remItem;
            cin >> remItem;
            if (cart.remove(remItem))
                cout << "The item has been removed." << endl;
            else
                cout << "No such item in your shopping cart!" << endl;
        }
        else if (choice == 3) { // change quantity
            cout << "Enter the item to change as the following order:" << endl;
            cout << "name unitPrice quantity" << endl;
            item modItem;
            cin >> modItem;

            if (!cart.contains(modItem)) {
                cout << "No such item in your shopping cart!" << endl;
            } else {
                int newQ;
                cout << "Enter a new quantity --> ";
                cin >> newQ;
                while (newQ < 0) {
                    cout << newQ << " is not a valid input." << endl;
                    cout << "Enter a new quantity --> ";
                    cin >> newQ;
                }

                // remove old one, add new one with updated qty
                cart.remove(modItem);
                modItem.setQuantity(newQ);
                cart.add(modItem);

                cout << "The quantity has been modified." << endl;;
            }
        }

        cout << "Want to modify your order? y/n-->";
        cin >> cont;
    }

    cout << "Here is your updated order:" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "You have ordered the following items:" << endl;
    cout << left << setw(15) << "Name"
     << right << setw(12) << "Unit_Price"
     << setw(12) << "Quantity" << endl;
    for (auto& it : cart.toVector()) {
        cout << left << setw(15) << it.getName()
        << right << setw(12) << fixed << setprecision(2) << it.getUnitPrice()
        << setw(12) << it.getQuantity() << endl;
    }


    cout << "The total charge is $" << fixed << setprecision(2)
         << cart.getTotalPrice() << endl;
    cout << "Thanks for shopping in XXX SHOPPING CENTER." << endl;
    cout << "--------------------------------------------------" << endl;

    return 0;
}
