#ifndef FILES_COMMANDS_PROCESSER
#define FILES_COMMANDS_PROCESSER

#include "Book.hpp"
#include "User.hpp"

class FilesCommandsProcesser
{

protected:

	void openBooksFile();

	void openUsersFile();

	void deserializeBooksFileAndClose(std::vector<Book> &);

	void deserializeUsersFileAndClose(std::vector<User> &);

	void serializeBooks(const std::vector<Book> &, const std::string & fileName = "");

	void serializeUsers(const std::vector<User> &);


protected:

	std::string path;


private:

	const std::string usersFile = "Users.txt";

	std::ifstream input;

	std::ofstream output;

};
#endif