#pragma once
#include <vector>
#include <iomanip>
#include <stdlib.h>

#include "User.h"
#include "userPassword.h"
#include "drawTable.h"

//создает первого пользователя(пользователя по умолчанию)
//принимает ссылку на вектор пользователей
void creatFirstUser(std::vector<User>& users);

//функция выполняет запрос на добавлении нового пользователя в базу данных администратором
//принимает ссылку на вектор пользователей
void addUsersByAdministrator(std::vector<User>& users);

//функция выполняет запрос на добавлении нового пользователя в базу данных простым пользователем
//принимает ссылку на вектор пользователей
void addUsersBySimpleUser(std::vector<User>& users);

//функция служит для установки логина и пароля для пользователя
//принимает ссылку на вектор пользователей и сообщение которое должно выводится при вводе данных
//возврощает пользователя с введённым паролем и логином
User setUserLoginAndPassword(const std::vector<User>& users, std::string const welcomeMessage);

//функция служит для ввода логина пользователя
//принимает ссылку на вектор пользователей и сообщение которое должно выводится при вводе данных
//возвращает строку удовлетворяющие требованием к логину
std::string enteryNewUserLogin(const std::vector<User>& users, std::string const welcomeMessage);

//функция служит для ввода пароля пользователя
//принимает сообщение которое должно выводится при вводе данных
//возвращает строку удовлетворяющие требованием к паролю
std::string enteryNewUserPasswor(std::string const welcomeMessage);

//функция служит для ввода прав пользователя(пользователь или администратор)
//принимает сообщение которое должно выводится при вводе данных
//возвращает права пользователя
userRole enteryNewUserRole(std::string const welcomeMessage);

//функция служит для ввода статуса пользователя(активен или заблокирован)
//принимает сообщение которое должно выводится при вводе данных и 
//уровень прав пользователя для которого изменяют статус
//если пользователя активировали функция вернёт true иначе false
bool enteryNewUserAccess(std::string const welcomeMessage, userRole const role);

//вывод индекса под которым хранится пользователь с заданным логином
//на вход принимает ссылку на вектор пользователей и искомый логин
//если пользователь с таким логином найден функция вернёт его индекс иначе -1
int findUserIndex(const std::vector<User>& users, std::string const login);

//проверка на существования пользователя с заданным логином
//на вход принимает ссылку на вектор пользователей и искомый логин
//если пользователь с таким логином найден функция вернёт true иначе false
bool loginExists(const std::vector<User>& users, std::string const login);

//функция выполняет запрос на изменение информации о пользователи администратором
//принимает ссылку на вектор пользователей и логин активного пользователя
void updateUserDataByAdministrator(std::vector<User>& users, std::string const activUserLogin);

//функция служит для ввода всей информации о пользователе
//принимает ссылку на вектор пользователей и сообщение которое должно выводится при вводе данных
//возврощает пользователя с введённой информаицей
User setAllUserData(const std::vector<User>& users, std::string const welcomeMessage);

//функция служит для изменения данных о пользователе в базе данных
//принимает ссылку на вектор пользователей, сыслку на пользователя парметры которого планируется изменить и
//логин активного пользователя
//если обнавление данных прошло успешно функция вернёт true иначе false
bool updateUserData(const std::vector<User>& users, User& updatedUser, std::string const activUserLogin);

//функция выполняет запрос на удаление пользователя администратором
//принимает ссылку на вектор пользователей и логин активного пользователя
void deleteUserDataByAdministrator(std::vector<User>& users, std::string const activUserLogin);

//функция служит для удаления пользователя из базы данных
//принимает ссылку на вектор пользователей, индекс проверяемого пользователя и логин активного пользователя
//если пользователя удалён функция вернёт true иначе false
bool deleteUser(std::vector<User>& const users, size_t const indexDeletedUser, std::string const activUserLogin);

//функция выполняет запрос на активацию пользователя администратором
//принимает ссылку на вектор пользователей
void activationUserByAdministrator(std::vector<User>& users);

//функция выполняет запрос на блокировку пользователя администратором
//принимает ссылку на вектор пользователей и логин активного пользователя
void blockUserByAdministrator(std::vector<User>& users, std::string const activUserLogin);

//вывод данных о всех пользователях
//принимает ссылку на вектор пользователей
void printUsers(const std::vector<User> &users);
