#pragma once
#include <fstream>
#include <string>
#include <vector>

#include "Book.h"

//проверка на наличие файла с базой данных библиотечных книг
//принимает имя файла с БД
//если файл отрывается корректно функция вернёт true иначе false
bool fileWithLibraryIsOpen(std::string const fileName);

//загрузка данных по библиотечным книга из файла в вектор
//принимает имя файла с БД и ссылку на вектор библиотечных книг
void downloadLibraryData(std::string const fileName, std::vector<Book>& booksInLibrary);

//чтение данных из файла базы данных о библиотечных книгах
//принимает файла с БД и ссылку на вектор библиотечных книг
void readLibraryDataFromFile(std::ifstream& fileWithData, std::vector<Book>& booksInLibrary);

//запись из вектора в файл данных о библиотечных книгах
//принимает имя файла с БД и указатель на вектор библиотечных книг
void writeLibraryDataToFile(std::string const fileName, std::vector<Book> const* booksInLibrary);