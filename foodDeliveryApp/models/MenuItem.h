#ifndef MENUITEM_H
#define MENUITEM_H

#include <bits/stdc++.h>
using namespace std;

class MenuItem {
    string code;
    string name;
    int price;
    public:
    MenuItem(const string& code, const string& name, int price) {
        this->code = code;
        this->name = name;
        this->price = price;
    }
    // getter setter
    string getCode() const {
        return code;
    }

    void setCode(const string& c) {
        code = c;
    }

    string getName() const {
        return name;
    }

    void setName(const string& n) {
        name = n;
    }

    int getPrice() {
        return price;
    }

    void setPrice(int p) {
        price = p;
    }
};

#endif // MENUITEM_H