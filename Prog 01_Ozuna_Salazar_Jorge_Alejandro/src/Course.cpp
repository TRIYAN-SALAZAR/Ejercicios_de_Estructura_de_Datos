#include "Course.h"
#include <iostream>

Course::Course(std::string name, int code, int credits) : name(name), code(code), credits(credits){}

Course::~Course()
{
    //dtor
}


void Course::showCourseInformation() {
    std::cout << "Name Course: " << this->name << std::endl;
    std::cout << "Code Course: " << this->code << std::endl;
    std::cout << "Credits of Course: " << this->credits << std::endl;
}

void Course::setCredits(int credits) {
    this->credits = credits;
}

int Course::getCredits() {
    return this->credits;
}
void Course::setChangeName(std::string name) {
    this->name = name;
}