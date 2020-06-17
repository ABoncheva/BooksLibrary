#include "User.hpp"

User User::getDefaultAdmin()
{
	return User(defaultUsername, defaultPassword, true);
}

bool User::empty() const
{
	return username.empty() && password.empty();
}

bool User::isActive() const
{
	return loggedIn;
}

bool User::isAdministrator() const
{
	return isAdmin;
}

bool User::isDefaultAdmin() const
{
	return username == defaultUsername && password == defaultPassword;
}

bool User::operator==(const User& other) const
{
	return this->username == other.username && this->password == other.password;
}

bool User::compareUsername(const User & other) const
{
	return username == other.username;
}

void User::activateSession()
{
	loggedIn = true;
}

void User::endSession()
{
	loggedIn = false;
}

const std::string & User::getUsername() const
{
	return username;
}

std::ostream & operator<<(std::ostream & out, const User & user)
{
	out << user.username << " " << user.password << " " << user.isAdmin << std::endl;

	return out;
}

std::istream & operator>>(std::istream & in, User & user)
{
	in >> user.username >> user.password >> user.isAdmin;
	user.loggedIn = false;

	return in;
}

