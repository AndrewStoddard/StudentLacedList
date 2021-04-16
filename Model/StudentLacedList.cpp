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
StudentNode* StudentLacedList::GetHeadName()
{
    return this->headName;
}
/**
* Gets the head of the grade lace
* @return StudentNode*
*/
StudentNode* StudentLacedList::GetHeadGrade()
{
    return this->headGrade;
}
/**
* Gets the head of the classification lace
* @return StudentNode*
*/
StudentNode* StudentLacedList::GetHeadClassification()
{
    return this->headClassification;
}
/**
* Sets the head of the name lace
* @param node the node to be set
*/
void StudentLacedList::SetHeadName(StudentNode* node)
{
    this->headName = node;
}
/**
* Sets the head of the grade lace
* @param node the node to be set
*/
void StudentLacedList::SetHeadGrade(StudentNode* node)
{
    this->headGrade = node;
}
/**
* Sets the head of the classification lace
* @param node the node to be set
*/
void StudentLacedList::SetHeadClassification(StudentNode* node)
{
    this->headClassification = node;
}
/**
* Inserts a stduent into the interlaced list
* @param student the stiudent to be inserted
*/
void StudentLacedList::Insert(Student* student)
{
    StudentNode* node = new StudentNode();
    node->SetStudent(student);
    this->InsertIntoGradeLace(node);
    this->InsertIntoClassLace(node);
    this->InsertIntoNameLace(node);


}
/**
* Inserts a node into the grade lace
* @param node the node to be inserted
*/
void StudentLacedList::InsertIntoGradeLace(StudentNode* node)
{
    if(this->headGrade == nullptr )
    {
        this->headGrade = node;
    }
    else if(this->headGrade->GetStudent()->getGrade() < node->GetStudent()->getGrade())
    {
        node->SetNextGrade(this->headGrade);
        this->headGrade = node;
    }
    else if (this->headGrade->GetStudent()->getGrade() == node->GetStudent()->getGrade())
    {
        StudentNode* currNode = this->headGrade;
        while (currNode->GetNextGrade() != nullptr && currNode->GetNextGrade()->GetStudent()->getGrade() == node->GetStudent()->getGrade() && toLowerCase(currNode->GetStudent()->getFirstName()) <= toLowerCase(node->GetStudent()->getFirstName()))
        {
            currNode = currNode->GetNextGrade();
        }
        node->SetNextGrade(currNode->GetNextGrade());
        currNode->SetNextGrade(node);

    }
    else
    {
        StudentNode* currNode = this->headGrade;
        while(currNode->GetNextGrade() != nullptr && currNode->GetNextGrade()->GetStudent()->getGrade() >= node->GetStudent()->getGrade())
        {
            if (currNode->GetNextGrade()->GetStudent()->getGrade() == node->GetStudent()->getGrade())
            {
                if(toLowerCase(currNode->GetNextGrade()->GetStudent()->getFirstName()) <= toLowerCase(node->GetStudent()->getFirstName()))
                {
                    currNode = currNode->GetNextGrade();
                } else {
                    break;
                }

            }
            else
            {
                currNode = currNode->GetNextGrade();
            }
        }
        node->SetNextGrade(currNode->GetNextGrade());
        currNode->SetNextGrade(node);
    }
}
/**
* Inserts a node into the name lace
* @param node the node to be inserted
*/
void StudentLacedList::InsertIntoNameLace(StudentNode* node)
{
    if (this->headName == nullptr)
    {
        this->headName = node;
    }
    else if (toLowerCase(this->headName->GetStudent()->getLastName()) < toLowerCase(node->GetStudent()->getLastName()))
    {
        node->SetNextName(this->headName);
        this->headName = node;


    }
    else if (toLowerCase(this->headName->GetStudent()->getLastName()) == toLowerCase(node->GetStudent()->getLastName()))
    {

        StudentNode* currNode = this->headName;
        while(currNode->GetNextName() != nullptr && toLowerCase(currNode->GetNextName()->GetStudent()->getLastName()) == toLowerCase(node->GetStudent()->getLastName()) && toLowerCase(currNode->GetNextName()->GetStudent()->getFirstName()) <= toLowerCase(node->GetStudent()->getFirstName()))
        {
            currNode = currNode->GetNextName();
        }
        node->SetNextName(currNode->GetNextName());
        currNode->SetNextName(node);

    }
    else
    {
        StudentNode* currNode = this->headName;
        while(currNode->GetNextName() != nullptr && toLowerCase(currNode->GetNextName()->GetStudent()->getLastName()) <= toLowerCase(node->GetStudent()->getLastName()))
        {
            if (toLowerCase(currNode->GetNextName()->GetStudent()->getLastName()) == toLowerCase(node->GetStudent()->getLastName()))
            {
                if(toLowerCase(currNode->GetNextName()->GetStudent()->getFirstName()) <= toLowerCase(node->GetStudent()->getFirstName()))
                {
                    currNode = currNode->GetNextName();
                } else {
                    break;
                }

            }
            else
            {
                currNode = currNode->GetNextName();
            }
        }
        node->SetNextName(currNode->GetNextName());
        currNode->SetNextName(node);

    }

}
/**
* Inserts a node into the class lace
* @param node the node to be inserted
*/
void StudentLacedList::InsertIntoClassLace(StudentNode* node)
{
    if (this->headClassification == nullptr)
    {
        node->SetNextClassification(this->headClassification);
        this->headClassification = node;

    }
    else if (this->headClassification->GetStudent()->getClassification() < node->GetStudent()->getClassification())
    {
        node->SetNextClassification(this->headClassification);
        this->headClassification = node;
    }
    else if (this->headClassification->GetStudent()->getClassification() == node->GetStudent()->getClassification())
    {
        StudentNode* currNode = this->headClassification;
        while(currNode->GetNextClassification() != nullptr && currNode->GetNextClassification()->GetStudent()->getClassification() == node->GetStudent()->getClassification() && toLowerCase(currNode->GetStudent()->getLastName()) <= toLowerCase(node->GetStudent()->getLastName()))
        {
            currNode = currNode->GetNextClassification();
        }
        node->SetNextClassification(currNode->GetNextClassification());
        currNode->SetNextClassification(node);
    }
    else
    {
        StudentNode* currNode = this->headClassification;
        while(currNode->GetNextClassification() != nullptr && currNode->GetNextClassification()->GetStudent()->getClassification() >= node->GetStudent()->getClassification())
        {
            if (currNode->GetNextClassification()->GetStudent()->getClassification() == node->GetStudent()->getClassification())
            {
                if(toLowerCase(currNode->GetNextClassification()->GetStudent()->getLastName()) <= toLowerCase(node->GetStudent()->getLastName()))
                {
                    currNode = currNode->GetNextClassification();
                } else {
                    break;
                }

            }
            else
            {
                currNode = currNode->GetNextClassification();
            }
        }
        node->SetNextClassification(currNode->GetNextClassification());
        currNode->SetNextClassification(node);
    }
}
/**
* Deletes a node from all laces
* @param firstName the firstname of the student in the lace
* @param lastName the lastname of the student in the lace
*/
void StudentLacedList::Delete(string& firstName, string& lastName)
{
    StudentNode* nameNode = this->GetHeadName();
    StudentNode* gradeNode = this->GetHeadGrade();
    StudentNode* classNode = this->GetHeadClassification();
    StudentNode* nodeToDelete = nullptr;
    if (nameNode == nullptr || gradeNode == nullptr || classNode == nullptr)
    {
        return;
    }
    if(toLowerCase(classNode->GetStudent()->getLastName()) == toLowerCase(lastName) && toLowerCase(classNode->GetStudent()->getFirstName()) == toLowerCase(firstName))
    {
        nodeToDelete = classNode;
        this->headClassification = classNode->GetNextClassification();
    }
    else
    {
        while (classNode->GetNextClassification() != nullptr)
        {

            if (toLowerCase(classNode->GetNextClassification()->GetStudent()->getLastName()) == toLowerCase(lastName) && toLowerCase(classNode->GetNextClassification()->GetStudent()->getFirstName()) == toLowerCase(firstName))
            {
                classNode->SetNextClassification(classNode->GetNextClassification()->GetNextClassification());
                break;
            }
            classNode = classNode->GetNextClassification();
        }
    }
    if(toLowerCase(gradeNode->GetStudent()->getLastName()) == toLowerCase(lastName) && toLowerCase(gradeNode->GetStudent()->getFirstName()) == toLowerCase(firstName))
    {
        nodeToDelete = gradeNode;
        this->headGrade = gradeNode->GetNextGrade();
    }
    else
    {
        while (gradeNode->GetNextGrade() != nullptr)
        {

            if (toLowerCase(gradeNode->GetNextGrade()->GetStudent()->getLastName()) == toLowerCase(lastName) && toLowerCase(gradeNode->GetNextGrade()->GetStudent()->getFirstName()) == toLowerCase(firstName))
            {
                gradeNode->SetNextGrade(gradeNode->GetNextGrade()->GetNextGrade());
                break;
            }
            gradeNode = gradeNode->GetNextGrade();
        }
    }
    if(toLowerCase(nameNode->GetStudent()->getLastName()) == toLowerCase(lastName) && toLowerCase(nameNode->GetStudent()->getFirstName()) == toLowerCase(firstName))
    {
        nodeToDelete = nameNode;
        this->headName = nameNode->GetNextName();
    }
    else
    {
        while (nameNode->GetNextName() != nullptr)
        {
            if (toLowerCase(nameNode->GetNextName()->GetStudent()->getLastName()) == toLowerCase(lastName) && toLowerCase(nameNode->GetNextName()->GetStudent()->getFirstName()) == toLowerCase(firstName))
            {
                nameNode->SetNextName(nameNode->GetNextName()->GetNextName());
                break;
            }
            nameNode = nameNode->GetNextName();
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
           Student::ClassificationToString(student->getClassification()) <<
           setw(5) << left <<
           student->getGrade();

    return result.str();
}
/**
* Gets the string of all nodes after passed node in the grade lace descending
* @param node the start node
* @return string the string result
*/
string StudentLacedList::GetGradesDescending(StudentNode* node)
{
    ostringstream result;
    result << this->getStudentString(node->GetStudent()) << endl;

    if (node->GetNextGrade() != nullptr)
    {
        result << this->GetGradesDescending(node->GetNextGrade());
    }

    return result.str();
}
/**
* Gets the string of all nodes after passed node in the grade lace ascending
* @param node the start node
* @return string the string result
*/
string StudentLacedList::GetGradesAscending(StudentNode* node)
{
    ostringstream result;

    if (node->GetNextGrade() != nullptr)
    {
        result << this->GetGradesAscending(node->GetNextGrade());
    }
    result << this->getStudentString(node->GetStudent()) << endl;

    return result.str();
}
/**
* Gets the string of all nodes after passed node in the name lace descending
* @param node the start node
* @return string the string result
*/
string StudentLacedList::GetNamesDescending(StudentNode* node)
{
    ostringstream result;
    result << this->getStudentString(node->GetStudent()) << endl;

    if (node->GetNextName() != nullptr)
    {
        result << this->GetNamesDescending(node->GetNextName());
    }

    return result.str();
}
/**
* Gets the string of all nodes after passed node in the name lace ascending
* @param node the start node
* @return string the string result
*/
string StudentLacedList::GetNamesAscending(StudentNode* node)
{
    ostringstream result;

    if (node->GetNextName() != nullptr)
    {
        result << this->GetNamesAscending(node->GetNextName());
    }
    result << this->getStudentString(node->GetStudent()) << endl;

    return result.str();
}
/**
* Gets the string of all nodes after passed node in the classification lace descending
* @param node the start node
* @return string the string result
*/
string StudentLacedList::GetClassificationsDescending(StudentNode* node)
{
    ostringstream result;
    result << this->getStudentString(node->GetStudent()) << endl;

    if (node->GetNextClassification() != nullptr)
    {
        result << this->GetClassificationsDescending(node->GetNextClassification());
    }
    return result.str();
}
/**
* Gets the string of all nodes after passed node in the classification lace ascending
* @param node the start node
* @return string the string result
*/
string StudentLacedList::GetClassificationsAscending(StudentNode* node)
{
    ostringstream result;

    if (node->GetNextClassification() != nullptr)
    {
        result << this->GetClassificationsAscending(node->GetNextClassification());
    }
    result << this->getStudentString(node->GetStudent()) << endl;

    return result.str();
}


}


