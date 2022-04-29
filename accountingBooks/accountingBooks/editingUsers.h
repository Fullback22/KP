#pragma once
#include <vector>
#include <iomanip>
#include <stdlib.h>

#include "User.h"
#include "userPassword.h"
#include "drawTable.h"

void creatFirstUser(std::vector<User>& users);
void addUsersByAdministrator(std::vector<User>& users);
void addUsersBySimpleUser(std::vector<User>& users);

User setUserLoginAndPassword(std::vector<User>* const users, std::string const welcomeMessage);
std::string enteryNewUserLogin(std::vector<User>* const users, std::string const welcomeMessage);
std::string enteryNewUserPasswor(std::string const welcomeMessage);
userRole enteryNewUserRole(std::string const welcomeMessage);
bool enteryNewUserAccess(std::string const welcomeMessage, userRole const role);

int findUserIndex(std::vector<User>* const users, std::string const login);
bool loginExists(std::vector<User>* const users, std::string const login);

void updateUserDataByAdministrator(std::vector<User>& users, std::string const activUserLogin);
User setAllUserData(std::vector<User>* const users, std::string const welcomeMessage);
bool updateUserData(std::vector<User>* const users, User& updatedUser, std::string const activUserLogin);

void deleteUserDataByAdministrator(std::vector<User>& users, std::string const activUserLogin);
bool deleteUser(std::vector<User>& const users, size_t const indexDeletedUser, std::string const activUserLogin);

void activationUserByAdministrator(std::vector<User>& users);
void blockUserByAdministrator(std::vector<User>& users, std::string const activUserLogin);

bool confirmationAction(std::string const message);

void printUsers(const std::vector<User> &users);
