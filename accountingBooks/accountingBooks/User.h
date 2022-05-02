#pragma once
#include<iostream>
//перечеслинеи определяющие права пользователя
enum class userRole
{
	SIMPLE_USER, //простой пользователь
	ADMINISTRATOR //администратор
};
//структура хранящая данные пользователя
struct User
{
	std::string login{}; //логин
	std::string saltedHashPassword{}; //хэш паспорта с "солью"
	std::string salt{}; //"соль"
	userRole role{ userRole::SIMPLE_USER }; //права пользователя
	bool access{ false }; //пользователь активирован(true) или блокирован(false)
};