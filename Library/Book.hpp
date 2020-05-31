#ifndef BOOK_HPP
#define BOOK_HPP

#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<fstream>

enum BookSearchCriteria { Title, Author, Tag, Year, Rate, Id };

class Book
{
public:
	Book() { setId(); }

	Book& makeDummyBookFromConsole();
	Book& makeDummy(const BookSearchCriteria&, const std::string&);
	Book & makeDummy(const BookSearchCriteria &, const unsigned & num);

	void showMainInfo() const;
	void showAllInfo() const;
	int compare(const BookSearchCriteria&, const Book&) const;
	bool operator==(const Book&) const;
	bool empty() const;

	friend std::ostream& operator<<(std::ostream&, const Book&);
	friend std::istream& operator>>(std::istream&, Book&);

private:
	void setId();
	void showKeyWords() const;
	bool findTag(const std::vector<std::string>&) const;
	int compareIntegers(unsigned, unsigned) const;
	int compareRate(double) const;
	std::string toLower(const std::string&) const;
	int compareTitle(const Book&) const;
	int compareAuthor(const Book&) const;

private:
	std::string author;
	std::string title;
	std::string genre;
	std::string description;
	unsigned publishedIn;
	std::vector<std::string> keyWords;
	double rate;
	unsigned id;
};

#endif
