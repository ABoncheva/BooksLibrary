#include "UsersManager.hpp"

UsersManager::UsersManager()
{
	User firstAdmin;
	firstAdmin.getDefaultAdmin();
	allUsers.push_back(firstAdmin);
}

User& UsersManager::findActiveUser()
{
	for (int i = 0; i < allUsers.size(); ++i)
	{
		if (allUsers[i].isActive())
			return allUsers[i];
	}
}

void UsersManager::logOut()
{
	if (activeUser)
	{
		User* toBeLoggedOut = &findActiveUser();
		toBeLoggedOut->endSession();
		activeUser = false;
		if (toBeLoggedOut->isAdministrator())
			activeAdmin = false;
	}
	else
		std::cout << "You are not logged in." << std::endl;
}


void UsersManager::logIn(const User& user)
{
	if (!activeUser)
	{
		bool userRegistered = false;
		for (int i = 0; i < allUsers.size(); ++i)
		{
			if (allUsers[i] == user)
			{
				userRegistered = true;
				if (!allUsers[i].isActive())
				{
					allUsers[i].activateSession();
					activeUser = true;
					if (allUsers[i].isAdministrator())
						activeAdmin = true;
					std::cout << "Welcome, " << user.getUsername() << '!' << std::endl;
				}
				break;
			}
		}
		if (!userRegistered)
			std::cout << "Invalid name or password." << std::endl;
	}
	else
		std::cout << "You are already logged in." << std::endl;
}

void UsersManager::addUser(const User& user)
{
	if (activeAdmin)
		allUsers.push_back(user);
	else
		std::cout << "You need to log in as admin." << std::endl;
}

void UsersManager::removeUser(const User& toBeRemoved)
{
	if (toBeRemoved.isDefaultAdmin())
	{
		std::cout << "You cannot remove the default admin." << std::endl;
		return;
	}
	if (activeAdmin)
		removeUserHelper(toBeRemoved);
	else
		std::cout << "You need to log in as admin." << std::endl;
}

void UsersManager::removeUserHelper(const User& toBeRemoved)
{
	std::vector<User>::iterator iterUsers;
	for (iterUsers = allUsers.begin(); iterUsers != allUsers.end(); iterUsers++)
	{
		if (*iterUsers == toBeRemoved)
		{
			allUsers.erase(iterUsers);
			break;
		}
	}
}

void UsersManager::setUsers(const std::vector<User>& users)
{
	if(!users.empty())
		allUsers = users;
}

const std::vector<User>& UsersManager::getUsers() const
{
	return allUsers;
}