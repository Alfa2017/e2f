#include "unittest.h"

namespace fly2elephant {

void UnitTest::utestGeneral()
{
	{
		std::string fly = "";
		std::string elephant = "";
		std::list<std::string> dictionary;
		std::vector<std::string> result;
		UnitTest::utest(fly, elephant, dictionary, result, "Ïóñòûå ñëîâà");
	}

	{
		std::string fly = "ÌÓÕÀ";
		std::string elephant = "ÑËÎÍ";
		std::list<std::string> dictionary;
		std::vector<std::string> result;
		UnitTest::utest(fly, elephant, dictionary, result, "Ïóñòîé ñëîâàğü");
	}

	{
		std::string fly = "ÌÓÕÀ";
		std::string elephant = "ÌÓÕÀ";
		std::list<std::string> dictionary;
		std::vector<std::string> result;
		result.push_back("ÌÓÕÀ");
		UnitTest::utest(fly, elephant, dictionary, result, "Îäèíàêîâûå ñëîâà");
	}

	{
		std::string fly = "ÊÎÒ";
		std::string elephant = "ÒÎÍ";
		std::list<std::string> dictionary;
		dictionary.push_back("ÊÎÒ");
		dictionary.push_back("ÒÎÍ");
		dictionary.push_back("ÍÎÒÀ");
		dictionary.push_back("ÊÎÒÛ");
		dictionary.push_back("ĞÎÒ");
		dictionary.push_back("ĞÎÒÀ");
		dictionary.push_back("ÒÎÒ");
		std::vector<std::string> result;
		result.push_back("ÊÎÒ");
		result.push_back("ÒÎÒ");
		result.push_back("ÒÎÍ");
		UnitTest::utest(fly, elephant, dictionary, result, "ÊÎÒ-ÒÎÍ");
	}

	{
		std::string fly = "ÊÎÒ";
		std::string elephant = "ÊÎÒÛ";
		std::list<std::string> dictionary;
		dictionary.push_back("ÊÎÒ");
		dictionary.push_back("ÒÎÍ");
		dictionary.push_back("ÍÎÒÀ");
		dictionary.push_back("ÊÎÒÛ");
		dictionary.push_back("ĞÎÒ");
		dictionary.push_back("ĞÎÒÀ");
		dictionary.push_back("ÒÎÒ");
		std::vector<std::string> result;
		UnitTest::utest(fly, elephant, dictionary, result, "ÊÎÒ-ÊÎÒÛ");
	}
}

} // end namespace fly2elephant
