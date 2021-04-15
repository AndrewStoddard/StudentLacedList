#include "FileOutputWriter.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "Student.h"
#include "StudentLacedList.h"
using namespace model;
using namespace std;

namespace datatier {
FileOutputWriter::FileOutputWriter()
{
    //ctor
}

FileOutputWriter::~FileOutputWriter()
{
    //dtor
}

void FileOutputWriter::WriteLacedListToFile(string fileName, StudentLacedList lacedList) {
    string output = FileOutputWriter::getOutputAscending(lacedList.GetHeadName());
    ofstream outfileOStream(fileName);
    outfileOStream << output;
}
string FileOutputWriter::getOutputAscending(StudentNode* node) {
    ostringstream result;
    result
    << node->GetStudent()->getLastName() << ","
    << node->GetStudent()->getFirstName() << ","
    << Student::ClassificationToString(node->GetStudent()->getClassification()) << ","
    << node->GetStudent()->getGrade()
    << endl;

    if (node->GetNextName() != nullptr)
    {
        result << FileOutputWriter::getOutputAscending(node->GetNextName());
    }

    return result.str();
}


}
