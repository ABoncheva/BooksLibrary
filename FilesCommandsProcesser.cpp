#include "FilesCommandsProcesser.hpp"

void FilesCommandsProcesser::openBooksFile()
{
	std::cin >> path;

	std::ofstream booksInitial(path, std::ios::app);
	if (booksInitial.bad())
		throw 1;

	booksInitial.close();

	input.open(path);
	if (input.bad())
		throw 2;
}

void FilesCommandsProcesser::openUsersFile()
{
	std::ofstream usersInitial(usersFile, std::ios::app);
	if (usersInitial.bad())
		throw 1;

	usersInitial.close();

	input.open(usersFile);
	if (input.bad())
		throw 2;
}

void FilesCommandsProcesser::deserializeBooksFileAndClose(std::vector<Book> & dest)
{
	while (!input.eof())
	{
		Book toBeAdded;
		input >> toBeAdded;
		if (!toBeAdded.empty())
		{
			dest.emplace_back(toBeAdded);
		}
	}

	input.close();
}

void FilesCommandsProcesser::deserializeUsersFileAndClose(std::vector<User> & dest)
{
	User toBeAdded;
	while (!input.eof())
	{
		input >> toBeAdded;
		if (!toBeAdded.empty())
		{
			if (input.eof())
				break;
			dest.emplace_back(toBeAdded);
		}
	}

	input.close();
}

void FilesCommandsProcesser::serializeBooks(const std::vector<Book> & books, const std::string & fileName)
{
	if (fileName.empty())
		output.open(path);
	else
		output.open(fileName);

	if (output.bad())
		throw 1;

	for (int i = 0; i < books.size(); ++i)
	{
		output << books[i];
	}

	output.close();
}

void FilesCommandsProcesser::serializeUsers(const std::vector<User> & users)
{
	output.open(usersFile,std::ios::trunc);

	if (output.bad())
		throw 1;

	for (int i = 0; i < users.size(); ++i)
	{
		output << users[i];
	}

	output.close();
}