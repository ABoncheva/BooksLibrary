#ifndef BOOK_HPP
#define BOOK_HPP

#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>

class Book
{
public:
	Book(const std::string&, const std::string&);
	void showMainInfo() const;
	void showAllInfo() const;
	bool compareById(const unsigned&) const;
	bool compareByTitle(const std::string&) const;
	bool compareByAuthor(const std::string&) const;
	bool compareByTag(const std::string&) const;
	bool operator==(const Book&) const;

private:
	void setId();
	void showKeyWords() const;

private:
	// To be reordered!
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
