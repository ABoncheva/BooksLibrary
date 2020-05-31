#include "User.hpp"

bool User::operator==(const User& other) const
{
	return this->username == other.username && this->password == other.password;
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

User User::getDefaultAdmin()
{
	setDefaultUsername();
	setDefaultPassword();
	isAdmin = true;
	loggedIn = false;
	return *this;
}

void User::setDefaultUsername()
{
	username = defaultUsername;
}

void User::setDefaultPassword()
{
	password = defaultPassword;
}

std::ostream& operator<<(std::ostream& out, const User& user)
{
	out << user.username << " " << user.password << " " << user.isAdmin << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, User& user)
{
	in >> user.username >> user.password >> user.isAdmin;
	user.loggedIn = false;
	return in;
}

bool User::empty() const
{
	return username.empty() && password.empty();
}

bool User::isDefaultAdmin() const
{
	return username == defaultUsername && password == defaultPassword;
}

const std::string& User::getUsername() const
{
	return username;
}