#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <bits/stdc++.h>
#include "../models/Restaurant.h"
using namespace std;

class RestaurantManager {
    vector<Restaurant*> restaurants;
    static RestaurantManager* instance;
    RestaurantManager() {

    }
    public:
    static RestaurantManager* getInstance() {
        if (!instance) {
            instance = new RestaurantManager();
        }
        return instance;
    }
    void addRestaurant(Restaurant* r) {
        restaurants.push_back(r);
    }
    vector<Restaurant*> searchByLocation(string loc) {
        // search logic
    }
    RestaurantManager* RestaurantManager::instance = nullptr;
};

#endif // RESTAURANT_MANAGER_H 