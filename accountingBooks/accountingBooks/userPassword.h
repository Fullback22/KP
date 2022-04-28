#pragma once
#include <iostream>
#include <string>
#include <random>
#include <conio.h>

#include "hashFunction.h"

std::string createSaltForUser(std::string const userName);
std::string generateSalt(size_t const saltLen);
std::string convertUserPasswordToHash(std::string const passwordWithSalt, std::string const userName);

std::string readPassword();