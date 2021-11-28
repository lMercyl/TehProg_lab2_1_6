#ifndef LABA2_WORKER_H
#define LABA2_WORKER_H

#include <iostream>
#include <string>

class Worker {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _middleName;
    std::string _position;
    std::string _year;
protected:
    bool numbersInStr(std::string str);
    bool charInNumbers(std::string str);
public:
    Worker();
    Worker(std::string firstName, std::string lastName, std::string middleName, std::string position, std::string year);
    Worker(Worker& obj);
    ~Worker();
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setMiddleName(std::string middleName);
    void setPosition(std::string position);
    void setYear(std::string year);
    std::string getFirstName();
    std::string getLastName();
    std::string getMiddleName();
    std::string getPosition();
    std::string getYear();
    void setInfoObject();
    void editInfoObject(int index);
    friend std::istream& operator>>(std::istream& stream,Worker* object);
    friend std::ostream& operator<<(std::ostream& stream,Worker* object);
};


#endif //LABA2_WORKER_H
