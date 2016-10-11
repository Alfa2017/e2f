#ifndef UNITTEST_H_
#define UNITTEST_H_

#include "algo.h"

#include <iostream>

namespace fly2elephant {

class UnitTest {
public:
	static bool utest(const std::string &flyWord
			, const std::string &elephantWord
			, const std::list<std::string> &dictionary
			, const std::vector<std::string> &etalon
			, const std::string &name = "some utest" )
	{
		algo converter;
		converter.setDictionary(dictionary);
		std::vector<std::string> result;
		result = converter.Process(flyWord, elephantWord);
		std::size_t iStep = 0;
		while (iStep != std::min(etalon.size(), result.size()) && etalon[iStep] == result[iStep]) {
			++iStep;
		}
		if (iStep < std::max(etalon.size(), result.size())) {
			std::cout << "test [" << name << "] is failed on step " << iStep << std::endl;
			std::cout << " etalon: " << (iStep < etalon.size() ? etalon[iStep] : "has no word") << std::endl;
			std::cout << " result: " << (iStep < result.size() ? result[iStep] : "has no word") << std::endl;
			return false;
		} else {
			std::cout << "test [" << name << "] is successfully passed" << std::endl;
			return true;
		}
	}

	static void utestGeneral();

};

} // end namespace fly2elephant

#endif /* UNITTEST_H_ */
