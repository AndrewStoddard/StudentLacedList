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
    StudentNode* GetHeadName();
    StudentNode* GetHeadGrade();
    StudentNode* GetHeadClassification();

    void SetHeadName(StudentNode* node);
    void SetHeadGrade(StudentNode* node);
    void SetHeadClassification(StudentNode* node);

    void InsertIntoGradeLace(StudentNode node);
    void InsertIntoNameLace(Student student);
    void InsertIntoClassLace(StudentNode node);

    void Insert(Student student);

    void Delete(Student* student);


    string GetGradesDescending(StudentNode node);
    string GetGradesAscending(StudentNode node);
    string GetNamesDescending(StudentNode node);
    string GetNamesAscending(StudentNode node);
    string GetClassificationsDescending(StudentNode node);
    string GetClassificationsAscending(StudentNode node);
protected:

private:
    StudentNode* headName;
    StudentNode* headGrade;
    StudentNode* headClassification;
    string getStudentString(Student student);
};
}


#endif // STUDENTLACEDLIST_H
