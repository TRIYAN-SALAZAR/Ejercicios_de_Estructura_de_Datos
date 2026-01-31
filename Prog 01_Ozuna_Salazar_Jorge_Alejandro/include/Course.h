#ifndef COURSE_H
#define COURSE_H
#include <iostream>

class Course
{
    public:
        std::string name;
        int code;
        int credits;

        Course(std::string, int, int);
        ~Course();

        void showCourseInformation();
        void setCredits(int);
        int getCredits();
        void setChangeName(std::string);

};

#endif // COURSE_H
