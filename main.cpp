#include "ClassRosterWindow.h"
using namespace view;

int main (int argc, char ** argv)
{
    ClassRosterWindow mainWindow(540, 375, "A3: Grade Lacer by Andrew Stoddard");
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
