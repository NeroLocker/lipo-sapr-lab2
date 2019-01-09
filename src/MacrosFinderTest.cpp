#include <pcrecpp.h>	// PCRE library
#include <iostream>		// ifstream/ofstream/fstream
#include "MacrosFinder.h"
#include "MacrosFinderTest.h"

void MacrosFinderTest::TestFindMacros()
{
    const char* ErrorMessage = "MacrosFinder::FindMacros must find all macros names with string type";
    
    MacrosFinder Finder;
    string List = Finder.FindMacros();
    string ExpectedList = "THREAD_SAFE_CLIENT";
    
    CPPUNIT_ASSERT_MESSAGE(ErrorMessage, List == ExpectedList);
}