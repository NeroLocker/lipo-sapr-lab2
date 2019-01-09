#include "MacrosFinder.h"
#include <string>
#include <iostream>
#include <pcrecpp.h>
#include <sstream>		// std::stringstream
#include <algorithm>    // std::find
#include <iterator>		// std::vector::iterator
#include <vector>		// std::vector

using namespace std;

string MacrosFinder::FindMacros()
{
    string macrosName = "";
    string list = "";
    pcrecpp::RE macrosNameRegex = pcrecpp::RE("#define\\s(\\w+)\\s");
    
    vector<string>macrosArray;
    vector<string>::iterator macrosArrayIterator;
    vector<string>::iterator uniqueMacros;
    
    while (getline(cin, macrosName))
    {
        pcrecpp::StringPiece input(macrosName);
        while (macrosNameRegex.FindAndConsume(&input, &macrosName))
        {
            uniqueMacros = find(macrosArray.begin(), macrosArray.end(), macrosName);
            if (uniqueMacros == macrosArray.end())
            {
                if (list == "")
                {
                    list += macrosName;
                }
                else 
                {
                    list += "\n" + macrosName;
                }
                macrosArray.push_back(macrosName);
            }
        }
    }
    return list;
}