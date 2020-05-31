#ifndef COMMANDS_PROCESSER
#define COMMANDS_PROCESSER

#include "ArchivesCommandsProcesser.hpp"
#include "FilesCommandsProcesser.hpp"

class CommandsProcesser : public FilesCommandsProcesser,public ArchivesCommandsProcesser
{
public:
	CommandsProcesser(ArchivesManager& archives);
	~CommandsProcesser();
	void proccessCommand();

private:
	void expectCommand();
	void extractBooksFromFile();
	void exctractUsersFromFile();
	void deleteBooksFromMemory();
	void saveBooksToFile();
	void saveBooksToNewFile();
	void saveUsersToFile();

private:
	std::string command;
	std::string option;
};

#endif
