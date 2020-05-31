#include "BooksManager.hpp"

void BooksManager::showAllBooks(const int desc) const
{
	if (desc == 0)
	{
		printFromBeg();
	}
	if (desc == 1)
	{
		printFromEnd();
	}
}

void BooksManager::printFromBeg() const
{
	for (int i = 0; i < allBooks.size(); ++i)
	{
		allBooks[i].showMainInfo();
		std::cout << std::endl;
	}
}

void BooksManager::printFromEnd() const
{
	for (int i = allBooks.size() - 1; i >= 0; --i)
	{
		allBooks[i].showMainInfo();
		std::cout << std::endl;
	}
}

void BooksManager::addBook(const Book& newBook)
{
	allBooks.push_back(newBook);
}

void BooksManager::removeBook(const Book& toBeRemoved)
{
	std::vector<Book>::iterator iterBooks;
	for (iterBooks = allBooks.begin(); iterBooks != allBooks.end(); iterBooks++)
	{
		if (*iterBooks == toBeRemoved)
		{
			allBooks.erase(iterBooks);
			break;
		}
	}
}

void BooksManager::setBooks(const std::vector<Book>& books)
{
	if (!books.empty())
		allBooks = books;
}

void BooksManager::freeBooks()
{
	allBooks.clear();
}

const std::vector<Book>& BooksManager::getBooks() const
{
	return allBooks;
}

void BooksManager::ascendingSortBooks(const BookSearchCriteria& option)
{
	mergeSort(0, allBooks.size() - 1, option);
}

void BooksManager::mergeArrays(int startIndex, int midIndex, int endIndex,
	const BookSearchCriteria& option)
{
	std::vector<Book> arrFirst, arrSecond;
	for (int i = startIndex; i <= midIndex; i++)
	{
		arrFirst.push_back(allBooks[i]);
	}
	for (int i = midIndex + 1; i <= endIndex; i++)
	{
		arrSecond.push_back(allBooks[i]);
	}

	int i = 0, j = 0;
	int pos = startIndex;
	while (i < arrFirst.size() && j < arrSecond.size())
	{
		int compareResult = arrFirst[i].compare(option, arrSecond[j]);
		if (compareResult == -1 || compareResult == 0)
		{
			allBooks[pos++] = arrFirst[i];
			i++;
		}
		else
		{
			allBooks[pos++] = arrSecond[j];
			j++;
		}
	}
	while (i < arrFirst.size())
	{
		allBooks[pos++] = arrFirst[i];
		i++;
	}
	while (j < arrSecond.size())
	{
		allBooks[pos++] = arrSecond[j];
		j++;
	}
}

void BooksManager::mergeSort(int startIndex, int endIndex, const BookSearchCriteria& option)
{
	if (startIndex < endIndex) {
		int mid = (startIndex + endIndex) / 2;

		mergeSort(startIndex, mid, option);
		mergeSort(mid + 1, endIndex, option);

		mergeArrays(startIndex, mid, endIndex, option);
	}
}