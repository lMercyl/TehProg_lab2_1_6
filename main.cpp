#include <iostream>
#include <fstream>
#include "Worker.h"
#include "Keeper.h"

void setFileHtml(Keeper& keeper);

int main() {
    int value;
    int select;
    int id;
    int _id;
    bool exit = false;
    Keeper keeper;
    Worker* worker;
    while (!exit) {
        std::cout << "Main menu" << std::endl;
        std::cout << "1 Add in keeper" << std::endl;
        std::cout << "2 Add in keeper on position" << std::endl;
        std::cout << "3 Edit item in keeper" << std::endl;
        std::cout << "4 Delete item" << std::endl;
        std::cout << "5 Show keeper" << std::endl;
        std::cout << "6 Show last name on value" << std::endl;
        std::cout << "7 Additional functionality" << std::endl;
        std::cout << "0 Exit" << std::endl;
        std::cout << "Select: ";
        if (std::cin >> select) {
            switch (select) {
                case 1:
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    worker = new Worker();
                    std::cin >> worker;
                    keeper.pushObject(worker);
                    keeper.sortByLastName();
                    break;
                case 2:
                    if (keeper.getSize() == 0) {
                        std::cout << "Keeper is empty. Add object" << std::endl;
                        std::cout << std::endl;
                    } else {
                        std::cout << std::endl;
                        for (int i = 0; i < keeper.getSize(); i++) {
                            std::cout << "Object " << i << std::endl;
                            std::cout << keeper[i];
                        }
                        std::cout << "Select object: ";
                        if (std::cin >> id) {
                            if (id < 0 || id > (keeper.getSize() - 1)) {
                                std::cout << "Error input. Try again" << std::endl;
                                std::cout << std::endl;
                            } else {
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                std::cin >> worker;
                                keeper.addObjectInPosition(worker, id);
                                keeper.sortByLastName();
                                std::cout << std::endl;
                            }
                        } else {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << std::endl;
                            std::cout << "Error input. Try again" << std::endl;
                            std::cout << std::endl;
                        }
                    }
                    break;
                case 3:
                    if (keeper.getSize() == 0) {
                        std::cout << "Keeper is empty. Add object" << std::endl;
                        std::cout << std::endl;
                    } else {
                        std::cout << std::endl;
                        for (int i = 0; i < keeper.getSize(); i++) {
                            std::cout << "Object " << i << std::endl;
                            std::cout << keeper[i];
                        }
                        std::cout << "Select object: ";
                        if (std::cin >> id) {
                            if (id < 0 || id > (keeper.getSize() - 1)) {
                                std::cout << "Error input. Try again" << std::endl;
                                std::cout << std::endl;
                            } else {
                                std::cout << std::endl;
                                std::cin.ignore(32767, '\n');
                                std::cout << keeper[id];
                                std::cout << "What edit: ";
                                if (std::cin >> _id) {
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    std::cout << std::endl;
                                    keeper[id]->editInfoObject(_id);
                                    keeper.sortByLastName();
                                } else {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    std::cout << std::endl;
                                    std::cout << "Error input. Try again" << std::endl;
                                    std::cout << std::endl;
                                }
                            }
                        } else {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << std::endl;
                            std::cout << "Error input. Try again" << std::endl;
                            std::cout << std::endl;
                        }
                    }
                    break;
                case 4:
                    if (keeper.getSize() == 0) {
                        std::cout << "Keeper is empty. Add object" << std::endl;
                        std::cout << std::endl;
                    } else {
                        std::cout << std::endl;
                        for (int i = 0; i < keeper.getSize(); i++) {
                            std::cout << "Object " << i << std::endl;
                            std::cout << keeper[i];
                        }
                        std::cout << "Select object: ";
                        if (std::cin >> id) {
                            if (id < 0 || id > (keeper.getSize() - 1)) {
                                std::cout << "Error input. Try again" << std::endl;
                                std::cout << std::endl;
                            } else {
                                std::cin.ignore(32767, '\n');
                                keeper.popObject(id);
                                keeper.sortByLastName();
                                std::cout << "Object " << id << " delete" << std::endl;
                                std::cout << std::endl;
                            }
                        } else {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << std::endl;
                            std::cout << "Error input. Try again" << std::endl;
                            std::cout << std::endl;
                        }
                    }
                    break;
                case 5:
                    if (keeper.getSize() == 0) {
                        std::cout << "Keeper is empty. Add object" << std::endl;
                        std::cout << std::endl;
                    } else {
                        std::cout << std::endl;
                        for (int i = 0; i < keeper.getSize(); i++) {
                            std::cout << keeper[i];
                        }
                    }
                    break;
                case 6:
                    if (keeper.getSize() == 0) {
                        std::cout << "Keeper is empty. Add object" << std::endl;
                        std::cout << std::endl;
                    } else {
                        std::cout << "Input value: ";
                        if (std::cin >> value) {
                            keeper.getLastNameByExp(value);
                        } else {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << std::endl;
                            std::cout << "Error input. Try again" << std::endl;
                            std::cout << std::endl;
                        }
                    }
                    break;
                case 7:
                    if (keeper.getSize() == 0) {
                        std::cout << "Keeper is empty. Add object" << std::endl;
                        std::cout << std::endl;
                    } else {
                        setFileHtml(keeper);
                    }
                    break;
                case 0:
                    exit = true;
                    break;
                default:
                    std::cout << std::endl;
                    std::cout << "Error input. Try again" << std::endl;
                    std::cout << std::endl;
                    break;
            }
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Error input. Try again" << std::endl;
            std::cout << std::endl;
        }
    }
    return 0;
}

void setFileHtml(Keeper& keeper) {
    std::ofstream file("index.html", std::ofstream::out | std::ofstream::trunc);
    try {
        if (!file.is_open()) {
            std::cout << std::endl;
            throw "Error open file";
        }
        else {
            file << "<!doctype html>\n";
            file << "<html lang=\"en\">\n";
            file << "<head>\n";
            file << "<link rel=\"stylesheet\" href=\"style.css\">\n";
            file << "<title>\n";
            file << "TehProg 2.1";
            file << "</title>\n";
            file << "</head>\n";
            file << "<body>\n";
            file << "<div class=\"worker-group\">\n";
            for (int i = 0; i < keeper.getSize(); i++) {
                file << "<div class=\"group-item\">\n";
                file << "<img class=\"image\" src=\"user.png\">\n";
                file << "<div>\n";
                file << "<p>\n";
                file << "ФИО: " << keeper[i]->getLastName() << " " << keeper[i]->getFirstName() << " "
                     << keeper[i]->getMiddleName() << "\n";
                file << "</p>\n";
                file << "<p>\n";
                file << "Позиция: " << keeper[i]->getPosition() << "\n";
                file << "</p>\n";
                file << "<p>\n";
                file << "Год выхода: " << keeper[i]->getYear() << "\n";
                file << "</p>\n";
                file << "</div>\n";
                file << "</div>\n";
            }
            file << "</div>\n";
            file << "</body>\n";
            file << "</html>";
            file.close();
            system("open index.html");
        }
    }
    catch (const char* exception) {
        std::cout << std::endl;
        std::cerr << "Error: " << exception << '\n';
        std::cout << std::endl;
    }
}