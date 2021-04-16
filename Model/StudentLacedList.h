#ifndef STUDENTLACEDLIST_H
#define STUDENTLACEDLIST_H
#include "StudentNode.h"


namespace model
{
class StudentLacedList
{
public:
    StudentLacedList();
    virtual ~StudentLacedList();
    StudentNode* getHeadName();
    StudentNode* getHeadGrade();
    StudentNode* getHeadClassification();

    void setHeadName(StudentNode* node);
    void setHeadGrade(StudentNode* node);
    void setHeadClassification(StudentNode* node);

    void insertIntoGradeLace(StudentNode* node);
    void insertIntoNameLace(StudentNode* node);
    void insertIntoClassLace(StudentNode* node);

    void insertNode(Student* student);

    void deleteNode(string& firstName, string& lastName);


    string getGradesDescending(StudentNode* node);
    string getGradesAscending(StudentNode* node);
    string getNamesDescending(StudentNode* node);
    string getNamesAscending(StudentNode* node);
    string getClassificationsDescending(StudentNode* node);
    string getClassificationsAscending(StudentNode* node);
protected:

private:
    StudentNode* headName;
    StudentNode* headGrade;
    StudentNode* headClassification;
    string getStudentString(Student* student);
};
}


#endif // STUDENTLACEDLIST_H
