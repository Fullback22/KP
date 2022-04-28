#pragma once
#include <iostream>
#include "editingUsers.h"
#include "userPassword.h"
#include "hashFunction.h"

void inputMenu(std::vector<User>& users);
bool authorization(std::vector<User>* const users, User& newActivUser);
void simpleUserMenu(User const activUser);
void administratorMenu(std::vector<User>& users, User const activUser);
bool isActivatedUser(User const user);