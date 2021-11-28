#ifndef LABA2_ITEM_H
#define LABA2_ITEM_H

#include "Worker.h"

class Item {
public:
    Worker* data;
    Item* nextItem;
};

#endif //LABA2_ITEM_H