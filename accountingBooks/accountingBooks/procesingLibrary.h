#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include "editingLibrary.h"
#include "drawTable.h"
#include "Book.h"

//запрос на поиск книги по автору
//принимает ссылку на вектор книг
void searchQueryByAuthor(const std::vector<Book>& books);

//запрос на поиск книги по году издания
//принимает ссылку на вектор книг
void searchQueryByYearPuolication(const std::vector<Book>& books);

//запрос на поиск книги изданной после заданного года
//принимает ссылку на вектор книг
void searchQueryByYearPuolicationMoreThen(const std::vector<Book>& books);

//запрос на поиск книги по издательству
//принимает ссылку на вектор книг
void searchQueryByPublishingHouse(const std::vector<Book>& books);

//запрос на вывод книг находящихся на выдаче
//принимает ссылку на вектор книг
void searchQueryBooksOnIssue(const std::vector<Book>& books);

//функция поиска книги по автору
//принимает ссылку на вектор книг, искомого автора, ссылку на вектор книг удовлетворяющих запросу
void findBooksByAuthor(const std::vector<Book>& books, std::string const author, std::vector<Book>& outBooks);

//функция поиска книги по году издания
//принимает ссылку на вектор книг, искомый год издания, ссылку на вектор книг удовлетворяющих запросу
void findBooksByYearPuolication(const std::vector<Book>& books, unsigned int const yearPuolication, std::vector<Book>& outBooks);

//функция поиска книги изданной после заданного года
//принимает ссылку на вектор книг, требуемый год издания, ссылку на вектор книг удовлетворяющих запросу
void findBooksByYearPuolicationMoreThen(const std::vector<Book>& books, unsigned int const minYearPuolication, std::vector<Book>& outBooks);

//функция поиска книги по издательству
//принимает ссылку на вектор книг, искомого издательства, ссылку на вектор книг удовлетворяющих запросу
void findBooksByPublishingHouse(const std::vector<Book>& books, std::string const publishingHouse, std::vector<Book>& outBooks);

//функция поиска книг находящихся на выдаче
//принимает ссылку на вектор книг и ссылку на вектор книг удовлетворяющих запросу
void findBooksOnIssue(const std::vector<Book>& books, std::vector<Book>& outBooks);

//сортировка книг по году издания
//принимает ссылку на вектор книг
//возращает входной вектор отсортированный по году издания
void sortBooksByYearPublication(std::vector<Book> &books);

//сортировка книг по автору
//принимает ссылку на вектор книг
//возращает входной вектор отсортированный по автор
void sortBooksByAuthor(std::vector<Book> &books);

//сортировка книг по числу страниц
//принимает ссылку на вектор книг
//возращает входной вектор отсортированный по числу страниц
void sortBooksByQuantityPage(std::vector<Book> &books);

//сортировка по полю года издания
//входные параметры сравниваемые книги
//если год издания первой книги меньше второй функция вернёт true иначе false
bool sortByYearPublication(Book firstBook, Book secondBook);

//сортировка по полю автора
//входные параметры сравниваемые книги
//если автор первой книги в алфавитном порядке находится перед автором второй функция вернёт true иначе false
bool sortByAuthor(Book firstBook, Book secondBook);

//сортировка по полю числа страниц
//входные параметры сравниваемые книги
//если число страниц первой книги меньше второй функция вернёт true иначе false
bool sortByQuantityPage(Book firstBook, Book secondBook);

//вывод данных по всем книгам
//принимает ссылку на вектор книг
void printBooks(const std::vector<Book>& books);



