#ifndef FILES_COMMANDS_PROCESSER
#define FILES_COMMANDS_PROCESSER

#include <fstream>
#include<vector>
#include "Book.hpp"
#include "User.hpp"

class FilesCommandsProcesser
{
protected:
	void openBooksFile();
	void openUsersFile();
	std::vector<Book> deserializeBooksFileAndClose();
	std::vector<User> deserializeUsersFileAndClose();
	void serializeBooks(const std::vector<Book>&, const std::string& fileName = "");
	void serializeUsers(const std::vector<User>&);

protected:
	std::string path;

private:
	const std::string usersFile = "Users.txt";
	std::ifstream inputBooks;
	std::ofstream outputBooks;
	std::ifstream inputUsers;
	std::ofstream outputUsers;
};
#endif