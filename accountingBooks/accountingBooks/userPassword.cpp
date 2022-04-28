#include "userPassword.h"

std::string createSaltForUser(std::string const userName)
{
    return generateSalt(userName.size());
}

std::string generateSalt(size_t const saltLen)
{
    std::random_device rd{};
    std::mt19937 gen{ rd() };
    double minSimvolIndex{ 33.0 };
    double maxSimvolIndex{ 127.0 };
    std::uniform_real_distribution<double> simvolGenerate{ minSimvolIndex, maxSimvolIndex };
    std::string salt{};
    for (size_t i{}; i < saltLen; ++i)
    {
        int newSimvol{ static_cast<int>(round(simvolGenerate(gen))) };
        salt.push_back(newSimvol);
    }
    return salt;
}

std::string convertUserPasswordToHash(std::string const passwordWithSalt, std::string const userName)
{
    size_t randomSeed{ userName.size() + passwordWithSalt.size() };
    return hashFunction(passwordWithSalt, randomSeed);
}

std::string readPassword()
{
    std::string password{};
    for (;;)
    {
        char simvol{ };
        simvol = _getch();
        if (simvol == '\r')
            return password;
        else if (simvol == '\b')
        {
            std::cout << "\b"<<" "<< "\b";
            if(password.size()>0)
                password.pop_back();
        }
        else
        {
            password.push_back(simvol);
            std::cout << "*";
        }
    }
}
