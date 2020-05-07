#ifndef USERS_MANAGER_HPP
#define USERS_MANAGER_HPP

#include<vector>
#include "User.hpp"

class UsersManager
{
public:
	UsersManager();
	void logIn(const User&);
	void logOut();
	void addUser(const User&);
	void removeUser(const User&);

protected:
	bool checkActiveUser() const;
	bool checkActiveAdmin() const;

private:
	User& findActiveUser();
	void removeUserHelper(const User&);

private:
	std::vector<User> allUsers;
};
#endif
