#include "CommandsProcesser.hpp"

CommandsProcesser::CommandsProcesser(ArchivesManager& archives) : FilesCommandsProcesser(),
ArchivesCommandsProcesser(archives)
{
	extractUsersFromFile();
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
	finalize();
}

void CommandsProcesser::expectCommand()
{
	std::cout << "Enter an action: ";
	std::cin >> command;
}

void CommandsProcesser::extractBooksFromFile()
{
	try
	{
		openBooksFile();
	}
	catch (int errorCode)
	{
		std::cout << "Books file couldn't be opened. Error code: " << errorCode << std::endl;
		return;
	}
	deserializeBooksFileAndClose(getBooks());
}

void CommandsProcesser::extractUsersFromFile()
{
	try
	{
		openUsersFile();
	}
	catch (int errorCode)
	{
		std::cout << "Users file couldn't be opened. Error code: " << errorCode << std::endl;
		return;
	}
	deserializeUsersFileAndClose(getUsers());
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
	try
	{
		serializeBooks(getBooks());
	}
	catch (int errorCode)
	{
		std::cout << "Books file couldn't be opened. Error code: " << errorCode << std::endl;
		return;
	}
}

void CommandsProcesser::saveBooksToNewFile()
{
	std::string newFileName;
	std::cin >> newFileName;

	try
	{
		serializeBooks(getBooks(), newFileName);
	}
	catch (int errorCode)
	{
		std::cout << "Books file couldn't be opened. Error code: " << errorCode << std::endl;
		return;
	}
}

void CommandsProcesser::saveUsersToFile()
{
	try
	{
		serializeUsers(getUsers());
	}
	catch (int errorCode)
	{
		std::cout << "Users file couldn't be opened. Error code: " << errorCode << std::endl;
		return;
	}
}

void CommandsProcesser::finalize()
{
	saveUsersToFile();
	std::cout << "Bye!" << std::endl;
}