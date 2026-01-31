#include <iostream>
#include <Student.h>
#include <Course.h>

int main()
{
    Course crs1("Data Structures", 100, 6);
    Course crs2("Databases", 101, 4);

    std::cout << "==================== Instancia 1 - Estructura de datos ====================" << std::endl;
    std::cout << "Creditos de Estructura de Datos: " << (crs1.getCredits()) << std::endl;
    crs1.setChangeName("Data Structures");
    crs1.setCredits(5);
    crs1.showCourseInformation();
    std::cout << std::endl;

    std::cout << "==================== Instancia 2 - Base de Datos ====================" << std::endl;
    std::cout << "Creditos de Bases de datos: " << (crs2.getCredits()) << std::endl;
    crs2.setChangeName("Data Structures");
    crs2.setCredits(5);
    crs2.showCourseInformation();
    std::cout << std::endl;

    Student A("Jorge Ozuna", 10001);
    Student B("Oscar Khay", 10002);
    
    std::cout << "==================== Instancia 1 - Estudiante A ====================" << std::endl;
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
    std::cout << std::endl;

    std::cout << "==================== Instancia 1 - Estudiante B ====================" << std::endl;
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
