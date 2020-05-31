#include "CommandsProcesser.hpp"

CommandsProcesser::CommandsProcesser(ArchivesManager& archives ) : FilesCommandsProcesser(),
ArchivesCommandsProcesser(archives)
{
	exctractUsersFromFile();
}

CommandsProcesser::~CommandsProcesser()
{
	saveUsersToFile();
}

void CommandsProcesser::proccessCommand()
{
	expectCommand();
	while (command != "exit")
	{
		if (command == "open")
		{
			extractBooksFromFile();
		}
		if (command == "close")
		{
			deleteBooksFromMemory();
		}
		if (command == "save")
		{
			saveBooksToFile();
		}
		if (command == "saveas")
		{
			saveBooksToNewFile();
		}
		if (command == "help")
		{
			//printCommandsInfo();
		}
		if (command == "login")
		{
			processLogin();
		}
		if (command == "logout")
		{
			processLogout();
		}
		if (command == "books")
		{
			std::cin >> option;
			if (option == "all")
				processBooksAll();
			if (option == "find")
				processBooksFind();
			if (option == "sort")
				processBooksSort();
			if (option == "info")
				processBooksInfo();
			if (option == "add")
				processBooksAdd();
			if (option == "remove")
				processBooksRemove();
		}
		if (command == "users")
		{
			std::cin >> option;
			if (option == "add")
				processUsersAdd();
			if (option == "remove")
				processUsersRemove();
		}
		expectCommand();
	}
	std::cout << "Bye!" << std::endl;
}

void CommandsProcesser::expectCommand()
{
	std::cout << "Enter an action: ";
	std::cin >> command;
}

void CommandsProcesser::extractBooksFromFile()
{
	openBooksFile();
	std::vector<Book> books = deserializeBooksFileAndClose();
	setBooks(books);
}

void CommandsProcesser::exctractUsersFromFile()
{
	openUsersFile();
	std::vector<User> users = deserializeUsersFileAndClose();
	setUsers(users);
}

void CommandsProcesser::deleteBooksFromMemory()
{
	if (!path.empty())
		ArchivesCommandsProcesser::deleteBooksFromMemory();
	else
		std::cout << "There is no file loaded." << std::endl;
}

void CommandsProcesser::saveBooksToFile()
{
	const std::vector<Book>* books = &getBooks();
	serializeBooks(*books);
}

void CommandsProcesser::saveUsersToFile()
{
	const std::vector<User>* users = &getUsers();
	serializeUsers(*users);
}

void CommandsProcesser::saveBooksToNewFile()
{
	const std::vector<Book>* books = &getBooks();
	std::string newFileName;
	std::cin >> newFileName;
	serializeBooks(*books, newFileName);
}