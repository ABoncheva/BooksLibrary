#include "FilesCommandsProcesser.hpp"

void FilesCommandsProcesser::openBooksFile()
{
	std::cin >> path;
	std::ofstream booksInitial(path, std::ios::app);
	booksInitial.close();
	inputBooks.open(path);
}

void FilesCommandsProcesser::openUsersFile()
{
	std::ofstream usersInitial(usersFile, std::ios::app);
	usersInitial.close();
	inputUsers.open(usersFile);
}

std::vector<Book> FilesCommandsProcesser::deserializeBooksFileAndClose()
{
	std::vector<Book> books;
	while (!inputBooks.eof())
	{
		Book toBeAdded;
		inputBooks >> toBeAdded;
		if (!toBeAdded.empty())
			books.push_back(toBeAdded);
	}
	inputBooks.close();
	return books;
}

std::vector<User> FilesCommandsProcesser::deserializeUsersFileAndClose()
{
	std::vector<User> users;
	User toBeAdded;
	while (!inputUsers.eof())
	{
		inputUsers >> toBeAdded;
		if (!toBeAdded.empty())
		{
			if (inputUsers.eof())
				break;
			users.push_back(toBeAdded);
		}
	}
	inputUsers.close();
	return users;
}

void FilesCommandsProcesser::serializeBooks(const std::vector<Book>& books, const std::string& fileName)
{
	if (fileName.empty())
		outputBooks.open(path);
	else
		outputBooks.open(fileName);

	for (int i = 0; i < books.size(); ++i)
	{
		outputBooks << books[i];
	}
	outputBooks.close();
}

void FilesCommandsProcesser::serializeUsers(const std::vector<User>& users)
{
	outputUsers.open(usersFile);
	for (int i = 0; i < users.size(); ++i)
	{
		outputUsers << users[i];
	}
	outputUsers.close();
}