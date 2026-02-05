// Implements the ShoppingCart class
// dj5172pl Teagen Lee
// 9/22/2025
// Dr. Jie Hu Meichsner

ShoppingCart::ShoppingCart() : Bag<item>(), totalPrice(0.0) {}

double ShoppingCart::getTotalPrice() const {
    return totalPrice;
}

bool ShoppingCart::add(const item& newEntry) {
    bool added = Bag<item>::add(newEntry);
    if (added) {
        totalPrice += newEntry.getUnitPrice() * newEntry.getQuantity();
    }
    return added;
}

bool ShoppingCart::remove(const item& anEntry) {
    bool removed = Bag<item>::remove(anEntry);
    if (removed) {
        totalPrice -= anEntry.getUnitPrice() * anEntry.getQuantity();
    }
    return removed;
}

void ShoppingCart::clear() {
    Bag<item>::clear();
    totalPrice = 0.0;
}
