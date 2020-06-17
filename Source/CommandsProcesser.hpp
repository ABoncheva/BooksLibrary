#ifndef COMMANDS_PROCESSER
#define COMMANDS_PROCESSER

#include "ArchivesCommandsProcesser.hpp"
#include "FilesCommandsProcesser.hpp"

class CommandsProcesser : public FilesCommandsProcesser,public ArchivesCommandsProcesser
{

public:

	CommandsProcesser(ArchivesManager & archives);

	void proccessCommand();


private:

	void expectCommand();

	void extractBooksFromFile();

	void extractUsersFromFile();

	void deleteBooksFromMemory();

	void saveBooksToFile();

	void saveBooksToNewFile();

	void saveUsersToFile();

	void finalize();


private:

	std::string command;

	std::string option;

};

#endif
