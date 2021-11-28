#include "Keeper.h"

Keeper::Keeper() {
    head = nullptr;
    _size = 0;
    std::cout << "Run constructor Keeper" << std::endl;
    std::cout << std::endl;
}

Keeper::~Keeper() {
    if (head != nullptr) {
        Item* ptr;
        while (head->nextItem != nullptr) {
            ptr = head;
            head = head->nextItem;
            ptr->data->~Worker();
            delete(ptr);
        }
        head->data->~Worker();
        delete(head);
    }
    std::cout << "Run destructor Keeper" << std::endl;
    std::cout << std::endl;
}

int Keeper::getSize() {
    return _size;
}

void Keeper::pushObject(Worker *obj) {
    Item* newItemObj;
    newItemObj = new Item;
    if (_size == 0) {
        newItemObj->data = obj;
        _size++;
        newItemObj->nextItem = nullptr;
        head = newItemObj;
    }
    else {
        Item *buf = head;
        while (buf->nextItem != nullptr) {
            buf = buf->nextItem;
        }
        newItemObj->data = obj;
        newItemObj->nextItem = nullptr;
        buf->nextItem = newItemObj;
        _size++;
    }
}

void Keeper::popObject(int index) {
    Item* ptr = head;
    Item* prevPtr;
    if (_size == 0) {
        std::cout << "Is empty" << std::endl;
        return;
    }
    if (((index) >= _size) || (index < 0)) {
        std::cout << "Not found index" << std::endl;
    } else {
        if (ptr->nextItem == nullptr) {
            std::cout << "Delete last object and one in all"<< std::endl;
            ptr->data->~Worker();
            _size--;
            return;
        }
        if (index == 0) {
            head = ptr->nextItem;
            ptr->data->~Worker();
            _size--;
            return;
        }
        for (int i = 0; i < index - 1; i++) {
            ptr = ptr->nextItem;
        }
        prevPtr = ptr->nextItem;
        ptr->nextItem = prevPtr->nextItem;
        prevPtr->data->~Worker();
        _size--;
    }
}

Worker* Keeper::operator[](int index) {
    Item* ptr = head;
    if (((index) >= _size) || (index < 0)) {
        std::cout << "Error" << std::endl;
    } else {
        for (int i = 0; i < index; i++) {
            ptr = ptr->nextItem;
        }
    }
    return ptr->data;
}

void Keeper::sortByLastName() {
    Item *ptr;
    Item *tmp = new Item;
    if (head == nullptr) {
       std::cout << "Keeper is empty" << std::endl;
    } else {
        if (head->nextItem == nullptr) {
            std::cout << "Sort is ready" << std::endl;
        } else {
            bool swapped = true;
            while (swapped) {
                swapped = false;
                ptr = head;
                while (ptr->nextItem != nullptr) {
                    if (strcmp(ptr->data->getLastName().c_str(), ptr->nextItem->data->getLastName().c_str()) > 0) {
                        swapped = true;
                        tmp->data = ptr->data;
                        ptr->data = ptr->nextItem->data;
                        ptr->nextItem->data = tmp->data;
                    }
                    ptr = ptr->nextItem;
                }
            }
            std::cout << "Sort is ready" << std::endl;
        }
    }
}

void Keeper::getLastNameByExp(int value) {
    Item *ptr = head;
    bool found = false;
    int time = 0;
    if (head->nextItem == nullptr) {
        time = 2021 - atoi(ptr->data->getYear().c_str());
        if (time > value) {
            found = true;
            std::cout << "Worker: " << ptr->data->getLastName() << std::endl;
        }
    } else {
        while (ptr != nullptr) {
            time = 2021 - atoi(ptr->data->getYear().c_str());
            if (time > value) {
                found = true;
                std::cout << "Worker: " << ptr->data->getLastName() << std::endl;
            }
            ptr = ptr->nextItem;
        }
    }
    if (!found) {
        std::cout << "There are no such workers" << std::endl;
    }
    std::cout << std::endl;
}

void Keeper::addObjectInPosition(Worker *obj, int index) {
    Item *newItemObj = new Item;
    Item* ptr = head;
    Item* prevPtr;
    if (_size == 0) {
        std::cout << "Is empty" << std::endl;
        return;
    }
    if (((index) >= _size) || (index < 0)) {
        std::cout << "Not found index" << std::endl;
    } else {
        if (ptr->nextItem == nullptr) {
            pushObject(obj);
            return;
        }
        if (index == 0) {
            newItemObj->data = obj;
            newItemObj->nextItem = ptr;
            head = newItemObj;
            _size++;
            return;
        }
        for (int i = 0; i < index - 1; i++) {
            ptr = ptr->nextItem;
        }
        prevPtr = ptr->nextItem;
        newItemObj->data = obj;
        newItemObj->nextItem = prevPtr;
        ptr->nextItem = newItemObj;
        _size++;
    }
}

