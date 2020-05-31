#ifndef BOOKS_MANAGER_HPP
#define BOOKS_MANAGER_HPP

#include "Book.hpp"

class BooksManager
{
public:
	void showAllBooks(const int desc = 0) const;

	template<typename T>
	void findBookBy(const BookSearchCriteria&, const T&) const;

	void addBook(const Book&);
	void removeBook(const Book&);
	void setBooks(const std::vector<Book>&);
	void freeBooks();
	void ascendingSortBooks(const BookSearchCriteria&);
	const std::vector<Book>& getBooks() const;

private:
	void printFromBeg() const;
	void printFromEnd() const;
	void mergeArrays(int, int, int, const BookSearchCriteria&);
	void mergeSort(int, int, const BookSearchCriteria&);

private:
	std::vector<Book> allBooks;
};

template<typename T>
void BooksManager::findBookBy(const BookSearchCriteria& criterion, const T& value) const
{
	Book dummy;
	dummy.makeDummy(criterion, value);
	for (int i = 0; i < allBooks.size(); ++i)
	{
		if (!allBooks[i].compare(BookSearchCriteria(criterion), dummy))
		{
			allBooks[i].showAllInfo();
			std::cout << std::endl;
		}
	}
}
#endif
