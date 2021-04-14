#ifndef STUDENTLACEDLIST_H
#define STUDENTLACEDLIST_H
#include "StudentNode.h"


namespace model {
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

        void InsertIntoGradeLace(StudentNode* node);
        void InsertIntoNameLace(StudentNode* node);
        void InsertIntoClassLace(StudentNode* node);

        void Insert(Student* student);

    protected:

    private:
        StudentNode* headName;
        StudentNode* headGrade;
        StudentNode* headClassification;
};
}


#endif // STUDENTLACEDLIST_H
