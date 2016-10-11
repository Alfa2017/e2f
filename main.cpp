//$(SolutionDir)$(Configuration)\
//$(Configuration)\

//#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <iostream>

#include <fstream>

#include <io.h>
#include <fcntl.h>
#include <string>

#include "algo.h"
#include "exception.h"

#include "unittest.h"

using namespace fly2elephant;


int main(int argc, char *argv[])
{
	#ifdef UTEST
	    ::setlocale(LC_CTYPE, "rus");
	    UnitTest::utestGeneral();
	    return 0;
    #else
		try {
			::setlocale(LC_CTYPE, "rus");
			algo::CheckArguments(argc, argv);

			std::string sourceWrd, targetWrd;
			algo::PrepareWords(argv[1], sourceWrd, targetWrd);

			std::list<std::string> dictionary;
			algo::PrepareDictionary(argv[2], dictionary);

			algo f2e(dictionary);
			std::vector<std::string> result;
			result = f2e.Process(sourceWrd, targetWrd);
			for (std::string &word : result) {
				std::cout << word << std::endl;
			}

			return 0;
		}
		catch (const BadUsage& e) {
			std::cerr << std::endl;
			std::cerr << "error:" << e.what() << std::endl;
			std::cerr << "usage: " << argv[0] << " [pathToWords] [pathToDic]" << std::endl;
			std::cerr << " [pathToWords] \t path to the file with source and target words" << std::endl;
			std::cerr << " [pathToDic] \t path to the file with dictionary" << std::endl;
		}
		catch (const FileNotExist& e) {
			std::cerr << std::endl;
			std::cerr << "error: file \"" << e.what() << "\" is not exist" << std::endl;
			std::cerr << "check path to files" << std::endl;
		}
    #endif
}