#include <iostream>

#include "Exercice/Exercice.h"

using namespace std;

int main()
{
    Exercice ex;

    if (ex.loadFromFile("butterfly.jpg.dots.xml"))
        cout << "Loading succeeded" << endl;
    else
        cout << "Loading failed" << endl;

    return 0;
}
