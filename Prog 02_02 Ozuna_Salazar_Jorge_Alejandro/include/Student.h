#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student
{
    private:
        int age;
        int grade;
        float average;
        std::string first_name;
        std::string last_name;

    public:
        Student();
        Student(int, std::string, std::string);
        Student(int, int, float, std::string, std::string);
        ~Student();
        void set_age(int);
        void set_grade(int);
        void set_average(float);
        void set_firstname(std::string);
        void set_lastname(std::string);
        
        int get_age() const;
        int get_grade() const;
        float get_average() const;
        std::string get_firstname() const;
        std::string get_lastname() const;
};

#endif // STUDENT_H
