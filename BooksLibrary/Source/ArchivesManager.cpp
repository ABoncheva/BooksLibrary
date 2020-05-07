#include "ArchivesManager.hpp"

void ArchivesManager::showAllBooks() const
{
	if (checkActiveUser())
		BooksManager::showAllBooks();
}

void ArchivesManager::showSpecificBook(const unsigned& id) const
{
	if (checkActiveUser())
		BooksManager::showSpecificBook(id);
}

void ArchivesManager::findBookBy(const BookSearchCriteria& criterion, const std::string& value) const
{
	if(checkActiveUser())
		BooksManager::findBookBy(criterion, value);
}

void ArchivesManager::addBook(const Book& newBook)
{
	if(checkActiveAdmin())
		BooksManager::addBook(newBook);  
}

void ArchivesManager::removeBook(const Book& toBeRemoved)
{
	if(checkActiveAdmin())
		BooksManager::removeBook(toBeRemoved);
}
