#include "ArchivesManager.hpp"

void ArchivesManager::showAllBooks(const int desc) const
{
	if (activeUser)
		BooksManager::showAllBooks(desc);
	else
		std::cout << "You need to log in first." << std::endl;
}

void ArchivesManager::addBook(const Book& newBook)
{
	if (activeAdmin)
		BooksManager::addBook(newBook);
	else
		std::cout << "You need to be logged in as admin" << std::endl;
}

void ArchivesManager::removeBook(const Book& toBeRemoved)
{
	if (activeAdmin)
		BooksManager::removeBook(toBeRemoved);
	else
		std::cout << "You need to be logged in as admin" << std::endl;
}

void ArchivesManager::ascendingSortBooks(const BookSearchCriteria& option) 
{
	if (activeUser)
		BooksManager::ascendingSortBooks(option);
	else
		std::cout << "You need to log in first." << std::endl;
}
