#include "Student.h"
#include "Utils.h"
namespace model
{

// Define constants associated with Student class
const string Student::DualEnrollment = "DUALENROLLMENT";
const string Student::Undergrad = "UNDERGRAD";
const string Student::Grad = "GRAD";
const string Student::Postdoc = "POSTDOC";

//
// Constructs a student object
//
// @precondition none
// @postcondition none
//
// @param firstName first name of student
// @param lastName last name of student
// @param classification type of student - grad, undergrad, etc.
// @param grade grade student has earned
//
Student::Student(const string& firstName, const string& lastName, Classification classification, int grade)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->classification = classification;
    this->grade = grade;
}

Student::Student(const string& firstName, const string& lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
}

//
// Gets the student's first name
//
// @precondition none
// @postcondition none
//
// @return Student's first name
//
const string& Student::getFirstName() const
{
    return this->firstName;
}

//
// Gets the student's last name
//
// @precondition none
// @postcondition none
//
// @return Student's last name
//
const string& Student::getLastName() const
{
    return this->lastName;
}

//
// Gets the student's classification
//
// @precondition none
// @postcondition none
//
// @return Student's classification
//
Student::Classification Student::getClassification() const
{
    return this->classification;
}

bool Student::Equal(Student* student1, Student* student2)
{
    return toLowerCase(student1->getFirstName()) == toLowerCase(student2->getFirstName()) && toLowerCase(student1->getLastName()) == toLowerCase(student2->getLastName());
}

Student::Classification Student::StringToClassification(string& classification) {
    Student::Classification result;
    if (classification == Student::DualEnrollment) {
        result = Student::DUALENROLLMENT;
    } else if (classification == Student::Undergrad) {
        result = Student::UNDERGRAD;
    } else if (classification == Student::Grad) {
        result = Student::GRAD;
    } else if (classification == Student::Postdoc) {
        result = Student::POSTDOC;
    } else {
        result = Student::UNKNOWN;
    }
    return result;
}


//
// Gets the student's grade earned
// @precondition none
// @postcondition none
//
// @return Student's grade earned
//
int Student::getGrade() const
{
    return this->grade;
}

//
// Destructor that cleans up all allocated resources for the Student object
//
Student::~Student()
{
    //dtor
}

}
