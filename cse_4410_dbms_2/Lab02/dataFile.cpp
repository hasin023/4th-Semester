#include <iostream>
#include <fstream>
#include <random>

using namespace std;

void generateDepartmentSQL(ostream &outputStream, int id, const string &name)
{
    outputStream << "INSERT INTO Department (ID, Name) VALUES\n"
                 << "  (" << id << ", '" << name << "');\n\n";
}

void generateStudentSQL(ostream &outputStream, int id, const string &name, int deptID)
{
    outputStream << "INSERT INTO Student (ID, name, dept_ID) VALUES\n"
                 << "  (" << id << ", '" << name << "', " << deptID << ");\n\n";
}

void generateCourseSQL(ostream &outputStream, const string &code, const string &name, int credit, int deptID)
{
    outputStream << "INSERT INTO Course (course_code, name, credit, offered_by_dept_ID) VALUES\n"
                 << "  ('" << code << "', '" << name << "', " << credit << ", " << deptID << ");\n\n";
}

int main()
{
    ofstream outputFile("E:\\DOCS\\IUT\\4th_Sem\\cse_4410_dbms_2\\Lab02\\data.sql");

    if (!outputFile.is_open())
    {
        cerr << "Error opening file for writing\n";
        return 1;
    }

    random_device rd;
    mt19937 gen(rd());

    for (int i = 1; i <= 8; ++i)
    {
        generateDepartmentSQL(outputFile, i, "Department" + to_string(i));
    }

    for (int i = 1; i <= 4000; ++i)
    {
        generateStudentSQL(outputFile, i, "Student" + to_string(i), gen() % 10 + 1);
    }

    for (int i = 1; i <= 80; ++i)
    {
        generateCourseSQL(outputFile, "C" + to_string(i), "Course" + to_string(i), gen() % 5 + 1, gen() % 10 + 1);
    }

    outputFile.close();
    cout << "Data has been saved to file\n";

    return 0;
}
