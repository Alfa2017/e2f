#include "unittest.h"

namespace fly2elephant {

void UnitTest::utestGeneral()
{
	{
		std::string fly = "";
		std::string elephant = "";
		std::list<std::string> dictionary;
		std::vector<std::string> result;
		UnitTest::utest(fly, elephant, dictionary, result, "������ �����");
	}

	{
		std::string fly = "����";
		std::string elephant = "����";
		std::list<std::string> dictionary;
		std::vector<std::string> result;
		UnitTest::utest(fly, elephant, dictionary, result, "������ �������");
	}

	{
		std::string fly = "����";
		std::string elephant = "����";
		std::list<std::string> dictionary;
		std::vector<std::string> result;
		result.push_back("����");
		UnitTest::utest(fly, elephant, dictionary, result, "���������� �����");
	}

	{
		std::string fly = "���";
		std::string elephant = "���";
		std::list<std::string> dictionary;
		dictionary.push_back("���");
		dictionary.push_back("���");
		dictionary.push_back("����");
		dictionary.push_back("����");
		dictionary.push_back("���");
		dictionary.push_back("����");
		dictionary.push_back("���");
		std::vector<std::string> result;
		result.push_back("���");
		result.push_back("���");
		result.push_back("���");
		UnitTest::utest(fly, elephant, dictionary, result, "���-���");
	}

	{
		std::string fly = "���";
		std::string elephant = "����";
		std::list<std::string> dictionary;
		dictionary.push_back("���");
		dictionary.push_back("���");
		dictionary.push_back("����");
		dictionary.push_back("����");
		dictionary.push_back("���");
		dictionary.push_back("����");
		dictionary.push_back("���");
		std::vector<std::string> result;
		UnitTest::utest(fly, elephant, dictionary, result, "���-����");
	}
}

} // end namespace fly2elephant
