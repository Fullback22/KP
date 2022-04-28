// accountingBooks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>



#include "Book.h"
#include "workingWithUserFile.h"
#include "menu.h"
int main()
{
    setlocale(LC_ALL, "Russian");

    std::string const FILE_NAME_WITH_USERS{ "users1.txt" };
    std::vector<User> users{};
    downloadUsersData(FILE_NAME_WITH_USERS, users);
    inputMenu(users);
    //blockUserByAdministrator(users, users[0].login);
    //updateUserDataByAdministrator(users, users[0].login);
    //addUsersBySimpleUser(users);
    //User qwe{ creatNewUser(&users) };
    //printUsers(&users);
    
    //std::string passwordTest{ readPassword() };
    //std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer wi
// ndow to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
