#include "Student.h"
#include <iostream>

using std::string;

Student::Student() {
    age = new int(0);
    grade = new int(0);
    average = new float(0.0f);
    first_name = new string("");
    last_name = new string("");
}

Student::Student(int a, string f_name, string l_name) {
    age = new int(a);
    grade = new int(0);
    average = new float(0.0f);
    first_name = new string(f_name);
    last_name = new string(l_name);

}

Student::Student(int a, int grd, float avg, string f_name, string l_name) {
    age = new int(a);
    grade = new int(grd);
    average = new float(avg);
    first_name = new string(f_name);
    last_name = new string(l_name);
}

Student::~Student()
{
    
}

void Student::set_age(int age) {}
void Student::set_grade(int grd) {}
void Student::set_average(float avg) {}
void Student::set_firstname(std::string f_name) {}
void Student::set_lastname(std::string l_name) {}

int Student::get_age() const {}
int Student::get_grade() const {}
float Student::get_average() const {}
string Student::get_firstname() const {}
string Student::get_lastname() const {}