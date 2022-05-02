#pragma once
#include <iostream>
//перечисление содержашие возможный статус книи
enum class bookStatus
{
    BOOK_IN_LIBRARY, //книга в библиотеки
    BOOK_ON_ISSUE //книга на выдаче
};
//структура хранящая данные о книге
struct Book
{
    unsigned int registrationNumber{}; //регистрационный номер
    std::string author{}; //автор
    std::string name{}; //название книги
    unsigned int yearPuplication{}; //год издания
    std::string publishingHouse{}; //мздательство
    unsigned int quantityPage{}; //число страниц
    unsigned int lastReaderTicketNumber{}; //номер читательского билета последнего читателя
    bookStatus status{}; //статус книги
};