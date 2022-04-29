#include "workingWithUserFile.h"

void downloadUsersData(std::string const fileName, std::vector<User>& users)
{
    std::ifstream fileWithUsersData(fileName);
    if (fileWithUsersData.is_open())
    {
        readUsersDataFromFile(fileWithUsersData, users);
    }
    else
    {
        creatFirstUser(users);
        writeUserDataToFile(fileName, &users);
    }
}

void readUsersDataFromFile(std::ifstream& fileWithData, std::vector<User>& users)
{
    size_t userNumber{};
    size_t stringNumber{};
    for (; !fileWithData.eof();) {
        std::string bufer;
        std::getline(fileWithData, bufer);
        switch (stringNumber) {
        case 0: {
            users.push_back(User{});
            users[userNumber].login = bufer;
            ++stringNumber;
            break;
        }
        case 1: {
            users[userNumber].saltedHashPassword = bufer;
            ++stringNumber;
            break;
        }
        case 2: {
            users[userNumber].salt = bufer;
            ++stringNumber;
            break;
        }
        case 3: {
            users[userNumber].role = userRole(atoi(bufer.c_str()));
            ++stringNumber;
            break;
        }
        case 4: {
            users[userNumber].access = atoi(bufer.c_str());
            stringNumber = 0;
            ++userNumber;
            break;
        }
        }
    }
}

void writeUserDataToFile(std::string const fileName, std::vector<User> const* users)
{
    std::ofstream outFile(fileName, std::ofstream::out | std::ofstream::trunc);
    for (size_t i{ }; i < users->size(); ++i)
    {
        outFile << (*users)[i].login << std::endl;
        outFile << (*users)[i].saltedHashPassword << std::endl;
        outFile << (*users)[i].salt << std::endl;
        outFile << static_cast<int>((*users)[i].role) << std::endl;
        outFile << (*users)[i].access;
        if (i < users->size() - 1)
            outFile << std::endl;
    }
}

