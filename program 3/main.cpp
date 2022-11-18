#include <iostream>
#include <vector>
#include <string>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;

void printMenu(ShoppingCart );

int main() {
    string nameOfCustomer = "";
    string todaysDate = "";

    cout << "Enter customer's name: " << endl;
    getline(cin, nameOfCustomer);
    cout << "Enter today's date: " << endl;
    getline(cin, todaysDate);
    cout << endl;
    cout << "Customer name: " << nameOfCustomer << endl;
    cout << "Today's date: " << todaysDate << endl;
    ShoppingCart shoppingCart(nameOfCustomer, todaysDate);
    cout << endl;
    printMenu(shoppingCart);

    return 0;
}

void printMenu(ShoppingCart cart) {
    char menuChoice = 'z';
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option: " << endl;

    while (menuChoice != 'q') {

        cin >> menuChoice;

        if (menuChoice != 'q'){
            string itemName = "none";
            string itemDescription = "none";
            int itemPrice = 0;
            int itemQuantity = 0;
            string newName = "none";
            int newQuantity = 0;

            cin.get();
            if (menuChoice == 'a') {
                cout << "ADD ITEM TO CART" << endl;
                cout << "Enter the item name: " << endl;
                
                getline (cin, itemName);

                cout << "Enter the item description: " << endl;
                getline (cin, itemDescription);

                cout << "Enter the item price: " << endl;
                cin >> itemPrice;

                cout << "Enter the item quantity: " << endl;
                cin >> itemQuantity;

                cart.addItem(ItemToPurchase(itemName, itemDescription, itemPrice, itemQuantity));
                cout << endl;

                cout << "MENU" << endl;
                cout << "a - Add item to cart" << endl;
                cout << "d - Remove item from cart" << endl;
                cout << "c - Change item quantity" << endl;
                cout << "i - Output items' descriptions" << endl;
                cout << "o - Output shopping cart" << endl;
                cout << "q - Quit" << endl << endl;
                cout << "Choose an option: " << endl;
            }
            else if (menuChoice == 'd') {
                cout << "REMOVE ITEM FROM CART" << endl;
                cout << "Enter name of item to remove: " << endl;
                getline (cin, itemName);

                cart.removeItem(itemName);
                cout << endl;

                cout << "MENU" << endl;
                cout << "a - Add item to cart" << endl;
                cout << "d - Remove item from cart" << endl;
                cout << "c - Change item quantity" << endl;
                cout << "i - Output items' descriptions" << endl;
                cout << "o - Output shopping cart" << endl;
                cout << "q - Quit" << endl << endl;
                cout << "Choose an option: " << endl;
                
            }
            else if (menuChoice == 'c') {
                ItemToPurchase modItem;

                cout << "CHANGE ITEM QUANTITY" << endl;
                cout << "Enter the item name: " << endl;
                getline(cin, newName);
                modItem.setName(newName);

                cout << "Enter the new quantity: " << endl;
                cin >> newQuantity;
                modItem.setQuantity(newQuantity);

                cart.modifyItem(modItem);

                cout << "MENU" << endl;
                cout << "a - Add item to cart" << endl;
                cout << "d - Remove item from cart" << endl;
                cout << "c - Change item quantity" << endl;
                cout << "i - Output items' descriptions" << endl;
                cout << "o - Output shopping cart" << endl;
                cout << "q - Quit" << endl << endl;
                cout << "Choose an option: " << endl;
            }
            else if (menuChoice == 'i') {
                cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
                cart.printDescriptions();

                cout << "MENU" << endl;
                cout << "a - Add item to cart" << endl;
                cout << "d - Remove item from cart" << endl;
                cout << "c - Change item quantity" << endl;
                cout << "i - Output items' descriptions" << endl;
                cout << "o - Output shopping cart" << endl;
                cout << "q - Quit" << endl << endl;
                cout << "Choose an option: " << endl;
            }
            else if (menuChoice == 'o') {
                cout << endl;
                cout << "OUTPUT SHOPPING CART" << endl;
                cart.printTotal();

                cout << "MENU" << endl;
                cout << "a - Add item to cart" << endl;
                cout << "d - Remove item from cart" << endl;
                cout << "c - Change item quantity" << endl;
                cout << "i - Output items' descriptions" << endl;
                cout << "o - Output shopping cart" << endl;
                cout << "q - Quit" << endl << endl;
                cout << "Choose an option: " << endl;
            }
            else {
                cout << "Choose an option: " << endl;
            }
        }
    }
}

