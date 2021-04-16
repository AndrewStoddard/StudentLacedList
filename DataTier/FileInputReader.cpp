#include "FileInputReader.h"
#include <vector>
#include <iostream>
#include <fstream>

#include <sstream>
#include <string>
#include "Student.h"

using namespace model;
using namespace std;
namespace datatier {
/**
* Constructor
* @return FileInputReader
*/
FileInputReader::FileInputReader()
{
    //ctor
}
/**
* Deconstructor
*
*/
FileInputReader::~FileInputReader()
{
    //dtor
}

/**
* Reads a csv file of students into a laced list
* @param file the file name
* @return StudentLacedList
*/
StudentLacedList FileInputReader::ReadFile(string file)
{
    string line;
    StudentLacedList lacedList;
    ifstream studentFileStream(file);
    while (getline(studentFileStream, line))
    {
        Student* student = this->readStudentFromCSVString(line);
        lacedList.Insert(student);
    }

    return lacedList;
}
/**
* Reads a student from a string line in csv format
* @param line the csv line
* @return Student*
*/
Student* FileInputReader::readStudentFromCSVString(string& line)
{
    vector<string> items;
    stringstream csvStream(line);
    while(csvStream.good())
    {
        string item;
        getline(csvStream, item, ',');
        item[0] = toupper(item[0]);
        items.push_back(item);
    }
    string& classificationString = items[2];
    Student::Classification classification = Student::StringToClassification(classificationString);
    return new Student(items[1], items[0], classification, stoi(items[3]));
}

}
