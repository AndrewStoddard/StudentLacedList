#include "StudentLacedList.h"
#include "StudentNode.h"
#include "Utils.h"


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
    StudentNode* node;

    node->SetStudent(student);
    this->InsertIntoGradeLace(node);
    this->InsertIntoClassLace(node);
    this->InsertIntoNameLace(node);

}

void StudentLacedList::InsertIntoGradeLace(StudentNode* node) {

    if(this->headGrade == NULL || this->headGrade->GetStudent()->getGrade() < node->GetStudent()->getGrade()) {
        node->SetNextGrade(this->headGrade);
        this->headGrade = node;
    } else if (this->headGrade->GetStudent()->getGrade() == node->GetStudent()->getGrade()) {
        StudentNode* currNode = this->headGrade;
        while (currNode->GetNextGrade()->GetStudent()->getGrade() == node->GetStudent()->getGrade() && toLowerCase(currNode->GetStudent()->getFirstName()) >= toLowerCase(node->GetStudent()->getFirstName())) {
            currNode = currNode->GetNextGrade();
        }
        node->SetNextGrade(currNode->GetNextGrade());
        currNode->SetNextGrade(node);

    } else {
        StudentNode* currNode = this->headGrade;
        while(currNode->GetNextGrade() != NULL && currNode->GetNextGrade()->GetStudent()->getGrade() >= node->GetStudent()->getGrade()) {
            if (currNode->GetNextGrade()->GetStudent()->getGrade() == node->GetStudent()->getGrade()) {
                if(toLowerCase(currNode->GetNextGrade()->GetStudent()->getFirstName()) >= toLowerCase(node->GetStudent()->getFirstName())) {
                    currNode = currNode->GetNextGrade();
                }

            } else {
                currNode = currNode->GetNextGrade();
            }
        }
        node->SetNextGrade(currNode->GetNextGrade());
        currNode->SetNextGrade(node);
    }
}
void StudentLacedList::InsertIntoNameLace(StudentNode* node) {
    if (this->headName->GetNextName() != NULL && toLowerCase(this->headName->GetStudent()->getLastName()) < toLowerCase(node->GetStudent()->getLastName())) {
        node->SetNextName(this->headName);
        this->headName = node;

    } else if (toLowerCase(this->headName->GetStudent()->getLastName()) == toLowerCase(node->GetStudent()->getLastName())) {
        StudentNode* currNode = this->headName;
        while(toLowerCase(currNode->GetNextName()->GetStudent()->getLastName()) == toLowerCase(node->GetStudent()->getLastName()) && toLowerCase(currNode->GetStudent()->getFirstName()) >= toLowerCase(node->GetStudent()->getFirstName())) {
            currNode = currNode->GetNextName();
        }
        node->SetNextName(currNode->GetNextName());
        currNode->SetNextName(node);
    } else {
        StudentNode* currNode = this->headName;
        while(currNode->GetNextName() != NULL && toLowerCase(currNode->GetNextName()->GetStudent()->getLastName()) >= toLowerCase(node->GetStudent()->getLastName())) {
            if (toLowerCase(currNode->GetNextName()->GetStudent()->getLastName()) == toLowerCase(node->GetStudent()->getLastName())) {
                if(toLowerCase(currNode->GetNextName()->GetStudent()->getFirstName()) >= toLowerCase(node->GetStudent()->getFirstName())) {
                    currNode = currNode->GetNextName();
                }

            } else {
                currNode = currNode->GetNextName();
            }
        }
        node->SetNextName(currNode->GetNextName());
        currNode->SetNextName(node);
    }
}
void StudentLacedList::InsertIntoClassLace(StudentNode* node) {
    if (this->headClassification->GetNextClassification() != NULL && this->headClassification->GetStudent()->getClassification() < node->GetStudent()->getClassification()) {
        node->SetNextClassification(this->headClassification);
        this->headClassification = node;

    } else if (this->headClassification->GetStudent()->getClassification() == node->GetStudent()->getClassification()) {
        StudentNode* currNode = this->headClassification;
        while(currNode->GetNextClassification()->GetStudent()->getClassification() == node->GetStudent()->getClassification() && currNode->GetStudent()->getFirstName() >= node->GetStudent()->getFirstName()) {
            currNode = currNode->GetNextClassification();
        }
        node->SetNextClassification(currNode->GetNextClassification());
        currNode->SetNextClassification(node);
    } else {
        StudentNode* currNode = this->headClassification;
        while(currNode->GetNextClassification() != NULL && currNode->GetNextClassification()->GetStudent()->getClassification() >= node->GetStudent()->getClassification()) {
            if (currNode->GetNextClassification()->GetStudent()->getClassification() == node->GetStudent()->getClassification()) {
                if(toLowerCase(currNode->GetNextClassification()->GetStudent()->getFirstName()) >= toLowerCase(node->GetStudent()->getFirstName())) {
                    currNode = currNode->GetNextClassification();
                }

            } else {
                currNode = currNode->GetNextClassification();
            }
        }
        node->SetNextClassification(currNode->GetNextClassification());
        currNode->SetNextClassification(node);
    }
}


}


