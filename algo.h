#ifndef CONVERTER_H_
#define CONVERTER_H_

#include <list>
#include <vector>
#include <memory>
#include <string>

#include <algorithm>

namespace fly2elephant {

	class algo {
public:
	algo()
	{}
	algo(const std::list<std::string> &dictionary)
		: m_dictionary(dictionary)
	{}
	void setDictionary(const std::list<std::string> &dictionary) { m_dictionary = dictionary; }
	std::vector<std::string> Process(const std::string &flyWord, const std::string &elephantWord);
	// проверки
	static void  algo::CheckArguments(int argc, char *argv[]);
	static void  algo::PrepareWords(const std::string &pathToWords, std::string &sourceWord, std::string &targetWord);
	static void  algo::PrepareDictionary(const std::string &pathToDic, std::list<std::string> &dictionary);
	static void  algo::NormalizeWord(const std::string &word, std::string &wWord);

private:
	std::list<std::string> m_dictionary;

private:
	class Word {
	public:
		Word(const std::string &word)
			: m_word(word)
		{}
		const std::string& value() const { return m_word; }
		void setPrev(const std::shared_ptr<Word> &prev) { m_prev = prev; }
		const std::shared_ptr<Word> &prev() const { return m_prev; }
		std::size_t diffFromWord(const std::string &word);

	private:
		std::string m_word;
		std::shared_ptr<Word> m_prev;

	};
};

} // end namespace fly2elephant

#endif /* CONVERTER_H_ */

