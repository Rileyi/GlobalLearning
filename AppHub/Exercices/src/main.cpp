#include <iostream>

#include "Content/DotToDot/DotToDotExercice.h"
#include "Exception.h"

int main()
{
    DotToDotExercice ex;

    try
    {
		ex.loadFromFile("butterfly.jpg.dots.xml");
		std::cout << "Loading succeeded" << std::endl;
    }
    catch(Exception &e)
    {
		std::cout << e.what() << std::endl;
    }
    return 0;
}
