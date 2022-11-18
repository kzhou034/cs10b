#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ItemToPurchase.h"
#include <iostream>
#include <vector>
using namespace std;

class ShoppingCart {
    public:
        ShoppingCart();
        ShoppingCart(const string &, const string &);
        string customerName() const;
        string date() const;
        void addItem(const ItemToPurchase &);
        void removeItem(const string &);
        void modifyItem(const ItemToPurchase &);
        int numItemsInCart() const;
        int costOfCart() const;
        void printTotal();
        void printDescriptions();

    private:
        string _customerName;
        string _currentDate;
        vector<ItemToPurchase> _cartItems;
};

#endif