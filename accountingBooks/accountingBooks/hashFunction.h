#pragma once
#include <iostream>
#include <string>
#include <vector>

std::string hashFunction(std::string const toHash, int const randomSeed);
bool checkingCorrectnessInput(std::string const input, std::string const trueAnswer);
bool checkingCorrectnessInputUnsignetInt(std::string const input);
bool checkingCorrectnessInputString(std::string const input);


template <typename T>
T mySum(const std::vector<T> &inputVector)
{
	T outSumm{};
	for (auto element : inputVector)
	{
		outSumm += element;
	}
	return outSumm;
}