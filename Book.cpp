#include "Book.hpp"

void Book::setId()
{
	srand(time(NULL));
	id = rand();
}

Book & Book::makeDummyBookFromConsole()
{
	std::cin.ignore();

	std::cout << "Enter title: ";
	std::getline(std::cin, title);

	std::cout << "Enter author: ";
	std::getline(std::cin, author);

	return *this;
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
	writeKeyWords(std::cout);
	std::cout << "Rate: " << rate << std::endl;
}

void Book::writeKeyWords(std::ostream & out) const
{
	out << keyWords.words.size() << " ";

	int i;
	for (i = 0; i < keyWords.words.size() - 1; ++i)
	{
		out << keyWords.words[i] << " ";
	}
	out << keyWords.words[i] << std::endl;
}

int Book::compare(const BookCompareCriteria & criterion, const Book & other) const
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
		std::cout << "Invalid criterion." << std::endl;
	}
}

int Book::compareTitle(const Book & other) const
{
	std::string lowerTitle1 = toLower(title);
	std::string lowerTitle2 = toLower(other.title);

	return lowerTitle1.compare(lowerTitle2);
}

std::string Book::toLower(const std::string & str) const
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

int Book::compareAuthor(const Book & other) const
{
	std::string lowerAuthor1 = toLower(author);
	std::string lowerAuthor2 = toLower(other.author);

	return lowerAuthor1.compare(lowerAuthor2);
}

int Book::findTag(const KeyWords & keyWords) const
{
	for (int i = 0; i < this->keyWords.words.size(); ++i)
	{
		for (int j = 0; j < keyWords.words.size(); ++j)
		{
			std::string lowerKeyWord1 = toLower(this->keyWords.words[i]);
			std::string lowerKeyWord2 = toLower(keyWords.words[j]);
			if (lowerKeyWord1 == lowerKeyWord2)
				return 0;
		}
	}
	return 1;
}

int Book::compareIntegers(const unsigned & lhs, const unsigned & rhs) const
{
	if (lhs < rhs)
		return -1;

	if (lhs == rhs)
		return 0;

	if (lhs > rhs)
		return 1;
}

int Book::compareRate(const double & rate) const
{
	if (this->rate < rate)
		return -1;

	if (this->rate == rate)
		return 0;

	if (this->rate > rate)
		return 1;
}

bool Book::operator==(const Book & other) const
{
	return !(compare(BookCompareCriteria(Author), *this) && compare(BookCompareCriteria(Title), *this));
}


bool Book::empty() const
{
	return title.empty();
}

std::ostream & operator<<(std::ostream & out, const Book & book)
{
	out << book.author << std::endl;
	out << book.title << std::endl;
	out << book.genre << std::endl;
	out << book.description << std::endl;
	out << book.publishedIn << std::endl;
	book.writeKeyWords(out);
	out << book.rate << std::endl;

	return out;
}

std::istream & operator>>(std::istream & in, Book & book)
{
	std::getline(in, book.author);
	std::getline(in, book.title);
	std::getline(in, book.genre);
	std::getline(in, book.description);
	in >> book.publishedIn;
	book.readKeyWords(in);
	in >> book.rate;

	in.ignore();

	return in;
}

void Book::readKeyWords(std::istream & in)
{
	size_t keyWordsNum;
	in >> keyWordsNum;

	for (size_t i = 0; i < keyWordsNum; ++i)
	{
		std::string keyWord;
		in >> keyWord;
		keyWords.words.emplace_back(keyWord);
	}
}
