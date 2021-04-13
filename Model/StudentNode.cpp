#include "StudentNode.h"

namespace model {
StudentNode::StudentNode()
{
    //ctor
}

StudentNode::~StudentNode()
{
    //dtor
}


StudentNode* StudentNode::GetNextName() {
    return this->nextName;
}
StudentNode* StudentNode::GetNextGrade() {
    return this->nextGrade;
}
StudentNode* StudentNode::GetNextClassification() {
    return this->nextClassification;
}
Student* StudentNode::GetStudent() {
    return this->student;
}
void StudentNode::SetNextName(StudentNode* node) {
    this->nextName = node;
}
void StudentNode::SetNextGrade(StudentNode* node) {
    this->nextGrade = node;
}
void StudentNode::SetNextClassification(StudentNode* node) {
    this->nextClassification = node;
}
void StudentNode::SetStudent(Student* newStudent) {
    this->student = newStudent;
}

}


