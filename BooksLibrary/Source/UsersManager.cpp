#include "UsersManager.hpp"

UsersManager::UsersManager()
{
	User firstAdmin = firstAdmin.getDefaultAdmin();
	allUsers.push_back(firstAdmin);
}

bool UsersManager::checkActiveUser() const
{
	for (int i = 0; i < allUsers.size(); ++i)
	{
		if (allUsers[i].isActive())
			return true;
	}
}

bool UsersManager::checkActiveAdmin() const
{
	for (int i = 0; i < allUsers.size(); ++i)
	{
		if (allUsers[i].isActive() && allUsers[i].isAdministrator())
			return true;
	}
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
	User* toBeLoggedOut = &findActiveUser();
	toBeLoggedOut->endSession();
}


void UsersManager::logIn(const User& user)
{
	for (int i = 0; i < allUsers.size(); ++i)
	{
		if (allUsers[i] == user)
		{
			if (!allUsers[i].isActive())
				allUsers[i].activateSession();
			//else
				// already logged in
		}
		//else
			// not registered
	}
}

void UsersManager::addUser(const User& newUser)
{
	if(checkActiveAdmin())
		allUsers.push_back(newUser);
	// add user to file
}

void UsersManager::removeUser(const User& toBeRemoved)
{
	if(checkActiveAdmin())
		removeUserHelper(toBeRemoved);
	// remove user from file
}

void UsersManager::removeUserHelper(const User& toBeRemoved)
{
	std::vector<User>::iterator iterUsers;
	for (iterUsers = allUsers.begin(); iterUsers != allUsers.end(); ++iterUsers)
	{
		if (*iterUsers == toBeRemoved)
			allUsers.erase(iterUsers);
	}
}