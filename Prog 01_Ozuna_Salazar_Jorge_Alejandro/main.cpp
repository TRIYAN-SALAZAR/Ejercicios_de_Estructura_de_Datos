#include <iostream>
#include <Student.h>
#include <Course.h>

int main()
{
    Course crs1("Data Structures", 100, 6);
    Course crs2("Databases", 101, 4);

    std::cout << "credits of DSA: " << (crs1.getCredits()) << std::endl;
    crs1.setChangeName("Data Structures");
    crs1.setCredits(5);
    crs1.showCourseInformation();

    std::cout << "credits of DSA: " << (crs2.getCredits()) << std::endl;
    crs2.setChangeName("Data Structures");
    crs2.setCredits(5);
    crs2.showCourseInformation();

    Student A("Jorge Ozuna", 10001);
    Student B("Oscar Khay", 10002);

    A.setUpdateAverageGrade(7.4f);
    A.setUpdateName("Jorge Ozuna Salazar");
    if(A.doesTheStudenPass())
        std::cout << "El estudiante pasa de semestre :)" << std::endl;
    else
        std::cout << "El estudiante no pasa de semestre :(" << std::endl;

    if(A.isTheStudenoutstanding())
        std::cout << "El estudiante es sobresaliente:)" << std::endl;
    else
        std::cout << "El estudiante no es sobresaliente :(" << std::endl;
    A.showStudentData();

    B.setUpdateAverageGrade(9.1f);
    B.setUpdateName("Oscar Khay Ray");
    if(B.doesTheStudenPass())
        std::cout << "El estudiante pasa de semestre :)" << std::endl;
    else
        std::cout << "El estudiante no pasa de semestre :(" << std::endl;

    if(B.isTheStudenoutstanding())
        std::cout << "El estudiante es sobresaliente:)" << std::endl;
    else
        std::cout << "El estudiante no es sobresaliente :(" << std::endl;
    B.showStudentData();

    return 0;
}
