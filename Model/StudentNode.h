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
    StudentNode* GetNextName();
    StudentNode* GetNextGrade();
    StudentNode* GetNextClassification();
    Student* GetStudent();

    void SetNextName(StudentNode* node);
    void SetNextGrade(StudentNode* node);
    void SetNextClassification(StudentNode* node);
    void SetStudent(Student* newStudent);


protected:

private:
    StudentNode* nextName;
    StudentNode* nextGrade;
    StudentNode* nextClassification;
    Student* student;

};
}


#endif // STUDENTNODE_H
