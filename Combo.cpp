#include "Combo.hpp"
#include <string>

using namespace std;

Combo::Combo() {
    Combo::comboCodeSequence++;
    this->code = comboCodeSequence;
}

Combo::Combo(vector<Item*> items, float discount) {
    Combo::comboCodeSequence++;
    this->code = comboCodeSequence;

    this->items = items;
    this->discount = discount;
}

int Combo::getCode() {
    return code;
}

vector<Item*> Combo::getItems() {
    return items;
}

float Combo::getDiscount() {
    return discount;
}

float Combo::getPrice() {
    float total = 0;

    for (Item* item : items) {
        total += item->getPrice();
    }

    return total;
}

float Combo::getPriceWithDiscount() {
    float price = getPrice();
    return price - (price * discount);
}

void Combo::setItems(vector<Item*> items) {
    this->items = items;
}

void Combo::setDiscount(float discount) {
    this->discount = discount;
}

string Combo::toString() {
    string comboText;

    for(int i = 0; i < items.size(); i++) {
        comboText += items[i]->getName();

        if (i < items.size() - 1) {
            comboText += ", ";
        }
    }

    return comboText;
}
