#include "ShoppingCart.h"
#include <iostream>
using namespace std;

//default
ShoppingCart::ShoppingCart() {
    _customerName = "none";
    _currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(const string &custName, const string &currDate) {
    _customerName = custName;
    _currentDate = currDate;
}

string ShoppingCart::customerName() const{
    return _customerName;
}

string ShoppingCart::date() const{
    return _currentDate;
}

void ShoppingCart::addItem(const ItemToPurchase &item){
    _cartItems.push_back(item);
}

void ShoppingCart::removeItem(const string &nameOfItem){

    for (unsigned int i = 0; i < _cartItems.size(); i++) {
        if (nameOfItem == _cartItems.at(i).name()) {
            ItemToPurchase temp1 = _cartItems.at(i);
            _cartItems.at(i) = _cartItems.at(_cartItems.size() - 1);
            _cartItems.at(_cartItems.size() - 1) = temp1;
        }
    }

    if (nameOfItem == _cartItems.at(_cartItems.size()-1).name()) {
        _cartItems.pop_back();
    }
    else {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::modifyItem(const ItemToPurchase &item){
    bool itemChanged = false;

    for (unsigned int i = 0; i < _cartItems.size(); i++) {

        if (_cartItems.at(i).name() == item.name()) {
            
            itemChanged = true;
            if (item.quantity() != 0) {
                _cartItems.at(i).setQuantity(item.quantity());
                cout << _cartItems.at(i).quantity() << endl;
            }
        }
    }
    if (itemChanged == false) {
        cout << "Item not found in cart. Nothing modified." << endl;
        cout << endl;
    }
}

int ShoppingCart::numItemsInCart() const{
    int totalItems = 0;
    for (unsigned int i = 0; i < _cartItems.size(); i++) {
        totalItems += _cartItems.at(i).quantity();
    }
    return totalItems;
}

int ShoppingCart::costOfCart() const{
    int totalCost = 0;
    for (unsigned int i = 0; i < _cartItems.size(); i++) {
        totalCost += (_cartItems.at(i).price() * _cartItems.at(i).quantity());
    }
    return totalCost;
}

void ShoppingCart::printTotal(){
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl;
    cout << endl;
    if (numItemsInCart() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
        cout << endl;
        cout << "Total: $" << costOfCart() << endl;
        cout << endl;
    }
    else {
        for (unsigned int i = 0;  i < _cartItems.size(); i++) {
            cout << _cartItems.at(i).name() << " " << _cartItems.at(i).quantity() << " @ $" << _cartItems.at(i).price() << " = $" << (_cartItems.at(i).price() * _cartItems.at(i).quantity()) << endl;
        }
        cout << endl;
        cout << "Total: $" << costOfCart() << endl;
        cout << endl;
    }
    
}

void ShoppingCart::printDescriptions(){
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    for (unsigned int i = 0;  i < _cartItems.size(); i++) {
        cout << _cartItems.at(i).name() << ": " << _cartItems.at(i).description() << endl;
    }
    cout << endl;
}

