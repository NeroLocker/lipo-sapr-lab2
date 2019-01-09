#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "MacrosFinder.h"

using namespace std;

class MacrosFinderTest : public CppUnit::TestCase
{
    public:
        void TestFindMacros();
        
        CPPUNIT_TEST_SUITE(MacrosFinderTest);
        CPPUNIT_TEST(TestFindMacros);
        CPPUNIT_TEST_SUITE_END();
};