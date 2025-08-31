#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <bits/stdc++.h>
#include "MenuItem.h"
using namespace std;

class Restaurant {
    static int nextRestaurantId;
    int restaurantId;
    string name;
    string location;
    vector<MenuItem> menu;
    public:
    Restaurant(const string& name, const string& location) {
        this->name = name;
        this->location = location;
        this->restaurantId = nextRestaurantId++;
    }

    ~Restaurant() {
        menu.clear();
    }

    // getter setter
    string getName() {
        return name;
    }

    void setName(const string& n) {
        name = n;
    }

    string getLocation() {
        return location;
    }

    void setLocation(const string& l) {
        location = l;
    }

    void addMenuItem(const MenuItem& item) {
        menu.push_back(item);
    }

    const vector<MenuItem>& getMenu() const {
        return menu;
    }
};

int Restaurant::nextRestaurantId = 0;

#endif // RESTAURANT_H
