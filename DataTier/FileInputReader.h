#ifndef FILEINPUTREADER_H
#define FILEINPUTREADER_H
#include "Student.h"
#include "StudentLacedList.h"

using namespace model;
namespace datatier {
class FileInputReader
{
    public:
        FileInputReader();
        virtual ~FileInputReader();
        StudentLacedList readFile(string file);



    protected:

    private:
        Student* readStudentFromCSVString(string& line);

};
}


#endif // FILEINPUTREADER_H
