#include "User.hpp"

bool User::operator==(const User& other) const
{
	return this->username == other.username;
}

bool User::isActive() const
{
	return loggedIn;
}

void User::activateSession()
{
	loggedIn = true;
}

void User::endSession()
{
	loggedIn = false;
}

bool User::isAdministrator() const
{
	return isAdmin;
}

User User::getDefaultAdmin() const
{
	return User("admin", "i<3c++", true);
}