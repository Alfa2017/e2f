#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <stdexcept>

namespace fly2elephant {

	class BadUsage : public std::runtime_error {
	public:
		BadUsage(const std::string& whatUsage)
			: runtime_error(whatUsage)
		{}

	};

	class FileNotExist : public std::runtime_error {
	public:
		FileNotExist(const std::string& whatFile)
			: runtime_error(whatFile)
		{}
	};

}

#endif /* EXCEPTION_H_ */