#include "algo.h"
#include "exception.h"

#include <stdexcept>
#include <locale>
#include <string>
#include <fstream>
#include <list>
#include <vector>

#include <algorithm> 

#include <deque>

namespace fly2elephant {

void algo::CheckArguments(int argc, char *argv[])
{
	if (argc != 3) {
		throw BadUsage("Invalid count of arguments");
	}
}
void algo::PrepareWords(const std::string &pathToWords, std::string &sourceWord, std::string &targetWord)
{
	sourceWord.clear();
	targetWord.clear();

	std::ifstream wordsFile(pathToWords, std::ifstream::binary);   // std::ios::in
	if (!wordsFile.is_open()) {
		throw FileNotExist(pathToWords);
	}

	std::string word;
	std::getline(wordsFile, word);
	NormalizeWord(word, sourceWord);

	std::getline(wordsFile, word);
	NormalizeWord(word, targetWord);
}
void algo::PrepareDictionary(const std::string &pathToDic, std::list<std::string> &dictionary)
{
	dictionary.clear();

	std::ifstream dicFile(pathToDic);
	if (!dicFile.is_open()) {
		throw FileNotExist(pathToDic);
	}

	std::string word;
	while (std::getline(dicFile, word)) {
		std::string wWord;
		NormalizeWord(word, wWord);
		dictionary.push_back(wWord);
	}
	dictionary.sort();
	dictionary.unique();
}
void algo::NormalizeWord(const std::string &word, std::string &wWord)
{
	wWord.clear();
	if (word.empty()) return;
	wWord = word;

	std::transform(wWord.begin(), wWord.end(), wWord.begin(), ::toupper);
}

std::vector<std::string> algo::Process(const std::string &sourceWord, const std::string &targetWord)
{
	std::vector<std::string> result;

	if (sourceWord.empty() || targetWord.empty()) {
		return result;
	}

	if (sourceWord.length() != targetWord.length()) {
		return result;
	}

	if (sourceWord == targetWord) {
		result.push_back(targetWord);
		return result;
	}

	std::list<std::string> dictionary = m_dictionary;
	std::size_t flyLength = sourceWord.length();
	// удаляем все неправильные слова (слова, длинна которых отличается от длинны исходных слов)
	dictionary.remove_if([flyLength](const std::string &w)->bool {
		return w.length() != flyLength;
	});

	std::deque<std::shared_ptr<Word>> intermediateWords;
	std::shared_ptr<Word> word = std::make_shared<Word>(sourceWord);
	intermediateWords.push_back(word);
	while (!intermediateWords.empty()) {
		word = intermediateWords.front();
		intermediateWords.pop_front();

		if (word->value() == targetWord) {
			intermediateWords.clear();
			dictionary.clear();
			break;
		}

		auto it = dictionary.begin();
		while (it != dictionary.end()) {
			auto diff = word->diffFromWord(*it);
			if (diff == 1) {
				intermediateWords.push_back(std::make_shared<Word>(*it));
				intermediateWords.back()->setPrev(word);
				dictionary.erase(it++);
				continue;
			}
			++it;
		}
	}

	if (word->value() == targetWord) {
		std::list<std::string> reverseResult;
		while (word) {
			reverseResult.push_back(word->value());
			word = word->prev();
		}
		result.assign(reverseResult.rbegin(), reverseResult.rend());
	}

	return result;
}

std::size_t algo::Word::diffFromWord(const std::string &word)
{
	if (m_word == word) {
		return 0;
	}

	if (m_word.length() != word.length()) {
		return std::max(m_word.length(), word.length());
	}

	std::string::size_type diffChars(0);
	for (std::string::size_type i = 0; i != m_word.size(); ++i) {
		if (m_word[i] != word[i]) {
			++diffChars;
		}
	}
	return diffChars;
}

} // end namespace fly2elephant
