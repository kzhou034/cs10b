#include "ItemToPurchase.h"
#include <iostream>
using namespace std;

//default
ItemToPurchase::ItemToPurchase() {
    _name = "none";
    _price = 0;
    _quantity = 0;
    _description = "none";
}

ItemToPurchase::ItemToPurchase(const string &nameSet, const string &descriptionSet, const int &priceSet, const int &quantitySet) {
    _name = nameSet;
    _price = priceSet;
    _quantity = quantitySet;
    _description = descriptionSet;
}

void ItemToPurchase::setName(const string &nameSet) {
    _name = nameSet;
}

string ItemToPurchase::name() const{
    return _name;
}

void ItemToPurchase::setPrice(const int &priceSet) {
    _price = priceSet;
}

int ItemToPurchase::price() const{
    return _price;
}

void ItemToPurchase::setQuantity(const int &quantitySet) {
    _quantity = quantitySet;
}

int ItemToPurchase:: quantity() const{
    return _quantity;
}

void ItemToPurchase::setDescription(const string &descriptionSet){
    _description = descriptionSet;
}

string ItemToPurchase::description() const{
    return _description;
}

void ItemToPurchase::printItemCost(){
    cout << _name << " " << _quantity << "@ $" << _price << " = $" << _price * _quantity << endl;
}

void ItemToPurchase::printItemDescription(){
    cout << _name << ": " << _description << endl;
}
