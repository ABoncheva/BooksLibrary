#ifndef BOOKS_MANAGER_HPP
#define BOOKS_MANAGER_HPP

#include "Book.hpp"

enum BookSearchCriteria { title, author, tag };

class BooksManager
{
public:
	void showAllBooks() const;
	void showSpecificBook(const unsigned&) const;
	void findBookBy(const BookSearchCriteria&, const std::string&) const;
	void addBook(const Book&);
	void removeBook(const Book&);

private:
	void findByTitle(const std::string&, bool&) const;
	void findByAuthor(const std::string&, bool&) const;
	void findByTag(const std::string&, bool&) const;

private:
	std::vector<Book> allBooks;
};
#endif
