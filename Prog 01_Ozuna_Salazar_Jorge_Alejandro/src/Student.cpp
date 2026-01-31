#include "Student.h"
#include <iostream>

Student::Student(std::string name, int studenID) : name(name), ID(studenID) {
    this->averageGrade = 0.0f;
}
Student::Student(std::string name, int studenID, float averageGrade) : name(name), ID(studenID), averageGrade(averageGrade) {}

Student::~Student() {}

void Student::showStudentData() {
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Student ID: " << this->ID << std::endl;
    std::cout << "Average Grade: " << this->averageGrade << std::endl;
}

void Student::setUpdateAverageGrade(float average) {
    this->averageGrade = average;
}

void Student::setUpdateName(std::string name) {
    this->name = name;
}

bool Student::doesTheStudenPass() {
    if(this->averageGrade >= 6.0) return true;
    return false;
}

bool Student::isTheStudenoutstanding() {
    if(this->averageGrade >= 9.0) return true;
    return false;
}