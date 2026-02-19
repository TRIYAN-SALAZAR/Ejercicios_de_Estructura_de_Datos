#include "Student.h"
#include <iostream>

using std::string;

Student::Student() : age(0), grade(0), average(0.0f), first_name(""), last_name("") {}
Student::Student(int age, string f_name, string l_name) {}
Student::Student(int age, int grd, float avg, string f_name, string l_name) {}

Student::~Student()
{
    //dtor
}

void Student::set_age(int age) {}
void Student::set_grade(int grd) {}
void Student::set_average(float avg) {}
void Student::set_firsname(std::string f_name) {}
void Student::set_lastname(std::string l_name) {}

int Student::get_age() const {}
int Student::get_grade() const {}
float Student::get_average() const {}
string Student::get_firsname() const {}
string Student::get_lastname() const {}