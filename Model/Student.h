#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

namespace model
{

//
// Defines a student
//
class Student
{
public:
    static const string DualEnrollment;
    static const string Undergrad;
    static const string Grad;
    static const string Postdoc;
    static const string Unknown;

    static bool equals(Student* student1, Student* student2);
    //
    // Student classification
    //
    enum Classification {DUALENROLLMENT, UNDERGRAD, GRAD, POSTDOC, UNKNOWN};

private:
    string firstName;
    string lastName;
    Classification classification;
    int grade;

public:
    Student(const string& firstName, const string& lastName, Classification classification, int grade);
    Student(const string& firstName, const string& lastName);
    virtual ~Student();

    const string& getFirstName() const;
    const string& getLastName() const;
    Student::Classification getClassification() const;
    int getGrade() const;
    static Classification stringToClassification(string& classification);
    static string classificationToString(Student::Classification classification);
};

}


#endif // STUDENT_H
