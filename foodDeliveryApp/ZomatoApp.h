#ifndef TOMATO_APP_H
#define TOMATO_APP_H

#include <bits/stdc++.h>
#include "models/Restaurant.h"
#include "models/MenuItem.h"
#include "managers/RestaurantManager.h"
using namespace std;

class ZomatoApp {
    public:
    ZomatoApp() {
        initialiseRestaurants();
    }
    void initialiseRestaurants() {
        Restaurant* restaurant1 = new Restaurant("Bikaner", "Delhi");
        restaurant1->addMenuItem(MenuItem("P1", "Chole Bhature", 120));
        RestaurnatManager* restaurantManager = RestaurantManager::getInstance();
    }
};

#endif // TOMATO_APP_H