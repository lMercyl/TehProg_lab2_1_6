#ifndef LABA2_KEEPER_H
#define LABA2_KEEPER_H

#include "Item.h"

class Keeper {
private:
    Item* head;
    int _size;
protected:
public:
    Keeper();
    ~Keeper();
    int getSize();
    void pushObject(Worker* obj);
    void addObjectInPosition(Worker* obj, int index);
    void popObject(int index);
    void sortByLastName();
    void getLastNameByExp(int value);
    Worker* operator[](int index);
};


#endif //LABA2_KEEPER_H
