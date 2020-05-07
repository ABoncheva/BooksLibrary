#ifndef USER_HPP
#define USER_HPP

#include<string>

class User
{
public:
	User() = default;
	User(const std::string& username, const std::string& password,const bool& isAdmin = false) 
		: username(username),password(password), loggedIn(false), isAdmin(isAdmin) {}
	bool isActive() const;
	bool isAdministrator() const;
	void activateSession();
	void endSession();
	bool operator==(const User&) const;
	User getDefaultAdmin() const;

private:
	bool loggedIn;
	bool isAdmin;
	std::string username;
	std::string password;
};
#endif
