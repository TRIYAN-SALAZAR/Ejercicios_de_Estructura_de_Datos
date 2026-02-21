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

Student::Student(const Student& other)
    : age(nullptr),
      grade(nullptr),
      average(nullptr),
      first_name(nullptr),
      last_name(nullptr)
{
    if (other.age != nullptr)
        age = new int(*other.age);
    
    if (other.grade != nullptr)
        grade = new int(*other.grade);
    
    if (other.average != nullptr)
        average = new float(*other.average);
    
    if (other.first_name != nullptr)
        first_name = new std::string(*other.first_name);
    
    if (other.last_name != nullptr)
        last_name = new std::string(*other.last_name);
}

Student& Student::operator=(const Student& other) {
     if (this != &other) {
        delete age;
        delete grade;
        delete average;
        delete first_name;
        delete last_name;
        
        age = (other.age != nullptr) ? new int(*other.age) : nullptr;
        grade = (other.grade != nullptr) ? new int(*other.grade) : nullptr;
        average = (other.average != nullptr) ? new float(*other.average) : nullptr;
        first_name = (other.first_name != nullptr) ? new std::string(*other.first_name) : nullptr;
        last_name = (other.last_name != nullptr) ? new std::string(*other.last_name) : nullptr;
    }
    return *this;
}

Student::~Student() {
    delete age;
    delete grade;
    delete average;
    delete first_name;
    delete last_name;

    age = nullptr;
    grade = nullptr;
    average = nullptr;
    first_name = nullptr;
    last_name = nullptr;
}

void Student::set_age(int a) { *age = a; }
void Student::set_grade(int grd) { *grade = grd; }
void Student::set_average(float avg) { *average = avg; }
void Student::set_firstname(std::string f_name) { *first_name = f_name; }
void Student::set_lastname(std::string l_name) { *last_name = l_name; }

int Student::get_age() const { return *age; }
int Student::get_grade() const { return *grade; }
float Student::get_average() const { return *average; }
string Student::get_firstname() const { return *first_name; }
string Student::get_lastname() const { return *last_name; }

void Student::display() const
{
    std::cout << "Nombre: " << get_firstname() << " " << get_lastname() << "\n"
              << "Edad: " << get_age() << "\n"
              << "Grado: " << get_grade() << "\n"
              << "Promedio: " << get_average() << std::endl;
}