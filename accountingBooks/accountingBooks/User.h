#pragma once
#include<iostream>

enum class userRole
{
	SIMPLE_USER,
	ADMINISTRATOR
};

struct User
{
	std::string login{};
	std::string saltedHashPassword{};
	std::string salt{};
	userRole role{ userRole::SIMPLE_USER };
	bool access{ false };
};