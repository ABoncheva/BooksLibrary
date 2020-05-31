#ifndef ARCHIVES_COMMANDS_PROCESSER
#define ARCHIVES_COMMANDS_PROCESSER

#include "ArchivesManager.hpp"

class ArchivesCommandsProcesser
{
public:
	ArchivesCommandsProcesser(ArchivesManager& archives) : archivesInSystem(&archives) {}

protected:
	void processLogin();
	void processLogout();
	void processBooksAll() const;
	void processBooksFind() const;
	void processBooksSort();
	void processBooksInfo() const;
	void processBooksAdd();
	void processBooksRemove();
	void processUsersAdd();
	void processUsersRemove();
	void setBooks(const std::vector<Book>&);
	void setUsers(const std::vector<User>&);
	void deleteBooksFromMemory();
	const std::vector<Book>& getBooks() const;
	const std::vector<User>& getUsers() const;

private:
	ArchivesManager* archivesInSystem;
};
#endif
