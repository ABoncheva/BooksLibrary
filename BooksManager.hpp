#ifndef BOOKS_MANAGER_HPP
#define BOOKS_MANAGER_HPP

#include "Book.hpp"

class BooksManager
{

public:

	void freeBooks();

	std::vector<Book> & getBooks();


protected:

	template<typename T>
	void findBookBy(const BookCompareCriteria &, const T &) const;

	void showAllBooks(const int desc = 0) const;

	void addBook(const Book &);

	void removeBook(const Book &);

	void ascendingSortBooks(const BookCompareCriteria &);


private:

	void printFromBeg() const;

	void printFromEnd() const;

	void mergeArrays(int, int, int, const BookCompareCriteria &);

	void mergeSort(int, int, const BookCompareCriteria &);


private:

	std::vector<Book> allBooks;

};

template<typename T>
void BooksManager::findBookBy(const BookCompareCriteria & criterion , const T & value) const
{
	Book dummy;
	dummy.makeDummy(criterion, value);

	for (int i = 0; i < allBooks.size(); ++i)
	{
		if (!allBooks[i].compare(BookCompareCriteria(criterion), dummy))
		{
			allBooks[i].showAllInfo();
			std::cout << std::endl;
		}
	}
}

#endif
