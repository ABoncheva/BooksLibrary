#include "CommandsProcesser.hpp"

int main()
{
	ArchivesManager archives;
	CommandsProcesser commandsProcesser(archives);
	commandsProcesser.proccessCommand();
	return 0;
}