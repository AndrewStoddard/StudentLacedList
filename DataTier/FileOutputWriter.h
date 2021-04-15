#ifndef FILEOUTPUTWRITER_H
#define FILEOUTPUTWRITER_H
#include "StudentLacedList.h"
#include <string>
using namespace model;
using namespace std;

namespace datatier {
class FileOutputWriter
{
    public:
        FileOutputWriter();
        virtual ~FileOutputWriter();
        static void WriteLacedListToFile(string fileName, StudentLacedList lacedList);
        static string getOutputAscending(StudentNode* node);

    protected:

    private:
};
}


#endif // FILEOUTPUTWRITER_H
