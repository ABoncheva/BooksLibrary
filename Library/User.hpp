#ifndef USER_HPP
#define USER_HPP

#include<string>
#include <iostream>

const std::string defaultUsername("admin");
const std::string defaultPassword("i<3c++");

class User
{
public:
	bool empty() const;
	bool isActive() const;
	bool isAdministrator() const;
	bool isDefaultAdmin() const;
	void activateSession();
	void endSession();
	bool operator==(const User&) const;
	User getDefaultAdmin();
	const std::string& getUsername() const;
	friend std::ostream& operator<<(std::ostream&, const User&);
	friend std::istream& operator>>(std::istream&, User&);

private:
	void setDefaultUsername();
	void setDefaultPassword();

private:
	bool loggedIn;
	bool isAdmin;
	std::string username;
	std::string password;
};
#endif
