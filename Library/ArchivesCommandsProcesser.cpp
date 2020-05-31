#include "ArchivesCommandsProcesser.hpp"

void ArchivesCommandsProcesser::processLogin()
{
	User user;
	std::cin >> user;
	archivesInSystem->logIn(user);
}

void ArchivesCommandsProcesser::processLogout()
{
	archivesInSystem->logOut();
}

void ArchivesCommandsProcesser::processBooksInfo() const
{
	unsigned id;
	std::cin >> id;
	archivesInSystem->findBookBy(BookSearchCriteria(Id), id);
}

void ArchivesCommandsProcesser::processBooksAll() const
{
	archivesInSystem->showAllBooks();
}

void ArchivesCommandsProcesser::processBooksFind() const
{
	std::string option;
	std::cin >> option;
	std::string optionString;
	std::cin.ignore();
	std::getline(std::cin, optionString);

	if (option == "title")
	{
		archivesInSystem->findBook(BookSearchCriteria(Title), optionString);
	}
	if (option == "author")
	{
		archivesInSystem->findBook(BookSearchCriteria(Author), optionString);
	}
	if (option == "tag")
	{
		archivesInSystem->findBook(BookSearchCriteria(Tag), optionString);
	}
}

void ArchivesCommandsProcesser::processBooksSort()
{
	std::string option;
	std::cin >> option;
	std::string sortOption;
	std::getline(std::cin, sortOption);


	if (option == "title")
		archivesInSystem->ascendingSortBooks(BookSearchCriteria(Title));
	if (option == "author")
		archivesInSystem->ascendingSortBooks(BookSearchCriteria(Author));
	if (option == "year")
		archivesInSystem->ascendingSortBooks(BookSearchCriteria(Year));
	if (option == "rating")
		archivesInSystem->ascendingSortBooks(BookSearchCriteria(Rate));

	if (sortOption.empty() || sortOption == " asc")
		archivesInSystem->showAllBooks();
	else if (sortOption == " desc")
		archivesInSystem->showAllBooks(1);
}
void ArchivesCommandsProcesser::processUsersAdd()
{
	User user;
	std::cin >> user;
	archivesInSystem->addUser(user);
}

void ArchivesCommandsProcesser::processUsersRemove()
{
	User toBeRemoved;
	std::cin >> toBeRemoved;
	archivesInSystem->removeUser(toBeRemoved);
}
void ArchivesCommandsProcesser::processBooksAdd()
{
	Book newBook;
	std::cin >> newBook;
	archivesInSystem->addBook(newBook);
}

void ArchivesCommandsProcesser::processBooksRemove()
{
	Book toBeRemoved;
	toBeRemoved = toBeRemoved.makeDummyBookFromConsole();
	archivesInSystem->removeBook(toBeRemoved);
}

void ArchivesCommandsProcesser::setBooks(const std::vector<Book>& books)
{
	archivesInSystem->setBooks(books);
}

void ArchivesCommandsProcesser::setUsers(const std::vector<User>& users)
{
	archivesInSystem->setUsers(users);
}

void ArchivesCommandsProcesser::deleteBooksFromMemory()
{
	archivesInSystem->freeBooks();
}

const std::vector<Book>& ArchivesCommandsProcesser::getBooks() const
{
	return archivesInSystem->getBooks();
}

const std::vector<User>& ArchivesCommandsProcesser::getUsers() const
{
	return archivesInSystem->getUsers();
}