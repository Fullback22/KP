#pragma once

#include <fstream>
#include <string>
#include <vector>

#include"editingUsers.h"

void downloadUsersData(std::string const fileName, std::vector<User>& users);
void readUsersDataFromFile(std::ifstream& fileWithData, std::vector<User>& users);
void writeUserDataToFile(std::string const fileName, std::vector<User> const* users);
