#include "ArchivesCommandsProcesser.hpp"

void ArchivesCommandsProcesser::processLogin()
{
	std::string username, password;
	std::cin >> username >> password;

	archivesInSystem->logIn(User(username, password));
}

void ArchivesCommandsProcesser::processLogout()
{
	archivesInSystem->logOut();
}

void ArchivesCommandsProcesser::processUsersAdd()
{
	User user;
	std::cin >> user;

	archivesInSystem->addUser(user);
}

void ArchivesCommandsProcesser::processUsersRemove()
{
	std::string username;
	std::cin >> username;

	archivesInSystem->removeUser(User(username));
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
		archivesInSystem->findBook(BookCompareCriteria(Title), optionString);
	}
	if (option == "author")
	{
		archivesInSystem->findBook(BookCompareCriteria(Author), optionString);
	}
	if (option == "tag")
	{
		archivesInSystem->findBook(BookCompareCriteria(Tag), optionString);
	}
}

void ArchivesCommandsProcesser::processBooksSort()
{
	std::string option;
	std::cin >> option;
	std::string sortOption;
	std::getline(std::cin, sortOption);


	if (option == "title")
		archivesInSystem->ascendingSortBooks(BookCompareCriteria(Title));
	if (option == "author")
		archivesInSystem->ascendingSortBooks(BookCompareCriteria(Author));
	if (option == "year")
		archivesInSystem->ascendingSortBooks(BookCompareCriteria(Year));
	if (option == "rating")
		archivesInSystem->ascendingSortBooks(BookCompareCriteria(Rate));

	if (sortOption.empty() || sortOption == " asc")
		archivesInSystem->showAllBooks();
	else if (sortOption == " desc")
		archivesInSystem->showAllBooks(true);
}

void ArchivesCommandsProcesser::processBooksInfo() const
{
	unsigned id;
	std::cin >> id;

	archivesInSystem->findBook(BookCompareCriteria(Id), id);
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

void ArchivesCommandsProcesser::deleteBooksFromMemory()
{
	archivesInSystem->freeBooks();
}

std::vector<Book> & ArchivesCommandsProcesser::getBooks()
{
	return archivesInSystem->getBooks();
}

std::vector<User> & ArchivesCommandsProcesser::getUsers()
{
	return archivesInSystem->getUsers();
}