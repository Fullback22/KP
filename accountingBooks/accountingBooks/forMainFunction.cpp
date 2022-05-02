#include "forMainFunction.h"

void setRusSettings()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
}

void downloadData(std::string const libraryFileName, std::vector<Book>& books, std::string const usersFileName, std::vector<User>& users)
{
    downloadLibraryData(libraryFileName, books);
    downloadUsersData(usersFileName, users);
}

void writeData(std::string const libraryFileName, const std::vector<Book>& books, std::string const usersFileName, const std::vector<User>& users)
{
    writeUserDataToFile(usersFileName, &users);
    writeLibraryDataToFile(libraryFileName, &books);
}
