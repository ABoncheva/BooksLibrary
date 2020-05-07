#include "BooksManager.hpp"

void BooksManager::showAllBooks() const
{
	for (int i = 0; i < allBooks.size(); ++i)
	{
		allBooks[i].showMainInfo();
		std::cout << std::endl;
	}
}

void BooksManager::showSpecificBook(const unsigned& id) const
{
	for (int i = 0; i < allBooks.size(); ++i)
	{
		if (allBooks[i].compareById(id))
		{
			allBooks[i].showAllInfo();
			std::cout << std::endl;
		}
	}
}

void BooksManager::findBookBy(const BookSearchCriteria& criterion, const std::string& value) const
{
	bool bookFound;
	switch (criterion)
	{
	case title:
	{
		findByTitle(value, bookFound);
		break;
	}
	case author:
	{
		findByAuthor(value, bookFound);
		break;
	}
	case tag:
	{
		findByTag(value, bookFound);
		break;
	}
	}

	if (!bookFound)
		std::cout << "There are no results about such book." << std::endl;
}

void BooksManager::findByTitle(const std::string& title, bool& bookFound) const
{
	for (int i = 0; i < allBooks.size(); ++i)
	{
		if (allBooks[i].compareByTitle(title))
		{
			bookFound = true;
			allBooks[i].showAllInfo();
			std::cout << std::endl;
		}
	}
}

void BooksManager::findByAuthor(const std::string& author, bool& bookFound) const
{
	for (int i = 0; i < allBooks.size(); ++i)
	{
		if (allBooks[i].compareByAuthor(author))
		{
			bookFound = true;
			allBooks[i].showAllInfo();
			std::cout << std::endl;
		}
	}
}

void BooksManager::findByTag(const std::string& tag, bool& bookFound) const
{
	for (int i = 0; i < allBooks.size(); ++i)
	{
		if (allBooks[i].compareByTag(tag))
		{
			bookFound = true;
			allBooks[i].showAllInfo();
			std::cout << std::endl;
		}
	}
}

void BooksManager::addBook(const Book& newBook)
{
	allBooks.push_back(newBook);
}

void BooksManager::removeBook(const Book& toBeRemoved)
{
	std::vector<Book>::iterator iterBooks;
	for (iterBooks = allBooks.begin(); iterBooks != allBooks.end(); ++iterBooks)
	{
		if (*iterBooks == toBeRemoved)
			allBooks.erase(iterBooks);
	}
}