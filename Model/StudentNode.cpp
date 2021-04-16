#include "StudentNode.h"

namespace model
{
/**
* Constructor
* @return StudentNode
*/
StudentNode::StudentNode()
{
    this->nextClassification = nullptr;
    this->nextGrade = nullptr;
    this->nextName = nullptr;
}
/**
* Destructor
*
*/
StudentNode::~StudentNode()
{
    delete(this->nextClassification);
    delete(this->nextGrade);
    delete(this->nextName);
    delete(this->student);
}

/**
* Gets the next node in the name lace
* @return StudentNode*
*/
StudentNode* StudentNode::GetNextName()
{
    return this->nextName;
}
/**
* Gets the next node in the grade lace
* @return StudentNode*
*/
StudentNode* StudentNode::GetNextGrade()
{
    return this->nextGrade;
}
/**
* Gets the next node in the classification lace
* @return StudentNode*
*/
StudentNode* StudentNode::GetNextClassification()
{
    return this->nextClassification;
}
/**
* Gets the student
* @return Student*
*/
Student* StudentNode::GetStudent()
{
    return this->student;
}
/**
* Sets the next node in the name lace
* @param node the next node in name lace
*/
void StudentNode::SetNextName(StudentNode* node)
{
    this->nextName = node;
}
/**
* Sets the next node in the grade lace
* @param node the next node in grade lace
*/
void StudentNode::SetNextGrade(StudentNode* node)
{
    this->nextGrade = node;
}
/**
* Sets the next node in the classification lace
* @param node the next node in classification lace
*/
void StudentNode::SetNextClassification(StudentNode* node)
{
    this->nextClassification = node;
}
/**
* Sets the student
* @param newStudent The new student
*/
void StudentNode::SetStudent(Student* newStudent)
{
    this->student = newStudent;
}

}


