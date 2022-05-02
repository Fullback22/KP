#include "workingWithUserFile.h"

void downloadUsersData(std::string const fileName, std::vector<User>& users)
{
    std::ifstream fileWithUsersData(fileName);//открытие файла
    if (fileWithUsersData.is_open())//если файл открыт
    {
        readUsersDataFromFile(fileWithUsersData, users);//чтение данных из файла
    }
    else
    {
        creatFirstUser(users);//создание первого пользователя
        writeUserDataToFile(fileName, &users);//запись данных первого пользователя в файл
    }
}

void readUsersDataFromFile(std::ifstream& fileWithData, std::vector<User>& users)
{
    size_t userNumber{};//хранение номера пользователя
    size_t stringNumber{};//хранение номера строки
    for (; !fileWithData.eof();) {
        std::string bufer;//буфер для хранения считанной строки
        std::getline(fileWithData, bufer);//чтение строки
        switch (stringNumber) {
        case 0: {
            users.push_back(User{});//добавление новго пользователя
            users[userNumber].login = bufer;//установка логина
            ++stringNumber;//увеличение номера строки на 1
            break;
        }
        case 1: {
            users[userNumber].saltedHashPassword = bufer;//запись хэша пароля
            ++stringNumber;//увеличение номера строки на 1
            break;
        }
        case 2: {
            users[userNumber].salt = bufer;//запись соли
            ++stringNumber;//увеличение номера строки на 1
            break;
        }
        case 3: {
            users[userNumber].role = userRole(atoi(bufer.c_str()));//установка уровня доступа, конвертация из string в int
            ++stringNumber;//увеличение номера строки на 1
            break;
        }
        case 4: {
            users[userNumber].access = atoi(bufer.c_str());//установка статуса активированности, конвертация из string в int
            stringNumber = 0;//обнуление номера строки
            ++userNumber;//увеличение номера пользователя на 1
            break;
        }
        }
    }
}

void writeUserDataToFile(std::string const fileName, std::vector<User> const* users)
{
    std::ofstream outFile(fileName, std::ofstream::out | std::ofstream::trunc);//открытие файла для записи и его очистка
    for (size_t i{ }; i < users->size(); ++i)
    {
        outFile << (*users)[i].login << std::endl;
        outFile << (*users)[i].saltedHashPassword << std::endl;
        outFile << (*users)[i].salt << std::endl;
        outFile << static_cast<int>((*users)[i].role) << std::endl;
        outFile << (*users)[i].access;
        if (i < users->size() - 1)
            outFile << std::endl;//если пользователь не последний перейти на новую строку
    }
}

