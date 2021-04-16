#include "StudentLacedList.h"
#include "StudentNode.h"
#include "Student.h"
#include "Utils.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace model;
using namespace std;
namespace model
{
/**
* Constructor
* @return StudentLacedList
*/
StudentLacedList::StudentLacedList()
{
    this->headGrade = nullptr;
    this->headClassification = nullptr;
    this->headName = nullptr;
}
/**
* Deconstructor
*
*/
StudentLacedList::~StudentLacedList()
{

}
/**
* Gets the head of the name lace
* @return StudentNode*
*/
StudentNode* StudentLacedList::getHeadName()
{
    return this->headName;
}
/**
* Gets the head of the grade lace
* @return StudentNode*
*/
StudentNode* StudentLacedList::getHeadGrade()
{
    return this->headGrade;
}
/**
* Gets the head of the classification lace
* @return StudentNode*
*/
StudentNode* StudentLacedList::getHeadClassification()
{
    return this->headClassification;
}
/**
* Sets the head of the name lace
* @param node the node to be set
*/
void StudentLacedList::setHeadName(StudentNode* node)
{
    this->headName = node;
}
/**
* Sets the head of the grade lace
* @param node the node to be set
*/
void StudentLacedList::setHeadGrade(StudentNode* node)
{
    this->headGrade = node;
}
/**
* Sets the head of the classification lace
* @param node the node to be set
*/
void StudentLacedList::setHeadClassification(StudentNode* node)
{
    this->headClassification = node;
}
/**
* Inserts a stduent into the interlaced list
* @param student the stiudent to be inserted
*/
void StudentLacedList::insertNode(Student* student)
{
    StudentNode* node = new StudentNode();
    node->setStudent(student);
    this->insertIntoGradeLace(node);
    this->insertIntoClassLace(node);
    this->insertIntoNameLace(node);


}
/**
* Inserts a node into the grade lace
* @param node the node to be inserted
*/
void StudentLacedList::insertIntoGradeLace(StudentNode* node)
{
    if(this->headGrade == nullptr )
    {
        this->headGrade = node;
    }
    else if(this->headGrade->getStudent()->getGrade() < node->getStudent()->getGrade())
    {
        node->setNextGrade(this->headGrade);
        this->headGrade = node;
    }
    else if (this->headGrade->getStudent()->getGrade() == node->getStudent()->getGrade())
    {
        StudentNode* currNode = this->headGrade;
        while (currNode->getNextGrade() != nullptr && currNode->getNextGrade()->getStudent()->getGrade() == node->getStudent()->getGrade() && toLowerCase(currNode->getStudent()->getFirstName()) <= toLowerCase(node->getStudent()->getFirstName()))
        {
            currNode = currNode->getNextGrade();
        }
        node->setNextGrade(currNode->getNextGrade());
        currNode->setNextGrade(node);

    }
    else
    {
        StudentNode* currNode = this->headGrade;
        while(currNode->getNextGrade() != nullptr && currNode->getNextGrade()->getStudent()->getGrade() >= node->getStudent()->getGrade())
        {
            if (currNode->getNextGrade()->getStudent()->getGrade() == node->getStudent()->getGrade())
            {
                if(toLowerCase(currNode->getNextGrade()->getStudent()->getFirstName()) <= toLowerCase(node->getStudent()->getFirstName()))
                {
                    currNode = currNode->getNextGrade();
                } else {
                    break;
                }

            }
            else
            {
                currNode = currNode->getNextGrade();
            }
        }
        node->setNextGrade(currNode->getNextGrade());
        currNode->setNextGrade(node);
    }
}
/**
* Inserts a node into the name lace
* @param node the node to be inserted
*/
void StudentLacedList::insertIntoNameLace(StudentNode* node)
{
    if (this->headName == nullptr)
    {
        this->headName = node;
    }
    else if (toLowerCase(this->headName->getStudent()->getLastName()) < toLowerCase(node->getStudent()->getLastName()))
    {
        node->setNextName(this->headName);
        this->headName = node;


    }
    else if (toLowerCase(this->headName->getStudent()->getLastName()) == toLowerCase(node->getStudent()->getLastName()))
    {

        StudentNode* currNode = this->headName;
        while(currNode->getNextName() != nullptr && toLowerCase(currNode->getNextName()->getStudent()->getLastName()) == toLowerCase(node->getStudent()->getLastName()) && toLowerCase(currNode->getNextName()->getStudent()->getFirstName()) <= toLowerCase(node->getStudent()->getFirstName()))
        {
            currNode = currNode->getNextName();
        }
        node->setNextName(currNode->getNextName());
        currNode->setNextName(node);

    }
    else
    {
        StudentNode* currNode = this->headName;
        while(currNode->getNextName() != nullptr && toLowerCase(currNode->getNextName()->getStudent()->getLastName()) <= toLowerCase(node->getStudent()->getLastName()))
        {
            if (toLowerCase(currNode->getNextName()->getStudent()->getLastName()) == toLowerCase(node->getStudent()->getLastName()))
            {
                if(toLowerCase(currNode->getNextName()->getStudent()->getFirstName()) <= toLowerCase(node->getStudent()->getFirstName()))
                {
                    currNode = currNode->getNextName();
                } else {
                    break;
                }

            }
            else
            {
                currNode = currNode->getNextName();
            }
        }
        node->setNextName(currNode->getNextName());
        currNode->setNextName(node);

    }

}
/**
* Inserts a node into the class lace
* @param node the node to be inserted
*/
void StudentLacedList::insertIntoClassLace(StudentNode* node)
{
    if (this->headClassification == nullptr)
    {
        node->setNextClassification(this->headClassification);
        this->headClassification = node;

    }
    else if (this->headClassification->getStudent()->getClassification() < node->getStudent()->getClassification())
    {
        node->setNextClassification(this->headClassification);
        this->headClassification = node;
    }
    else if (this->headClassification->getStudent()->getClassification() == node->getStudent()->getClassification())
    {
        StudentNode* currNode = this->headClassification;
        while(currNode->getNextClassification() != nullptr && currNode->getNextClassification()->getStudent()->getClassification() == node->getStudent()->getClassification() && toLowerCase(currNode->getStudent()->getLastName()) <= toLowerCase(node->getStudent()->getLastName()))
        {
            currNode = currNode->getNextClassification();
        }
        node->setNextClassification(currNode->getNextClassification());
        currNode->setNextClassification(node);
    }
    else
    {
        StudentNode* currNode = this->headClassification;
        while(currNode->getNextClassification() != nullptr && currNode->getNextClassification()->getStudent()->getClassification() >= node->getStudent()->getClassification())
        {
            if (currNode->getNextClassification()->getStudent()->getClassification() == node->getStudent()->getClassification())
            {
                if(toLowerCase(currNode->getNextClassification()->getStudent()->getLastName()) <= toLowerCase(node->getStudent()->getLastName()))
                {
                    currNode = currNode->getNextClassification();
                } else {
                    break;
                }

            }
            else
            {
                currNode = currNode->getNextClassification();
            }
        }
        node->setNextClassification(currNode->getNextClassification());
        currNode->setNextClassification(node);
    }
}
/**
* Deletes a node from all laces
* @param firstName the firstname of the student in the lace
* @param lastName the lastname of the student in the lace
*/
void StudentLacedList::deleteNode(string& firstName, string& lastName)
{
    StudentNode* nameNode = this->getHeadName();
    StudentNode* gradeNode = this->getHeadGrade();
    StudentNode* classNode = this->getHeadClassification();
    StudentNode* nodeToDelete = nullptr;
    if (nameNode == nullptr || gradeNode == nullptr || classNode == nullptr)
    {
        return;
    }
    if(toLowerCase(classNode->getStudent()->getLastName()) == toLowerCase(lastName) && toLowerCase(classNode->getStudent()->getFirstName()) == toLowerCase(firstName))
    {

        this->headClassification = classNode->getNextClassification();
    }
    else
    {
        while (classNode->getNextClassification() != nullptr)
        {

            if (toLowerCase(classNode->getNextClassification()->getStudent()->getLastName()) == toLowerCase(lastName) && toLowerCase(classNode->getNextClassification()->getStudent()->getFirstName()) == toLowerCase(firstName))
            {
                classNode->setNextClassification(classNode->getNextClassification()->getNextClassification());
                break;
            }
            classNode = classNode->getNextClassification();
        }
    }
    if(toLowerCase(gradeNode->getStudent()->getLastName()) == toLowerCase(lastName) && toLowerCase(gradeNode->getStudent()->getFirstName()) == toLowerCase(firstName))
    {
        this->headGrade = gradeNode->getNextGrade();
    }
    else
    {
        while (gradeNode->getNextGrade() != nullptr)
        {

            if (toLowerCase(gradeNode->getNextGrade()->getStudent()->getLastName()) == toLowerCase(lastName) && toLowerCase(gradeNode->getNextGrade()->getStudent()->getFirstName()) == toLowerCase(firstName))
            {
                gradeNode->setNextGrade(gradeNode->getNextGrade()->getNextGrade());
                break;
            }
            gradeNode = gradeNode->getNextGrade();
        }
    }
    if(toLowerCase(nameNode->getStudent()->getLastName()) == toLowerCase(lastName) && toLowerCase(nameNode->getStudent()->getFirstName()) == toLowerCase(firstName))
    {
        this->headName = nameNode->getNextName();
    }
    else
    {
        while (nameNode->getNextName() != nullptr)
        {
            if (toLowerCase(nameNode->getNextName()->getStudent()->getLastName()) == toLowerCase(lastName) && toLowerCase(nameNode->getNextName()->getStudent()->getFirstName()) == toLowerCase(firstName))
            {
                nameNode->setNextName(nameNode->getNextName()->getNextName());
                break;
            }
            nameNode = nameNode->getNextName();
        }
    }

    if (nodeToDelete != nullptr)
    {
        nodeToDelete->~StudentNode();
    }


}
/**
* Gets a string of the passed student
* @param student the student to get the string of
* @return string the student string
*/
string StudentLacedList::getStudentString(Student* student)
{
    ostringstream result;
    result <<
           setw(12) << left <<
           student->getFirstName() <<
           setw(12) << left <<
           student->getLastName() <<
           setw(22) << left <<
           Student::classificationToString(student->getClassification()) <<
           setw(5) << left <<
           student->getGrade();

    return result.str();
}
/**
* Gets the string of all nodes after passed node in the grade lace descending
* @param node the start node
* @return string the string result
*/
string StudentLacedList::getGradesDescending(StudentNode* node)
{
    if (node == nullptr) {
        return "";
    }
    ostringstream result;
    result << this->getStudentString(node->getStudent()) << endl;

    if (node->getNextGrade() != nullptr)
    {
        result << this->getGradesDescending(node->getNextGrade());
    }

    return result.str();
}
/**
* Gets the string of all nodes after passed node in the grade lace ascending
* @param node the start node
* @return string the string result
*/
string StudentLacedList::getGradesAscending(StudentNode* node)
{
    if (node == nullptr) {
        return "";
    }
    ostringstream result;

    if (node->getNextGrade() != nullptr)
    {
        result << this->getGradesAscending(node->getNextGrade());
    }
    result << this->getStudentString(node->getStudent()) << endl;

    return result.str();
}
/**
* Gets the string of all nodes after passed node in the name lace descending
* @param node the start node
* @return string the string result
*/
string StudentLacedList::getNamesDescending(StudentNode* node)
{
    if (node == nullptr) {
        return "";
    }
    ostringstream result;
    result << this->getStudentString(node->getStudent()) << endl;

    if (node->getNextName() != nullptr)
    {
        result << this->getNamesDescending(node->getNextName());
    }

    return result.str();
}
/**
* Gets the string of all nodes after passed node in the name lace ascending
* @param node the start node
* @return string the string result
*/
string StudentLacedList::getNamesAscending(StudentNode* node)
{
    if (node == nullptr) {
        return "";
    }
    ostringstream result;

    if (node->getNextName() != nullptr)
    {
        result << this->getNamesAscending(node->getNextName());
    }
    result << this->getStudentString(node->getStudent()) << endl;

    return result.str();
}
/**
* Gets the string of all nodes after passed node in the classification lace descending
* @param node the start node
* @return string the string result
*/
string StudentLacedList::getClassificationsDescending(StudentNode* node)
{
    if (node == nullptr) {
        return "";
    }
    ostringstream result;
    result << this->getStudentString(node->getStudent()) << endl;

    if (node->getNextClassification() != nullptr)
    {
        result << this->getClassificationsDescending(node->getNextClassification());
    }
    return result.str();
}
/**
* Gets the string of all nodes after passed node in the classification lace ascending
* @param node the start node
* @return string the string result
*/
string StudentLacedList::getClassificationsAscending(StudentNode* node)
{
    if (node == nullptr) {
        return "";
    }
    ostringstream result;

    if (node->getNextClassification() != nullptr)
    {
        result << this->getClassificationsAscending(node->getNextClassification());
    }
    result << this->getStudentString(node->getStudent()) << endl;

    return result.str();
}


}


