#include "StudentLacedList.h"
#include "StudentNode.h"
#include "Student.h"
#include "Utils.h"
#include <string>
#include <sstream>
#include <iomanip>
using namespace model;
using namespace std;
namespace model {
StudentLacedList::StudentLacedList()
{
    this->headGrade = nullptr;
    this->headClassification = nullptr;
    this->headName = nullptr;
}

StudentLacedList::~StudentLacedList()
{
    //dtor
}

StudentNode* StudentLacedList::GetHeadName() {
    return this->headName;
}

StudentNode* StudentLacedList::GetHeadGrade() {
    return this->headGrade;
}

StudentNode* StudentLacedList::GetHeadClassification() {
    return this->headClassification;
}


void StudentLacedList::SetHeadName(StudentNode* node) {
    this->headName = node;
}

void StudentLacedList::SetHeadGrade(StudentNode* node) {
    this->headGrade = node;
}

void StudentLacedList::SetHeadClassification(StudentNode* node) {
    this->headClassification = node;
}

void StudentLacedList::Insert(Student* student) {
    StudentNode node;

    node.SetStudent(student);
    this->InsertIntoGradeLace(node);
    this->InsertIntoClassLace(node);
    this->InsertIntoNameLace(node);

}

void StudentLacedList::Delete(Student* student) {
    StudentNode* currNameNode = this->headName;
    StudentNode* nodeToDelete;
    while (currNameNode != nullptr && currNameNode->GetNextName() != nullptr) {
        if (Student::Equal(currNameNode->GetNextName()->GetStudent(), student))  {
            nodeToDelete = currNameNode->GetNextName();
            break;
        }
        currNameNode = currNameNode->GetNextName();
    }
    StudentNode* currGradeNode = this->headGrade;
    while (currGradeNode != nullptr && currGradeNode->GetNextGrade() != nullptr) {
        if (Student::Equal(currGradeNode->GetNextGrade()->GetStudent(), student))  {
            break;
        }
        currGradeNode = currGradeNode->GetNextGrade();
    }
    StudentNode* currClassificationNode = this->headClassification;
    while (currClassificationNode != nullptr && currClassificationNode->GetNextClassification() != nullptr) {
        if (Student::Equal(currClassificationNode->GetNextClassification()->GetStudent(), student))  {
            break;
        }
        currClassificationNode = currClassificationNode->GetNextClassification();
    }
    if (nodeToDelete != nullptr) {
        currNameNode->SetNextName(nodeToDelete->GetNextName());
        currGradeNode->SetNextGrade(nodeToDelete->GetNextGrade());
        currClassificationNode->SetNextClassification(nodeToDelete->GetNextClassification());
        //TODO: DELETE NODE
    }

}

void StudentLacedList::InsertIntoGradeLace(StudentNode node) {

    if(this->headGrade == nullptr ) {
        node.SetNextGrade(this->headGrade);
        this->headGrade = &node;
    } else if(this->headGrade->GetStudent()->getGrade() < node.GetStudent()->getGrade()) {
        node.SetNextGrade(this->headGrade);
        this->headGrade = &node;
    } else if (this->headGrade->GetStudent()->getGrade() == node.GetStudent()->getGrade()) {
        StudentNode* currNode = this->headGrade;
        while (currNode->GetNextGrade()->GetStudent()->getGrade() == node.GetStudent()->getGrade() && toLowerCase(currNode->GetStudent()->getFirstName()) >= toLowerCase(node.GetStudent()->getFirstName())) {
            currNode = currNode->GetNextGrade();
        }
        node.SetNextGrade(currNode->GetNextGrade());
        currNode->SetNextGrade(&node);

    } else {
        StudentNode* currNode = this->headGrade;
        while(currNode->GetNextGrade() != nullptr && currNode->GetNextGrade()->GetStudent()->getGrade() >= node.GetStudent()->getGrade()) {
            if (currNode->GetNextGrade()->GetStudent()->getGrade() == node.GetStudent()->getGrade()) {
                if(toLowerCase(currNode->GetNextGrade()->GetStudent()->getFirstName()) >= toLowerCase(node.GetStudent()->getFirstName())) {
                    currNode = currNode->GetNextGrade();
                }

            } else {
                currNode = currNode->GetNextGrade();
            }
        }
        node.SetNextGrade(currNode->GetNextGrade());
        currNode->SetNextGrade(&node);
    }
}
void StudentLacedList::InsertIntoNameLace(StudentNode node) {
    if (this->headName == nullptr) {
        node.SetNextName(this->headName);
        this->headName = &node;

    } else if (toLowerCase(this->headName->GetStudent()->getLastName()) < toLowerCase(node.GetStudent()->getLastName())) {
        node.SetNextName(this->headName);
        this->headName = &node;

    } else if (toLowerCase(this->headName->GetStudent()->getLastName()) == toLowerCase(node.GetStudent()->getLastName())) {
        StudentNode* currNode = this->headName;
        while(toLowerCase(currNode->GetNextName()->GetStudent()->getLastName()) == toLowerCase(node.GetStudent()->getLastName()) && toLowerCase(currNode->GetStudent()->getFirstName()) >= toLowerCase(node.GetStudent()->getFirstName())) {
            currNode = currNode->GetNextName();
        }
        node.SetNextName(currNode->GetNextName());
        currNode->SetNextName(&node);
    } else {
        StudentNode* currNode = this->headName;
        while(currNode->GetNextName() != nullptr && toLowerCase(currNode->GetNextName()->GetStudent()->getLastName()) >= toLowerCase(node.GetStudent()->getLastName())) {
            if (toLowerCase(currNode->GetNextName()->GetStudent()->getLastName()) == toLowerCase(node.GetStudent()->getLastName())) {
                if(toLowerCase(currNode->GetNextName()->GetStudent()->getFirstName()) >= toLowerCase(node.GetStudent()->getFirstName())) {
                    currNode = currNode->GetNextName();
                }

            } else {
                currNode = currNode->GetNextName();
            }
        }
        node.SetNextName(currNode->GetNextName());
        currNode->SetNextName(&node);
    }
}
void StudentLacedList::InsertIntoClassLace(StudentNode node) {
    if (this->headClassification == nullptr) {
        node.SetNextClassification(this->headClassification);
        this->headClassification = &node;

    } else if (this->headClassification->GetStudent()->getClassification() < node.GetStudent()->getClassification()) {
        node.SetNextClassification(this->headClassification);
        this->headClassification = &node;
    } else if (this->headClassification->GetStudent()->getClassification() == node.GetStudent()->getClassification()) {
        StudentNode* currNode = this->headClassification;
        while(currNode->GetNextClassification()->GetStudent()->getClassification() == node.GetStudent()->getClassification() && currNode->GetStudent()->getFirstName() >= node.GetStudent()->getFirstName()) {
            currNode = currNode->GetNextClassification();
        }
        node.SetNextClassification(currNode->GetNextClassification());
        currNode->SetNextClassification(&node);
    } else {
        StudentNode* currNode = this->headClassification;
        while(currNode->GetNextClassification() != nullptr && currNode->GetNextClassification()->GetStudent()->getClassification() >= node.GetStudent()->getClassification()) {
            if (currNode->GetNextClassification()->GetStudent()->getClassification() == node.GetStudent()->getClassification()) {
                if(toLowerCase(currNode->GetNextClassification()->GetStudent()->getFirstName()) >= toLowerCase(node.GetStudent()->getFirstName())) {
                    currNode = currNode->GetNextClassification();
                }

            } else {
                currNode = currNode->GetNextClassification();
            }
        }
        node.SetNextClassification(currNode->GetNextClassification());
        currNode->SetNextClassification(&node);
    }
}

    string StudentLacedList::getStudentString(Student* student)
    {
        ostringstream result;
        result <<
               setw(22) << left <<
               student->getLastName() <<
               setw(22) << left <<
               student->getFirstName() <<
               setw(22) << left <<
               student->getClassification() <<
               setw(22) << left <<
               student->getGrade();

        return result.str();
    }

    string StudentLacedList::GetGradesDescending(StudentNode* node)
    {
        ostringstream result;

        if (node->GetNextGrade() != nullptr)
        {
            result << this->GetGradesDescending(node->GetNextGrade());
        }
        result << this->getStudentString(node->GetStudent()) << endl;
        return result.str();
    }

    string StudentLacedList::GetGradesAscending(StudentNode* node)
    {
        ostringstream result;
        result << this->getStudentString(node->GetStudent()) << endl;

        if (node->GetNextGrade() != nullptr)
        {
            result << this->GetGradesDescending(node->GetNextGrade());
        }
        return result.str();
    }

    string StudentLacedList::GetNamesDescending(StudentNode* node)
    {
        ostringstream result;

        if (node->GetNextName() != nullptr)
        {
            result << this->GetNamesDescending(node->GetNextName());
        }
        result << this->getStudentString(node->GetStudent()) << endl;
        return result.str();
    }

    string StudentLacedList::GetNamesAscending(StudentNode* node)
    {
        ostringstream result;
        result << this->getStudentString(node->GetStudent()) << endl;

        if (node->GetNextName() != nullptr)
        {
            result << this->GetNamesDescending(node->GetNextName());
        }
        return result.str();
    }

    string StudentLacedList::GetClassificationsDescending(StudentNode* node)
    {
        ostringstream result;

        if (node->GetNextClassification() != nullptr)
        {
            result << this->GetClassificationsDescending(node->GetNextClassification());
        }
        result << this->getStudentString(node->GetStudent()) << endl;
        return result.str();
    }

    string StudentLacedList::GetClassificationsAscending(StudentNode* node)
    {
        ostringstream result;
        result << this->getStudentString(node->GetStudent()) << endl;

        if (node->GetNextClassification() != nullptr)
        {
            result << this->GetClassificationsDescending(node->GetNextClassification());
        }
        return result.str();
    }


}


