#pragma once
#include <iostream>
#include <string>
#include <random>
#include <conio.h>

#include "checkFunction.h"
#include "editingUsers.h"

//функция авторизации
//принимает ссылку на вектор пользователей и ссылку на нового активного пользователя
//выходными данными является ссылка на нового активного пользователя, содржашая данные автороиированного пользователя
//если авторизация был успешной функция вернёт true иначе false
bool authorization(const std::vector<User>& users, User& newActivUser);

//функция создания «соли» к паролю для пользователя
//принимает логин пользователя
//возвращает строку с "солью" для пользователя
std::string createSaltForUser(std::string const userName);

//функция генерации «соли»
//принимает требуемы размер "соли"
//возвращает строку с "солью"
std::string generateSalt(size_t const saltLen);

//функция перевода пароля с «солью» в хеш
//принимает пароль с "солью" и логин пользователя
//возвращает хеш пароля
std::string convertUserPasswordToHash(std::string const passwordWithSalt, std::string const userName);

//функция для чтения пароля с консоли, заменяет символы на «звёздочки» *
//возвращает строку с паролем
std::string readPassword();

//функция хеширования
//принимает значение которое надо хешировать и номер сида для функции random
//возвращает хеш
std::string hashFunction(std::string const toHash, int const randomSeed);