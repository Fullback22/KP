#pragma once
#include <iostream>
#include "editingUsers.h"
#include "editingLibrary.h"
#include "procesingLibrary.h"
#include "userPassword.h"
#include "checkFunction.h"

//меню входа в систему
//принимает ссылку на вектор пользователей и ссылку на вектор библиотечных книг
void inputMenu(std::vector<User>& users, std::vector<Book>& booksInLibrary);

//главное меню пользователя
//принимает ссылку на вектор библиотечных книг и активного пользователя
void simpleUserMenu(std::vector<Book>& booksInLibrary, User const activUser);

//главное меню администратора
//принимает ссылку на вектор пользователей, ссылку на вектор библиотечных книг  и активного пользователя
void administratorMenu(std::vector<User>& users, std::vector<Book>& booksInLibrary, User const activUser);

//меню изменения параметров пользователей
//принимает ссылку на вектор пользователей и активного пользователя
void menuEditingUsers(std::vector<User>& users, User const activUser);

//меню изменения параметров библиотечных книг
//принимает ссылку на вектор библиотечных книг
void menuEditingLibrary(std::vector<Book>& booksInLibrary);

//меню обработки библиотечных книг
//принимает ссылку на вектор библиотечных книг
void menuProcessingLibrary(std::vector<Book>& booksInLibrary);

//меню типов сортировки книг
//принимает ссылку на вектор библиотечных книг
void menuSortedBooks(std::vector<Book>& booksInLibrary);

//меню поиска книг
//принимает ссылку на вектор библиотечных книг
void menuSearcBooks(const std::vector<Book>& booksInLibrary);

//проверка на активацию пользователя
//если пользователь активирован функция вернёт true иначе false
bool isActivatedUser(User const user);