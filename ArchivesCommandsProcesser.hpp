#ifndef ARCHIVES_COMMANDS_PROCESSER
#define ARCHIVES_COMMANDS_PROCESSER

#include "ArchivesManager.hpp"

class ArchivesCommandsProcesser
{

protected:

	ArchivesCommandsProcesser(ArchivesManager & archives) : archivesInSystem(&archives) {}

	void processLogin();

	void processLogout();

	void processUsersAdd();

	void processUsersRemove();

	void processBooksAll() const;

	void processBooksFind() const;

	void processBooksSort();

	void processBooksInfo() const;

	void processBooksAdd();

	void processBooksRemove();

	void deleteBooksFromMemory();

	std::vector<Book> & getBooks();

	std::vector<User> & getUsers();


private:

	ArchivesManager* archivesInSystem;

};
#endif
