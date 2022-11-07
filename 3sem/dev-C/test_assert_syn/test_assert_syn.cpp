# include <iostream >
# include <string >
# include <map >
# include <set >
# include <cassert >
using namespace std;
using Synonyms = map <string, set <string >>;
// сократили запись типа и везде изменили на Synonyms
void AddSynonyms(Synonyms& synonyms, const string & first_word, const string &
	second_word) {
	synonyms[second_word].insert(first_word);
	synonyms[first_word].insert(first_word); // тут должен не сработать AddSynonyms
}
size_t GetSynonymCount(Synonyms& synonyms, const string & word) {
	return synonyms[word].size();
}
bool AreSynonyms(Synonyms& synonyms, const string & first_word, const string &
	second_word) {
	return synonyms[first_word].count(second_word) == 1;
}
void TestAddSynonyms() { // тестируем AddSynonyms
	{
		Synonyms empty; // тест 1
		AddSynonyms(empty, " a ", " b ");
		const Synonyms expected = {
		{ " a " , { " b " }}, // ожидаем, что при добавлении синонимов появятся две записи в
		// словаре
		{ " b " , { " a " }}
		};
		assert(empty == expected);
	}
	{ // заметим, что мы формируем корректный словарь и ожидаем, что он останется корректным
		Synonyms synonyms = { // если вдруг корректность нарушится, то assert скажет, где
		{ " a " , { " b " }}, // тест 2
		{ " b " , { " a " , " c " }},
		{ " c " , { " b " }}
		};
		AddSynonyms(synonyms, " a ", " c ");
		const Synonyms expected = {
		{ " a " , { " b " , " c " }},
		{ " b " , { " a " , " c " }},
		{ " c " , { " a " , " b " }}
		};
		assert(synonyms == expected);
	}
	cout << " TestAddSynonyms OK " << endl;
}
void TestCount() { // тестируем Count
	{
		Synonyms empty;
		assert(GetSynonymCount(empty, " a ") == 0);
	}
	{
		Synonyms synonyms = {
		{ " a " , { " b " , " c " }},
		{ " b " , { " a " }},
		{ " c " , { " a " }}
		};
		assert(GetSynonymCount(synonyms, " a ") == 2);
		assert(GetSynonymCount(synonyms, " b ") == 1);
		assert(GetSynonymCount(synonyms, " z ") == 0);
	}
	cout << " TestCount OK " << endl;
}
void TestAreSynonyms() { // тестируем AreSynonyms
	{
		Synonyms empty; // пустой словарь для любых двух слов вернёт false
		assert(!AreSynonyms(empty, " a ", " b "));
		assert(!AreSynonyms(empty, " b ", " a "));
	}
	{
		Synonyms synonyms = {
		{ " a " , { " b " , " c " }},
		{ " b " , { " a " }},
		{ " c " , { " a " }}
		};
		assert(AreSynonyms(synonyms, " a ", " b "));
		assert(AreSynonyms(synonyms, " b ", " a "));
		assert(AreSynonyms(synonyms, " a ", " c "));
		assert(AreSynonyms(synonyms, " c ", " a "));
		assert(!AreSynonyms(synonyms, " b ", " c ")); // false
		assert(!AreSynonyms(synonyms, " c ", " b ")); // false
	}
	cout << " TestAreSynonyms OK " << endl;
}
void TestAll() { // функция, вызывающая все тесты
	TestCount();
	TestAreSynonyms();
	TestAddSynonyms();
}
int main() {
	TestAll();
	return 0;
}
// TestCount OK
// TestAreSynonyms OK
// main.cpp:26: void TestAddSynonyms(): Assertion 'empty == expected' failed.

