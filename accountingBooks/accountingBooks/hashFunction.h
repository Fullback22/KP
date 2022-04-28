#pragma once
#include <string>

std::string hashFunction(std::string const toHash, int const randomSeed);
bool checkingCorrectnessInput(std::string const input, std::string const trueAnswer);