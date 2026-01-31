#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student
{
    public:
        std::string name;
        int ID;
        float averageGrade;
        Student(std::string, int);
        Student(std::string, int, float);
        
        ~Student();

        void showStudentData();
        void setUpdateAverageGrade(int);
        void setUpdateName(std::string);
        
        bool doesTheStudenPass();
        bool isTheStudenoutstanding();
};

#endif // STUDENT_H
