#include "stdafx.h"
#include "CppUnitTest.h"

#include "../BooksLibrary/ArchivesCommandsProcesser.hpp"
#include "../BooksLibrary/ArchivesManager.hpp"
#include "../BooksLibrary/Book.hpp"
#include "../BooksLibrary/BooksManager.hpp"
#include "../BooksLibrary/CommandsProcesser.hpp"
#include "../BooksLibrary/FilesCommandsProcesser.hpp"
#include "../BooksLibrary/User.hpp"
#include "../BooksLibrary/UsersManager.hpp"

#include "../BooksLibrary/ArchivesCommandsProcesser.cpp"
#include "../BooksLibrary/ArchivesManager.cpp"
#include "../BooksLibrary/Book.cpp"
#include "../BooksLibrary/BooksManager.cpp"
#include "../BooksLibrary/CommandsProcesser.cpp"
#include "../BooksLibrary/FilesCommandsProcesser.cpp"
#include "../BooksLibrary/User.cpp"
#include "../BooksLibrary/UsersManager.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestBooksLibrary
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestLogIn)
		{
			User testUser("abonchev", "i<3c++");
			UsersManager testUsersManager;
			testUsersManager.logIn(testUser);
			Assert::IsTrue(testUser.isActive());
		}
		TEST_METHOD(TestLogOut)
		{
			User testUser("abonchev", "i<3c++");
			UsersManager testUsersManager;

			testUsersManager.logIn(testUser);
			testUsersManager.logOut();

			Assert::IsFalse(testUser.isActive());
		}
		TEST_METHOD(TestCompareBooks)
		{
			Book lhs, rhs;
			std::string lhsTitle("Harry Potter");
			std::string rhsTitle("harrY pOtteR");

			lhs.makeDummy(Title, lhsTitle);
			rhs.makeDummy(Title, rhsTitle);

			Assert::AreEqual(lhs.compare(Title,rhs), 0);
		}
	};
}