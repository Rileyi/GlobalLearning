#include <iostream>

#include "Content/DotToDot/DotToDotExercice.h"

using namespace std;

int main()
{
    DotToDotExercice ex;

    if (ex.loadFromFile("butterfly.jpg.dots.xml"))
        cout << "Loading succeeded" << endl;
    else
        cout << "Loading failed" << endl;

    return 0;
}
