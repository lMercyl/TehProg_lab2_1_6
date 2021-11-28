#include "Worker.h"

Worker::Worker() {
    _firstName = "first name not found";
    _lastName = "last name not found";
    _middleName = "middle name not found";
    _position = "position not found";
    _year = "year not found";
}

Worker::Worker(std::string firstName, std::string lastName, std::string middleName, std::string position,
               std::string year) {
    _firstName = firstName;
    _lastName = lastName;
    _middleName = middleName;
    _position = position;
    _year = year;
}

Worker::Worker(Worker &obj) {
    _firstName = obj._firstName;
    _lastName = obj._lastName;
    _middleName = obj._middleName;
    _position = obj._position;
    _year = obj._year;
}

Worker::~Worker() {
    _firstName = "";
    _lastName = "";
    _middleName = "";
    _position = "";
    _year = "";
}

void Worker::setFirstName(std::string firstName) {
    _firstName = firstName;
}

void Worker::setLastName(std::string lastName) {
    _lastName = lastName;
}

void Worker::setMiddleName(std::string middleName) {
    _middleName = middleName;
}

void Worker::setPosition(std::string position) {
    _position = position;
}

void Worker::setYear(std::string year) {
    _year = year;
}

std::string Worker::getFirstName() {
    return _firstName;
}

std::string Worker::getLastName() {
    return _lastName;
}

std::string Worker::getMiddleName() {
    return _middleName;
}

std::string Worker::getPosition() {
    return _position;
}

std::string Worker::getYear() {
    return _year;
}

void Worker::setInfoObject() {
    std::cout << "first name: ";
    std::getline(std::cin, _firstName);
    std::cout << "last name: ";
    std::getline(std::cin, _lastName);
    std::cout << "middle name: ";
    std::getline(std::cin, _middleName);
    std::cout << "position: ";
    std::getline(std::cin, _position);
    std::cout << "year: ";
    std::getline(std::cin, _year);
}

void Worker::editInfoObject(int index) {
    switch (index) {
        case 1:
            std::cout << "first name: ";
            std::getline(std::cin, _firstName);
            break;
        case 2:
            std::cout << "last name: ";
            std::getline(std::cin, _lastName);
            break;
        case 3:
            std::cout << "middle name: ";
            std::getline(std::cin, _middleName);
            break;
        case 4:
            std::cout << "position: ";
            std::getline(std::cin, _position);
            break;
        case 5:
            std::cout << "year: ";
            std::getline(std::cin, _year);
            break;
        default:
            std::cout << "Error input. Try again" << std::endl;
            break;
    }
}

std::istream &operator>>(std::istream &stream, Worker *object) {
    std::cout << "first name: ";
    std::getline(stream, object->_firstName);
    std::cout << "last name: ";
    std::getline(stream, object->_lastName);
    std::cout << "middle name: ";
    std::getline(stream, object->_middleName);
    std::cout << "position: ";
    std::getline(stream, object->_position);
    std::cout << "year: ";
    std::getline(stream, object->_year);
    return stream;
}

std::ostream &operator<<(std::ostream &stream, Worker *object) {
    stream << "full name: " << object->_lastName << object->_firstName << object->_middleName << std::endl;
    stream << "position: " << object->_position << std::endl;
    stream << "year: " << object->_year << std::endl;
    stream << std::endl;
    return stream;
}
