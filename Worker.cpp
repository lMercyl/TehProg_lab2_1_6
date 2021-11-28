#include "Worker.h"

Worker::Worker() {
    _firstName = "first name not found";
    _lastName = "last name not found";
    _middleName = "middle name not found";
    _position = "position not found";
    _year = "0";
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
    std::string str;
    std::cout << "first name: ";
    std::getline(std::cin, str);
    if (!numbersInStr(str)) {
        _firstName = str;
    } else {
        std::cout << "You input string-line when is number. Value not set" << std::endl;
    }
    std::cout << "last name: ";
    std::getline(std::cin, str);
    if (!numbersInStr(str)) {
        _lastName = str;
    } else {
        std::cout << "You input string-line when is number. Value not set" << std::endl;
    }
    std::cout << "middle name: ";
    std::getline(std::cin, str);
    if (!numbersInStr(str)) {
        _middleName = str;
    } else {
        std::cout << "You input string-line when is number. Value not set" << std::endl;
    }
    std::cout << "position: ";
    std::getline(std::cin, str);
    if (!numbersInStr(str)) {
        _position = str;
    } else {
        std::cout << "You input string-line when is number. Value not set" << std::endl;
    }
    std::cout << "year: ";
    std::getline(std::cin, str);
    if (charInNumbers(str) && str.length() == 4 && atoi(str.c_str()) < 1990 && atoi(str.c_str()) > 2021) {
        _year = str;
    } else {
        std::cout << "You input string-line when is char or value.length > or < 4 and value < 1990. Value not set" << std::endl;
    }
}

void Worker::editInfoObject(int index) {
    std::string str;
    switch (index) {
        case 1:
            std::cout << "first name: ";
            std::getline(std::cin, str);
            if (!numbersInStr(str)) {
                _firstName = str;
            } else {
                std::cout << "You input string-line when is number. Value not set" << std::endl;
            }
            break;
        case 2:
            std::cout << "last name: ";
            std::getline(std::cin, str);
            if (!numbersInStr(str)) {
                _lastName = str;
            } else {
                std::cout << "You input string-line when is number. Value not set" << std::endl;
            }
            break;
        case 3:
            std::cout << "middle name: ";
            std::getline(std::cin, str);
            if (!numbersInStr(str)) {
                _middleName = str;
            } else {
                std::cout << "You input string-line when is number. Value not set" << std::endl;
            }
            break;
        case 4:
            std::cout << "position: ";
            std::getline(std::cin, str);
            if (!numbersInStr(str)) {
                _position = str;
            } else {
                std::cout << "You input string-line when is number. Value not set" << std::endl;
            }
            break;
        case 5:
            std::cout << "year: ";
            std::getline(std::cin, str);
            if (charInNumbers(str) && str.length() == 4 && atoi(str.c_str()) < 1990 && atoi(str.c_str()) > 2021) {
                _year = str;
            } else {
                std::cout << "You input string-line when is char or value.length > or < 4 and value < 1990. Value not set" << std::endl;
            }
            break;
        default:
            std::cout << "Error input. Try again" << std::endl;
            break;
    }
}

std::istream &operator>>(std::istream &stream, Worker *object) {
    std::string str;
    std::cout << "first name: ";
    std::getline(std::cin, str);
    if (!object->numbersInStr(str)) {
        object->_firstName = str;
    } else {
        std::cout << "You input string-line when is number. Value not set" << std::endl;
    }
    std::cout << "last name: ";
    std::getline(std::cin, str);
    if (!object->numbersInStr(str)) {
        object->_lastName = str;
    } else {
        std::cout << "You input string-line when is number. Value not set" << std::endl;
    }
    std::cout << "middle name: ";
    std::getline(std::cin, str);
    if (!object->numbersInStr(str)) {
        object->_middleName = str;
    } else {
        std::cout << "You input string-line when is number. Value not set" << std::endl;
    }
    std::cout << "position: ";
    std::getline(std::cin, str);
    if (!object->numbersInStr(str)) {
        object->_position = str;
    } else {
        std::cout << "You input string-line when is number. Value not set" << std::endl;
    }
    std::cout << "year: ";
    std::getline(std::cin, str);
    if (object->charInNumbers(str) && str.length() == 4 && atoi(str.c_str()) >= 1990 && atoi(str.c_str()) <= 2021) {
        object->_year = str;
    } else {
        std::cout << "You input string-line when is char or value.length > or < 4 and value < 1990. Value not set" << std::endl;
    }
    return stream;
}

std::ostream &operator<<(std::ostream &stream, Worker *object) {
    stream << "first name: " << object->_firstName << std::endl;
    stream << "last name: " << object->_lastName << std::endl;
    stream << "middle name: " << object->_middleName << std::endl;
    stream << "position: " << object->_position << std::endl;
    stream << "year: " << object->_year << std::endl;
    stream << std::endl;
    return stream;
}

bool Worker::charInNumbers(std::string str) {
    return str.find_first_not_of("0123456789") == std::string::npos;
}

bool Worker::numbersInStr(std::string str) {
    int i = 0;
    int found = 0;
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            found++;
            return true;
        }
        i++;
    }
    if (found == 0) {
        return false;
    }
}