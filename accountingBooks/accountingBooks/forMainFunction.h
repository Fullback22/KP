#pragma 
#include <Windows.h>

#include "workingWithLibraryFile.h"
#include "workingWithUserFile.h"

//устанавливает русскую локализацию для консоли
void setRusSettings();

//функция предназначена для загрузки требуемых файлов в вектора
//функция принимает имя файла с БД библиотечных книг, ссылку на вектор для хранения книг,
//имя файла с БД пользователей, ссылку на вектор для хранения пользователей
void downloadData(std::string const libraryFileName, std::vector<Book>& books, std::string const usersFileName, std::vector<User>& users);

//функция предназначена для загрузки в файлы данных из соответствующих векторов
//функция принимает имя файла в который надо записать данные библиотечных книг, ссылку на вектор с данными книг,
//имя файла в который надо записать данные пользователей, ссылку на вектор с данными пользователей
void writeData(std::string const libraryFileName, const std::vector<Book>& books, std::string const usersFileName, const std::vector<User>& users);
