#include "Student.h"
#include "Utils.h"
namespace model
{

// Define constants associated with Student class
const string Student::DualEnrollment = "DUALENROLLMENT";
const string Student::Undergrad = "UNDERGRAD";
const string Student::Grad = "GRAD";
const string Student::Postdoc = "POSTDOC";
const string Student::Unknown = "UNKNOWN";

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
/**
* Checks if two students are equal
* @param student1 first student
* @param student2 second student
* @return bool
*/
bool Student::equals(Student* student1, Student* student2)
{
    return toLowerCase(student1->getFirstName()) == toLowerCase(student2->getFirstName()) && toLowerCase(student1->getLastName()) == toLowerCase(student2->getLastName());
}
/**
* Converts classification to a string
* @param classification The classification to convert
* @return string
*/
string Student::classificationToString(Student::Classification classification) {
    string result;
    if (classification == Student::DUALENROLLMENT) {
        result = Student::DualEnrollment;
    } else if (classification == Student::UNDERGRAD) {
        result = Student::Undergrad;
    } else if (classification == Student::GRAD) {
        result = Student::Grad;
    } else if (classification == Student::POSTDOC) {
        result = Student::Postdoc;
    } else {
        result = Student::Unknown;
    }
    return result;
}
/**
* Converts string to a classification
* @param classification The classification to convert
* @return Classification
*/
Student::Classification Student::stringToClassification(string& classification) {
    Student::Classification result;
    if (toLowerCase(classification) == toLowerCase(Student::DualEnrollment)) {
        result = Student::DUALENROLLMENT;
    } else if (toLowerCase(classification) == toLowerCase(Student::Undergrad)) {
        result = Student::UNDERGRAD;
    } else if (toLowerCase(classification) == toLowerCase(Student::Grad)) {
        result = Student::GRAD;
    } else if (toLowerCase(classification) == toLowerCase(Student::Postdoc)) {
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
