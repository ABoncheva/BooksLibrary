#include "Book.hpp"

Book::Book(const std::string& title, const std::string& author) : title(title), author(author)
{
	// the other atributes should be initialized as well
	// maybe they could be read from a file that an admin is opening
	setId();
}

void Book::setId()
{
	srand(time(NULL));
	id = rand();
}

void Book::showMainInfo() const
{
	std::cout << "Title: " << title << std::endl;
	std::cout << "Author: " << author << std::endl;
	std::cout << "Genre: " << genre << std::endl;
	std::cout << "ID: " << std::endl;
}

void Book::showAllInfo() const
{
	showMainInfo();
	std::cout << "Description: " << description << std::endl;
	std::cout << "Published in: " << publishedIn << std::endl;
	showKeyWords();
	std::cout << "Rate: " << rate << std::endl;
}

void Book::showKeyWords() const
{
	int i = 0;
	for (i = 0; i < keyWords.size()-1; ++i)
	{
		std::cout << keyWords[i] << ", ";
	}
	std::cout << keyWords[i] << std::endl;
}

bool Book::compareById(const unsigned& id) const
{
	return this->id == id;
}

bool Book::compareByTitle(const std::string& title) const
{
	return this->title == title;
}

bool Book::compareByAuthor(const std::string& author) const
{
	return this->author == author;
}

bool Book::compareByTag(const std::string& tag) const
{
	for (int i = 0; i < keyWords.size(); ++i)
	{
		if (keyWords[i] == tag)
			return true;
	}
	return false;
}

bool Book::operator==(const Book& other) const
{
	return compareByTitle(other.title) && compareByAuthor(other.author);
}