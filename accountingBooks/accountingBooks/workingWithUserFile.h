#pragma once

#include <fstream>
#include <string>
#include <vector>

#include"editingUsers.h"

//загрузка данных по пользователям из файла в вектор
//принимает имя файла с БД и ссылку на вектор пользователей
void downloadUsersData(std::string const fileName, std::vector<User>& users);

//чтение данных из файла базы данных о пользователях
//принимает файла с БД и ссылку на вектор пользователей
void readUsersDataFromFile(std::ifstream& fileWithData, std::vector<User>& users);

//запись из вектора в файл данных о пользователях
//принимает имя файла с БД и указатель на вектор пользователей
void writeUserDataToFile(std::string const fileName, std::vector<User> const* users);
