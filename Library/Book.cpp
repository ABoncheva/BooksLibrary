#include "Book.hpp"

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
	std::cout << "ID: " << id << std::endl;
}

void Book::showAllInfo() const
{
	showMainInfo();
	std::cout << "Description: " << description << std::endl;
	std::cout << "Published in: " << publishedIn << std::endl;
	std::cout << "Key words: ";
	showKeyWords();
	std::cout << "Rate: " << rate << std::endl;
}

void Book::showKeyWords() const
{
	int i = 0;
	for (i = 0; i < keyWords.size() - 1; ++i)
	{
		std::cout << keyWords[i] << ", ";
	}
	std::cout << keyWords[i] << std::endl;
}

int Book::compare(const BookSearchCriteria& criterion, const Book& other) const
{
	switch (criterion)
	{
	case Title:
	{
		return compareTitle(other);
	}
	case Author:
	{
		return compareAuthor(other);
	}
	case Tag:
	{
		return findTag(other.keyWords);
	}
	case Year:
	{
		return compareIntegers(this->publishedIn, other.publishedIn);
	}
	case Rate:
	{
		return compareRate(other.rate);
	}
	case Id:
	{
		return compareIntegers(this->id, other.id);
	}
	default:
		std::cout << "Invalid criterion" << std::endl;
	}
}

int Book::compareTitle(const Book& other) const
{
	std::string lowerTitle1 = toLower(title);
	std::string lowerTitle2 = toLower(other.title);
	return lowerTitle1.compare(lowerTitle2);
}

int Book::compareAuthor(const Book& other) const
{
	std::string lowerAuthor1 = toLower(author);
	std::string lowerAuthor2 = toLower(other.author);
	return lowerAuthor1.compare(lowerAuthor2);
}

bool Book::findTag(const std::vector<std::string>& keyWords) const
{
	for (int i = 0; i < this->keyWords.size(); ++i)
	{
		for (int j = 0; j < keyWords.size(); ++j)
		{
			std::string lowerKeyWord1 = toLower(this->keyWords[i]);
			std::string lowerKeyWord2 = toLower(keyWords[j]);
			if (lowerKeyWord1 == lowerKeyWord2)
				return 0; // so that the compare function would work
		}
	}
	return true;
}

int Book::compareIntegers(unsigned lhs, unsigned rhs) const
{
	if (lhs < rhs)
		return -1;
	if (lhs == rhs)
		return 0;
	if (lhs > rhs)
		return 1;
}

int Book::compareRate(double rate) const
{
	if (this->rate < rate)
		return -1;
	if (this->rate == rate)
		return 0;
	if (this->rate > rate)
		return 1;
}

bool Book::operator==(const Book& other) const
{
	return !(compare(BookSearchCriteria(Author), *this) && compare(BookSearchCriteria(Title), *this));
}

std::ostream& operator<<(std::ostream& out, const Book& book)
{
	out << book.author << std::endl;
	out << book.title << std::endl;
	out << book.genre << std::endl;
	out << book.description << std::endl;
	out << book.publishedIn << std::endl;
	out << book.keyWords.size() << " ";
	size_t i;
	for (i = 0; i < book.keyWords.size() - 1; ++i)
	{
		out << book.keyWords[i] << " ";
	}
	out << book.keyWords[i] << std::endl;
	out << book.rate << std::endl;

	return out;
}

bool Book::empty() const
{
	return title.empty();
}

std::istream& operator>>(std::istream& in, Book& book)
{
	std::getline(in, book.author);
	std::getline(in, book.title);
	std::getline(in, book.genre);
	std::getline(in, book.description);
	std::string num;
	std::getline(in, num);
	book.publishedIn = atoi(num.c_str());
	char keyWordsNum;
	in >> keyWordsNum;
	int iKeyWordsNum = keyWordsNum - '0';
	for (int i = 0; i < iKeyWordsNum; ++i)
	{
		std::string keyWord;
		in >> keyWord;
		book.keyWords.push_back(keyWord);
	}
	std::getline(in, num);
	std::getline(in, num);
	book.rate = atof(num.c_str());

	return in;
}

Book& Book::makeDummyBookFromConsole()
{
	std::cin.ignore();
	std::cout << "Enter title: ";
	std::getline(std::cin, title);
	std::cout << "Enter author: ";
	std::getline(std::cin, author);
	return *this;
}

Book& Book::makeDummy(const BookSearchCriteria& criterion, const std::string& value)
{
	switch (criterion)
	{
	case Title:
	{
		this->title = value;
		break;
	}
	case Author:
	{
		this->author = value;
		break;
	}
	case Tag:
	{
		keyWords.push_back(value);
		break;
	}
	default:
		std::cout << "Invalid search criterion" << std::endl;
	}
	return *this;
}

Book& Book::makeDummy(const BookSearchCriteria& criterion, const unsigned& num)
{
	switch (criterion)
	{
	case Id:
	{
		this->id = num;
		break;
	}
	case Year:
	{
		this->publishedIn = num;
		break;
	}
	}
	return *this;
}

std::string Book::toLower(const std::string& str) const
{
	std::string temp;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			temp.push_back(str[i] - ('A' - 'a'));
		else
			temp.push_back(str[i]);
	}
	return temp;
}