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
FileInputReader::FileInputReader()
{
    //ctor
}

FileInputReader::~FileInputReader()
{
    //dtor
}

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
    Student student(items[1], items[0], classification, stoi(items[3]));
    return &student;
}

}
