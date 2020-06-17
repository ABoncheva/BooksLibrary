#ifndef USERS_MANAGER_HPP
#define USERS_MANAGER_HPP

#include<vector>
#include "User.hpp"

class UsersManager
{

public:

	UsersManager();

	void logIn(const User &);

	void logOut();

	void addUser(const User &);

	void removeUser(const User &);

	std::vector<User> & getUsers();


protected:

	bool activeUser;

	bool activeAdmin;


private:

	User & findActiveUser();

	void removeUserHelper(const User &);


private:

	std::vector<User> allUsers;

};
#endif
