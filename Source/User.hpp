#ifndef USER_HPP
#define USER_HPP

#include<string>
#include<iostream>

const std::string defaultUsername = "admin";
const std::string defaultPassword = "i<3c++";

class User
{

public:

	User() = default;

	User(const std::string & username, const std::string & password = "", const bool & isAdmin = false,
		const bool & loggedIn = false) : username(username), password(password), isAdmin(isAdmin), loggedIn(loggedIn) {}

	User getDefaultAdmin();

	bool empty() const;

	bool isActive() const;

	bool isAdministrator() const;

	bool isDefaultAdmin() const;

	bool operator==(const User &) const;

	bool compareUsername(const User &) const;

	void activateSession();

	void endSession();

	const std::string & getUsername() const;

	friend std::ostream & operator<<(std::ostream &, const User &);

	friend std::istream & operator>>(std::istream &, User &);


private:

	std::string username;

	std::string password;

	bool loggedIn;

	bool isAdmin;

};

#endif
