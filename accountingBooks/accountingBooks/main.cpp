// accountingBooks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "forMainFunction.h"
#include "menu.h"

int main()
{
    setRusSettings();
    std::string const FILE_NAME_WITH_LIBRARY_DB{ "libraryDB.txt" };// константа для хранения имени файла с БД библиотечных книг
    std::vector<Book> booksInLibrary{};// объявление вектора для хранения информации библиотечных книг
    std::string const FILE_NAME_WITH_USERS{ "users1.txt" };// константа для хранения имени файла с БД пользователей
    std::vector<User> users{};// объявление вектора для хранения информации пользователей

    if (fileWithLibraryIsOpen(FILE_NAME_WITH_LIBRARY_DB))
    {
        downloadData(FILE_NAME_WITH_LIBRARY_DB, booksInLibrary, FILE_NAME_WITH_USERS, users);
        inputMenu(users, booksInLibrary);
        writeData(FILE_NAME_WITH_LIBRARY_DB, booksInLibrary, FILE_NAME_WITH_USERS, users);
    }
    else
    {
        std::string const dbError{ "Ошибка. Файл с базой данных библиотеки не найден. Программа завершена." };//константа хранящая сообщение об ошибке подключения к БД
        std::cout << dbError << std::endl;
        system("pause");//пауза, предотвращает преждевременное закрытие консоли
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer wi
// ndow to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
