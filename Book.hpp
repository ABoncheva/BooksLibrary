#ifndef BOOK_HPP
#define BOOK_HPP

#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<fstream>

enum BookCompareCriteria { Title, Author, Tag, Year, Rate, Id };

class Book
{

public:

	Book() { setId(); }

	Book & makeDummyBookFromConsole();

	template<typename T>
	Book & makeDummy(const BookCompareCriteria &, const T &);

	template<>
	Book & makeDummy<std::string>(const BookCompareCriteria &, const std::string &);

	template<>
	Book & makeDummy<unsigned>(const BookCompareCriteria &, const unsigned &);

	void showMainInfo() const;

	void showAllInfo() const;

	int compare(const BookCompareCriteria &, const Book &) const;

	bool operator==(const Book &) const;

	bool empty() const;

	friend std::ostream & operator<<(std::ostream &, const Book &);

	friend std::istream & operator>>(std::istream &, Book &);


private:

	struct KeyWords
	{
		std::vector<std::string> words;
	} keyWords;

	void setId();

	void writeKeyWords(std::ostream &) const;

	void readKeyWords(std::istream &);

	int findTag(const KeyWords &) const;

	int compareIntegers(const unsigned &, const unsigned &) const;

	int compareRate(const double &) const;

	int compareTitle(const Book &) const;

	int compareAuthor(const Book &) const;

	std::string toLower(const std::string &) const;


private:

	std::string author;

	std::string title;

	std::string genre;

	std::string description;

	double rate;

	unsigned publishedIn;

	unsigned id;

};

template<typename T>
Book & Book::makeDummy(const BookCompareCriteria &, const T &)
{
	std::cerr << "A dummy cannot be created with the given data" << std::endl;
}

template<>
Book & Book::makeDummy<std::string>(const BookCompareCriteria & criterion, const std::string & value)
{
	switch (criterion)
	{
	case Title:
	{
		this->title = value;
		break;
	}
	case Author:
	{
		this->author = value;
		break;
	}
	case Tag:
	{
		keyWords.words.emplace_back(value);
		break;
	}
	default:
		std::cout << "Invalid search criterion" << std::endl;
	}

	return *this;
}

template<>
Book & Book::makeDummy<unsigned>(const BookCompareCriteria & criterion, const unsigned & value)
{
	switch (criterion)
	{
	case Id:
	{
		this->id = value;
		break;
	}
	case Year:
	{
		this->publishedIn = value;
		break;
	}
	}

	return *this;
}


#endif
