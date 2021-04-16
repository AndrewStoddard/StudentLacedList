#include "FileOutputWriter.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "Student.h"
#include "StudentLacedList.h"
using namespace model;
using namespace std;

namespace datatier {
/**
* Constructor
* @return FileOutputWriter
*/
FileOutputWriter::FileOutputWriter()
{
    //ctor
}
/**
* Deconstructor
*
*/
FileOutputWriter::~FileOutputWriter()
{
    //dtor
}
/**
* Writes output to a file in csv format
* @param fileName the file to write to
* @param lacedList the laced list with nodes to write
*/
void FileOutputWriter::WriteLacedListToFile(string fileName, StudentLacedList lacedList) {
    string output = FileOutputWriter::getOutputAscending(lacedList.GetHeadName());
    ofstream outfileOStream(fileName);
    outfileOStream << output;
}
/**
* Gets a csv output for all nodes after start node in ascending order for name
* @param node the start node
* @return string
*/
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
