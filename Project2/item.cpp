// Implements the item class
// dj5172pl Teagen Lee
// 9/22/2025
// Dr. Jie Hu Meichsner


#include <iostream>
#include <string>

using namespace std;

item::item(){
    name = "Blank";
    unitPrice = 0.0;
    quantity = 0;
}

item::item(string n, double p, int q) {
    name = n;
    unitPrice = p;
    quantity = q;
}

void item::setName(string n) {
    name = n;
}

void item::setUnitPrice(double p){
    unitPrice = p;   
}

void item::setQuantity(int q) {
    quantity = q;
}

string item::getName() const {
    return name;
}

double item::getUnitPrice() const {
    return unitPrice;
}

int item::getQuantity() const {
    return quantity;
}

istream& operator>>(istream& is, item& i) {
    is >> i.name >> i.unitPrice >> i.quantity;
    return is;
}

ostream& operator<<(ostream& os, const item& i) {
    os << i.name << " $" << i.unitPrice << " Amount: " << i.quantity;
    return os; 
}

bool operator==(const item& a, const item& b) {
    return (a.name == b.name &&
            a.unitPrice == b.unitPrice &&
            a.quantity == b.quantity);
}