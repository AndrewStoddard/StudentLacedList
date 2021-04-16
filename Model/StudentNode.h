#ifndef STUDENTNODE_H
#define STUDENTNODE_H
#include "Student.h"


namespace model
{
class StudentNode
{
public:
    StudentNode();
    virtual ~StudentNode();
    StudentNode* getNextName();
    StudentNode* getNextGrade();
    StudentNode* getNextClassification();
    Student* getStudent();

    void setNextName(StudentNode* node);
    void setNextGrade(StudentNode* node);
    void setNextClassification(StudentNode* node);
    void setStudent(Student* newStudent);


protected:

private:
    StudentNode* nextName;
    StudentNode* nextGrade;
    StudentNode* nextClassification;
    Student* student;

};
}


#endif // STUDENTNODE_H
