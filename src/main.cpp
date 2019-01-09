#include <string>
#include <iostream>
#include <pcrecpp.h>
#include "MacrosFinder.h"
#include "MacrosFinderTest.h"

using namespace std;

int main(int argc, char** argv) 
{
    CPPUNIT_TEST_SUITE_REGISTRATION(MacrosFinderTest);
	
	if ( argc >= 2 )
	{
	    // If argument option is -t or --test, then make test
	    if ( strcmp(argv[1], "-t\n") || strcmp(argv[1], "--test\n") ) 
		{
			CppUnit::Test *test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
			CppUnit::TextTestRunner runner;
			runner.addTest(test);
			
			runner.run();
			
			exit(0);
		}
		// Else run program
	}
	
    MacrosFinder Finder;
    cout << Finder.FindMacros() << endl;
    return 0;
}