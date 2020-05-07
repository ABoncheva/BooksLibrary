#ifndef ARCHIVES_MANAGER_HPP
#define ARCHIVES_MANAGER_HPP

#include "UsersManager.hpp"
#include "BooksManager.hpp"

class ArchivesManager : public UsersManager,BooksManager
{
public:
	void showAllBooks() const; // books all
	void showSpecificBook(const unsigned&) const; // books view
	void findBookBy(const BookSearchCriteria&, const std::string&) const; // books find
	void addBook(const Book&);
	void removeBook(const Book&);
};

#endif