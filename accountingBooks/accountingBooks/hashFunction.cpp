#include "hashFunction.h"

std::string hashFunction(std::string const toHash, int const randomSeed)
{
    srand(randomSeed);
    std::string hash{};
    int sumSimvols{ 0 };
    for (size_t i{}; i < toHash.size(); ++i)
    {
        sumSimvols += toHash[i];
    }
    for (size_t i{}; i < toHash.size(); ++i)
    {
        double denominator{ static_cast<double>(rand()) };
        double firstPartHashElement{ sumSimvols / denominator };
        double secondPartHashElement{ toHash[i] / denominator };
        hash += std::to_string(firstPartHashElement + secondPartHashElement);
    }
    return hash;
}

bool checkingCorrectnessInput(std::string const input, std::string const trueAnswer)
{
    size_t index{ input.find_first_not_of(trueAnswer) };
    if (index == std::string::npos && input.size() == 1)
        return true;
    else
        return false;
}
