#include "StudentLacedList.h"
#include "StudentNode.h"


namespace model {
StudentLacedList::StudentLacedList()
{
    //ctor
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
    if(this->headGrade == NULL || this->headGrade->GetStudent()->getGrade() < node.GetStudent()->getGrade()) {
        node.SetNextGrade(this->headGrade);
        this->headGrade = node;
    } else if (this->headGrade->GetStudent()->getGrade() == node.GetStudent()->getGrade()) {
        StudentNode* currNode = this->headGrade;
        while (currNode->GetNextGrade()->GetStudent()->getGrade() == node.GetStudent()->getGrade() && currNode->GetStudent()->getFirstName() >= node.GetStudent()->getFirstName()) {
            currNode = currNode.GetNextGrade();
        }
        node.SetNextGrade(currNode->GetNextGrade());
        currNode.SetNextGrade(node);

    } else {
        StudentNode* currNode = this->headGrade;
        while(currNode->GetNextGrade() != NULL && currNode->GetNextGrade()->getGrade() >= node.GetStudent()->getGrade()) {
            if (currNode->GetNextGrade()->GetStudent()->getGrade() == node.GetStudent()->getGrade()) {
                if(currNode->GetNextGrade()->GetStudent()->getFirstName() >= node.GetStudent()->getFirstName()) {
                    currNode = currNode->GetNextGrade();
                }

            } else {
                currNode = currNode->GetNextGrade();
            }
        }
        node.SetNextGrade(currNode->GetNextGrade());
        currNode->SetNextGrade(node);
    }
}

}


