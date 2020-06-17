#ifndef ARCHIVES_MANAGER_HPP
#define ARCHIVES_MANAGER_HPP

#include "UsersManager.hpp"
#include "BooksManager.hpp"

class ArchivesManager : public UsersManager, public BooksManager
{

public:

	template<typename T>
	void findBook(const BookCompareCriteria &, const T &) const;

	void showAllBooks(const int desc = 0) const;

	void addBook(const Book &);

	void removeBook(const Book &);

	void ascendingSortBooks(const BookCompareCriteria &);

};

template<typename T>
void ArchivesManager::findBook(const BookCompareCriteria & criterion, const T & value) const
{
	if (activeUser)
		BooksManager::findBookBy(criterion, value);
	else
		std::cout << "You need to log in first." << std::endl;
}

#endif