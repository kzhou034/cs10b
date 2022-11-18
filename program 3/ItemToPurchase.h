#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <iostream>
using namespace std;

class ItemToPurchase {
    public:
        ItemToPurchase();
        ItemToPurchase(const string &, const string &, const int &, const int &);
        void setName(const string &);
        string name() const;
        void setPrice(const int &);
        int price() const;
        void setQuantity(const int &);
        int quantity() const;

        void setDescription(const string &);
        string description() const;
        void printItemCost();
        void printItemDescription();

    private:
        string _name;
        int _price;
        int _quantity;
        string _description;
};

#endif